#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define LEFT(i)     (2 * i + 1)
#define RIGHT(i)    (2 * i + 2)
#define PARENT(i)   ((i - 1) / 2)

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i].val<<" ";}  std::cout<<" : " #a <<"\n";



template <typename NumType>
struct Segment_Tree
{
private:

  struct node {
    NumType val;
    int seg_start, seg_end;
  };
  
  std::vector<node> laztree;
  int num_leaves;
  int tree_size;


  void iterative_build(std::vector<NumType> const& leaves) {
    auto heigth = (int) ceil(log2(num_leaves));
    int left_most_node, offset;
    if (heigth > 0) {
      left_most_node = (int(1) << (heigth-1)) - 1;
      offset = LEFT(left_most_node);
    } else offset = 0;
    
    int i = 0;
    int k = 0;
    for (int j = offset; j != tree_size; ++i, ++j, ++k) {
      segtree[j] = {leaves[k], i, i};
    }
    
    for (int j = 0; i != num_leaves; ++i, ++j, ++k) {
      segtree[num_leaves - 1 + j] = node{leaves[k], i, i};
    }
    
    for (int j = tree_size - 1; j != 0; j -= 2) {
      NumType parent_val = segtree[j].val + segtree[j - 1].val;
      segtree[PARENT(j)] = node{parent_val, segtree[j-1].seg_start, segtree[j].seg_end};
    }
  }

public:
  std::vector<node> segtree;
  
  Segment_Tree(std::vector<NumType> v) : num_leaves(v.size()) {
    tree_size = 2 * num_leaves - 1;
    segtree.resize(tree_size);
    laztree.resize(tree_size);
    iterative_build(v);
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
  std::cin >> n;
  std::vector<int> input(n, 0);

  for (int i = 0; i < n; ++i) { std::cin >> input[i];}

  Segment_Tree<int> test_seg(input);

  printarr(test_seg.segtree, 0);

  std::cout << res << std::endl;
  return 0;
}
