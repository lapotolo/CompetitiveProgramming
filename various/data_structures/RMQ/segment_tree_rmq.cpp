#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

#define LEFT(i)     (2 * i + 1)
#define RIGHT(i)    (2 * i + 2)
#define PARENT(i)   ((i - 1) / 2)

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<< a[i] <<" ";}  std::cout<<" : " #a <<"\n";

template <typename NumType>
struct Lazy_Segment_Tree
{
  struct segment {
    int start, end;
  };

public:
  
  Lazy_Segment_Tree(std::vector<NumType> const&v)
    : leaves(v)
  {
    num_leaves = v.size();
    // m is num_leaves rounded up to the next power of two;
    size_t m = size_t(1) << static_cast<size_t>(ceil(log2(num_leaves)));
    tree_size = 2 * m - 1;

    segtree.resize(tree_size, 0);
    laztree.resize(tree_size, 0);

    typedef std::chrono::high_resolution_clock clock_type;
    auto time_start = clock_type::now();
    build(root_segment(), 0);
    auto time_end = clock_type::now();
    std::chrono::duration<double> elapsed = time_end - time_start;
    std::cout << "Rec-building took: " << elapsed.count() << " [sec]" << std::endl;

    time_start = clock_type::now();
    iterative_build();
    time_end = clock_type::now();
    elapsed = time_end-time_start;
    std::cout << "Iter-building took: " << elapsed.count() << " [sec]" << std::endl;
  }
  
  int64_t circular_rmq(int q_left, int q_right) {
    if(q_left > q_right)
      return std::min(circular_rmq(q_left, num_leaves-1),
                      circular_rmq(0, q_right));
    return rmq(q_left, q_right, root_segment(), 0);
  }  
  
  void circular_add(int q_left, int q_right, int64_t val){
    if (q_left > q_right) {
      add(q_left, num_leaves-1, root_segment(), 0, val);
      add(0, q_right, root_segment(), 0, val);
    }
    else add(q_left, q_right, root_segment(), 0, val);
  }
  
  void print_tree(int flag) {
    if(flag){
      for (auto el : segtree) std::cout << el << " ";
      std::cout<<std::endl;
    }
    else{
      for (auto el : segtree_iter) std::cout << el << " ";
      std::cout<<std::endl;
    }
  }
  
private:
  std::vector<NumType> segtree;
  std::vector<NumType> segtree_iter;
  std::vector<NumType> laztree;
  std::vector<NumType> leaves;
  int num_leaves;
  int tree_size;

  void build(segment const& node_segment, int current) {
    int start = node_segment.start;
    int end   = node_segment.end;

    //if (start > end) return;
    
    if (start == end) {
      segtree[current] = leaves[start];
      return;
    }

    int mid = (start + end) / 2;
    build(segment{start, mid}, LEFT(current));
    build(segment{mid+1, end}, RIGHT(current));
    segtree[current] = std::min(segtree[LEFT(current)],
                                segtree[RIGHT(current)]);
  }

  void iterative_build() {
    int iter_tree_size = 2*num_leaves-1;
    segtree_iter.resize(iter_tree_size, 0);
    auto heigth = (int) ceil(log2(num_leaves));
    int left_most_node, offset;
    if (heigth > 0) {
      left_most_node = (int(1) << (heigth-1)) - 1;
      offset = LEFT(left_most_node);
    } else offset = 0;
    int i = 0;
    int k = 0;
    for (int j = offset; j != iter_tree_size; ++i, ++j, ++k) {
      // segtree[j] = {leaves[k], i, i};
      segtree_iter[j] = leaves[k];
    }
    for (int j = 0; i != num_leaves; ++i, ++j, ++k) {
      //segtree[num_leaves - 1 + j] = node{leaves[k], i, i};
      segtree_iter[num_leaves - 1 + j] = leaves[k];
    }
    for (int j = iter_tree_size - 1; j != 0; j -= 2) {
      NumType parent_val = std::min(segtree_iter[j], segtree_iter[j - 1]);
      segtree_iter[PARENT(j)] = parent_val;
      //NumType parent_val = segtree[j].val + segtree[j - 1].val;
      //segtree[PARENT(j)] = node{parent_val, segtree[j-1].seg_start, segtree[j].seg_end};
    }
  }
  
  segment root_segment() { return segment{0, (num_leaves-1)}; }

  void manage_lazy_tree(segment node_range, int current){
    if (laztree[current] != 0) {
      segtree[current] += laztree[current];
      if (node_range.start != node_range.end) {
        laztree[LEFT(current)]  += laztree[current];
        laztree[RIGHT(current)] += laztree[current];
      }
      laztree[current] = 0;
    }
  }
  
  int64_t rmq(int q_left, int q_right, segment const& node_range, int current) {
    manage_lazy_tree(node_range, current);
    
    // NO overlap
    if( node_range.start > q_right || node_range.end < q_left || node_range.start > node_range.end) return INT64_MAX;
    // TOTAL overlap
    if( node_range.start >= q_left && node_range.end <= q_right) return segtree[current];

    // partial overlap so need to go deeper via recursive calls to rmq
    int mid = (node_range.start + node_range.end) / 2;
    return std::min(rmq(q_left, q_right, segment{node_range.start, mid}, LEFT(current)),
                    rmq(q_left, q_right, segment{mid+1, node_range.end}, RIGHT(current)));
  }
  
  void add(int q_left, int q_right, segment const& node_range, int current, int64_t val){
    manage_lazy_tree(node_range, current);

      // NO overlap
    if( node_range.start > q_right || node_range.end < q_left) return;
    // TOTAL overlap
    if( node_range.start >= q_left && node_range.end <= q_right) {
      segtree[current] += val;
      if (node_range.start != node_range.end) {
        laztree[LEFT(current)]  += val;
        laztree[RIGHT(current)] += val;
      }
    } else{
      // PARTIAL overlap
      int mid = (node_range.start + node_range.end) / 2;
      add(q_left, q_right, segment{node_range.start, mid}, LEFT(current), val);
      add(q_left, q_right, segment{mid+1, node_range.end}, RIGHT(current), val);
      segtree[current] = std::min(segtree[LEFT(current)],
                                  segtree[RIGHT(current)]);
    }
  }
};


void to_ranks(std::vector<int> & a, std::vector<int> & tmp){
  std::sort(tmp.begin(), tmp.end());  
  for (int i = 0; i < tmp.size(); i++) a[i] = std::lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  size_t n;
  int64_t res = 0;


  // std::cin >> n;
  // std::vector<int> input(n, 0);
  // for (int i = 0; i < n; ++i) { std::cin >> input[i];}

  std::cin >> n;
  std::vector<int> input(n);  
  auto rand_num_generator = [](int min, int max) -> int
    { return rand() % max + min;};
  for(int i = 0; i < n; ++i){
    auto x = rand_num_generator(1, 1000);
    input.emplace_back(x);
  }

  //  std::vector<int> input {5,3,1,2,0};
  
  Lazy_Segment_Tree<int> segm(input);

  //segm.print_tree(1);
  //segm.print_tree(0);

  std::cout << res << std::endl;
  return 0;
}
