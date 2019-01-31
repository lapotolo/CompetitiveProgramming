// NOT WORKING

// see notes for lecture 7


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
  
  Segment_Tree(std::vector<NumType> const&v)
    : leaves(v)
  {
    num_leaves = v.size();
    size_t m = size_t(1) << static_cast<size_t>(ceil(log2(num_leaves)));
    tree_size = 2 * m - 1;
    segtree.resize(tree_size, 0);
    build(root_segment(), 0);
  }

  int rmq(int q_left, int q_right) { return rmq(q_left, q_right, root_segment(), 0); }

  
  int rmq(int q_left, int q_right, segment const& node_range, int current) {
    
    if( node_range.start > q_right || node_range.end < q_left || node_range.start > node_range.end) return INT32_MAX;
    if( node_range.start >= q_left && node_range.end <= q_right) return segtree[current];
    int mid = (node_range.start + node_range.end) / 2;
    return std::min(rmq(q_left, q_right, segment{node_range.start, mid}, LEFT(current)),
                    rmq(q_left, q_right, segment{mid+1, node_range.end}, RIGHT(current)));
  }

  int get_tree_size() const { return tree_size; }

  std::vector<NumType> get_leaves() const { return leaves; }

  void print_tree() {
    for (auto el : segtree) std::cout << el << " ";
    std::cout<<std::endl;
  }
  
  
private:
  std::vector<NumType> segtree;
  std::vector<NumType> leaves;
  int num_leaves;
  int tree_size;

  void build(segment const& node_segment, int current) {
    int start = node_segment.start;
    int end   = node_segment.end;
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

};

std::vector<int> build_P(std::vector<int> const& v, int num_col){
  std::vector<int> P (v.size(), 0);
  std::vector<size_t> C(num_col+1, 0);
  for(size_t i = 0; i < v.size(); ++i){
    P[i] = C[v[i]];
    C[v[i]] = i+1;
  }
  return P;
}

void distinct(Segment_Tree<int> seg, std::vector<int> res, int i, int j) {
  int m = seg.rmq(i, j);
  if (seg.get_leaves()[m] <= i){
    res.push_back(m);
    distinct(seg, res, i, m-1);
    distinct(seg, res, m+1, j);
  }
}

  
int main() {
  int num_colors = 3;
  std::vector<int> A {2,1,1,2,2,2,1,3};
  std::vector<int> result;

  std::vector<int> P = build_P(A, num_colors);


  Segment_Tree<int> segtree(P);

  printele(segtree.rmq(0,3));
  distinct(segtree, result, 2, 7);
  for(auto el:result) std::cout << A[el-1] << " ";
  std::cout<<std::endl;
}
