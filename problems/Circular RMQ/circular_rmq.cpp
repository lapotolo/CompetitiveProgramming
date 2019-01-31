#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>  // used in split function

#define LEFT(i)     (2 * i + 1)
#define RIGHT(i)    (2 * i + 2)
#define PARENT(i)   ((i - 1) / 2)

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";



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
    build(root_segment(), 0);
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
  
  void print_tree() {
    for (auto el : segtree) std::cout << el << " ";
    std::cout<<std::endl;}
  
private:
  std::vector<NumType> segtree;
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


// source: https://www.quora.com/How-do-I-split-a-string-by-space-into-an-array-in-c++
std::vector<std::string> split(std::string str, char delimiter) {
  std::vector<std::string> internal;
  std::stringstream ss(str); // Turn the string into a stream.
  std::string token;
  while(getline(ss, token, delimiter)) {
    internal.push_back(token);
  }
  return internal;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  size_t n, m;

  std::cin >> n;
  std::vector<int64_t> input(n);

  for (int i = 0; i < n; ++i) { std::cin >> input[i];}
  Lazy_Segment_Tree<int64_t> rmq_segtree(input);
  std::cin >> m;

  std::string query;
  for(size_t i = 0; i <= m; ++i){
    std::getline(std::cin, query);
    std::vector<std::string> splitted_query = split(query, ' ');
   
    if(splitted_query.size() == 2) std::cout << rmq_segtree.circular_rmq(std::stoi(splitted_query[0]), std::stoi(splitted_query[1])) << std::endl;
    else if(splitted_query.size() == 3) rmq_segtree.circular_add(std::stoi(splitted_query[0]), std::stoi(splitted_query[1]), std::stoi(splitted_query[2]));
  }
  return 0;
}
 
