#include <deque>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

#define LEFT(i)  2 * i + 1
#define RIGHT(i) 2 * i + 2
#define PARENT(i) (i -1) / 2

struct node {
  node (int k, node* l = nullptr, node* r = nullptr)
    : key(k), left(l), right(r)
  {}

  int key;
  node* left;
  node* right;
};

// rmw binary tree left complete
node* build_rmq_tree_pointers(std::vector<int> const& v) {
  node* root = nullptr;
  std::deque<node*> q;
  int n = v.size();

  for (int i=0; i < n; ++i){
    node* n = new node(v[i]);
    q.push_back(n);
  }

  node* last = nullptr;
  if (n % 2) {
    last = q.back();
    q.pop_back();
  }

  auto min_parent = [&](node* left, node* right) {
    int min = std::min<int>(left->key, right->key);
    node* parent = new node{min, left, right};
    return parent;
    //q.push_back(parent);
  };

  node* tmp_parent = nullptr;
  while (q.size() != 1) {
    tmp_parent = min_parent(q[0], q[1]);
    q.pop_front();
    q.pop_front();
    q.push_back(tmp_parent);
  }
  
  if (last != nullptr) { // so if n is even
    min_parent(q.front(), last);
    q.pop_front();
  }
  root = q.front();
  return root;
}

std::vector<int> build_rmq_tree_arrays() {
  std::vector<int> tree;
  int n, x;
  std::cin >> n;
  int tree_size = 2 * n - 1;
  tree.resize(tree_size);
  printarr(tree, 0);
  int h = ceil(log2(n));
  int left_most_node = (int(1) << (h - 1)) - 1;
  int offset = LEFT(left_most_node);

  // setting leaves circularly
  int i = 0;
  //for( int k =)

  // the two following for-loops set the leaves circularly.
  // j is used to index position in the tree, i to count how many leaves we have already put in the tree
  // ie: in the first for we start from j=offset and we go forward untill we
  //     reach the end of the tree array
  for (int j = offset; j != tree_size; ++i, ++j) {        
    std::cin >> x;
    tree[j] = x;
  }
  // fall back
  for (int j = 0; i != n; ++i, ++j) {
    std::cin >> x;
    tree[n-1+j] = x;
  }

  // internal nodes
  // note that the step is -=2 since we use a binary function to find the minimum
  for (int i = tree_size-1; i != 0; i-=2) {
    int min = std::min<int>(tree[i], tree[i-1]);
    tree[PARENT(i)] = min;
  }
  return tree;
}

int main() {
  std::vector<int> v {1,2,3,4,5};
  build_rmq_tree_pointers(v);
  std::vector<int> treetest = build_rmq_tree_arrays();
  printarr(treetest, 0);
}

