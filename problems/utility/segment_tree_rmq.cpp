// LAZY SEGMENT TREE
// PROVIDE RMQ QUERIES AND ADD to update nodes
// CIRCULARITY in queries ranges

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define LEFT(i)     (2 * i + 1)
#define RIGHT(i)    (2 * i + 2)
#define PARENT(i)   ((i - 1) / 2)

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";



template <typename NumType>
struct Segment_Tree
{
  struct segment {
    int start, end;
  };

public:
  
  Segment_Tree(std::vector<NumType> v)
    : leaves(v)
  {
    num_leaves = v.size();
    size_t m = size_t(1) << static_cast<size_t>(ceil(log2(num_leaves)));
    tree_size = 2 * m - 1;
    segtree.resize(tree_size, 0);
    laztree.resize(tree_size, 0);
    build(v, 0, num_leaves-1, 0);
    std::cout << "FINISHED BUILD \n";
  }
  
  int64_t circular_rmq(int q_left, int q_right) {
    if(q_left > q_right)
      return std::min(circular_rmq(q_left, num_leaves-1),
                      circular_rmq(0, q_right));
    return rmq(q_left, q_right, root(), 0);
  }  
  
  void circular_add(int q_left, int q_right, int val){
    if (q_left > q_right) {
      add(q_left, num_leaves-1, val, 0);
      add(0, q_right, val, 0);
    }
    else add(q_left, q_right, val, 0);
  }
  
  std::vector<NumType> get_seg() {return *segtree;}
  
private:
  std::vector<NumType> segtree;
  std::vector<NumType> laztree;
  std::vector<NumType> leaves;
  int num_leaves;
  int tree_size;

  void build(std::vector<NumType> const& leaves, int start, int end, int current) {
    if (start > end) return;
    if (start == end) segtree[current] = leaves[start];

    int mid = (start + end) / 2;
    build(leaves, start, mid, LEFT(current));
    build(leaves, mid+1, end, RIGHT(current));
    segtree[current] = std::min(segtree[LEFT(current)],
                                segtree[RIGHT(current)]);
  }

  segment root() { return segment{0, (num_leaves-1)}; }
  
  int64_t rmq(int q_left, int q_right, segment const& node_range, int current) {
    // manage lazy update
    if (laztree[current] != 0) {
      segtree[current] += laztree[current];
      if (node_range.start != node_range.end) {
        laztree[LEFT(current)]  += laztree[current];
        laztree[RIGHT(current)] += laztree[current];
      }
      laztree[current] = 0;
    }
    
    // NO overlap
    if( node_range.start > q_right or node_range.end < q_left) return INT64_MAX;
    // TOTAL overlap
    if( node_range.start >= q_left and node_range.end <= q_right) return segtree[current];

    // partial overlap so need to go deeper via recursive calls to rmq
    int mid = (node_range.start + node_range.end) / 2;
    return std::min(rmq(q_left, q_right, segment{q_left, mid}, LEFT(current)),
                    rmq(q_left, q_right, segment{mid+1, q_right}, RIGHT(current)));
  }
  
  void add(int q_left, int q_right, segment const& node_range, int current, int val){
    // manage lazy update
    if (laztree[current] != 0) {
      segtree[current] += laztree[current];
      if (node_range.start != node_range.end) {
        laztree[LEFT(current)]  += laztree[current];
        laztree[RIGHT(current)] += laztree[current];
      }
      laztree[current] = 0;
    }
    
    // NO overlap
    if( node_range.start > q_right or node_range.end < q_left) return;
    // TOTAL overlap
    if( node_range.start >= q_left and node_range.end <= q_right) {
      segtree[current] += val;
      if (node_range.start != node_range.end) {
        laztree[LEFT(current)]  += val;
        laztree[RIGHT(current)] += val;
      }
    }
    // PARTIAL overlap
    int mid = (node_range.start + node_range.end) / 2;
    add(q_left, q_right, segment{node_range.start, mid}, LEFT(current), val);
    add(q_left, q_right, segment{mid+1, node_range.end}, RIGHT(current), val);
    segtree[current] = std::min(segtree[LEFT(current)],
                                segtree[RIGHT(current)]);
  }
 
};
int main() {
  std::ios_base::sync_with_stdio(false);
  size_t n;

  std::cin >> n;
  std::vector<int> input(n, 0);

  for (int i = 0; i < n; ++i) { std::cin >> input[i];}

  Segment_Tree<int> test_seg(input);


  printdbg(test_seg.circular_rmq(3, 0));
  //test_seg.add(3,0,-1);
  printdbg(test_seg.circular_rmq(0, 1));
  printdbg(test_seg.circular_rmq(2, 1));
  return 0;
}


  // void iterative_build(std::vector<NumType> const& leaves) {
  //   auto heigth = (int) ceil(log2(num_leaves));
  //   int left_most_node, offset;
  //   if (heigth > 0) {
  //     left_most_node = (int(1) << (heigth-1)) - 1;
  //     offset = LEFT(left_most_node);
  //   } else offset = 0;
    
  //   int i = 0;
  //   int k = 0;
  //   for (int j = offset; j != tree_size; ++i, ++j, ++k) {
  //     segtree[j] = {leaves[k], i, i};
  //   }
    
  //   for (int j = 0; i != num_leaves; ++i, ++j, ++k) {
  //     segtree[num_leaves - 1 + j] = node{leaves[k], i, i};
  //   }
    
  //   for (int j = tree_size - 1; j != 0; j -= 2) {
  //     NumType parent_val = std::min<NumType>(segtree[j].val, segtree[j - 1].val);
  //     segtree[PARENT(j)] = node{parent_val, segtree[j-1].seg_start, segtree[j].seg_end};
  //   }
  // }
