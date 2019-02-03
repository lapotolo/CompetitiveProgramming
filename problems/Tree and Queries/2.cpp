#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


template <typename T>
class Fenwick_Tree
{
public:
  int n;
  std::vector<T> B;

  Fenwick_Tree(int size) : n(size) { B = std::vector<T>(n+1, 0); }
  
  void add(int i, T v) {for (++i; i <= n; i += (i&(-i))) B[i] += v;}
  
  T sum(int i) {
    T sum = 0;
    for (++i; i != 0; i -= (i&(-i))) sum += B[i];
    return sum;
   }
};

void to_ranks(std::vector<int> & a, std::vector<int> & tmp){
  std::sort(tmp.begin(), tmp.end());  
  for (int i = 0; i < tmp.size(); i++) a[i] = std::lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
}

struct query {
  int l, r, k, id;
};

struct node{
  size_t index;
  std::vector<size_t> next_idxs;
};

void euler_helper( size_t start
                 , std::vector<std::vector<size_t>> const& tree
                 , std::vector<int> & visited
                 , size_t & i
                 , std::vector<size_t> & euler_tour
                 )
{
	visited[start] = 1; 
	euler_tour[i] = start;
  i++;
	for (auto node : tree[start]) {
		if (!visited[node]) {
			euler_helper( node, tree, visited, i, euler_tour); 
			euler_tour[i] = start;
      i++; 
		}
	} 
}

void build_euler_tour( size_t root
                     , std::vector<std::vector<size_t>> const& tree
                     , std::vector<size_t> & euler_tour
                     )
{
  size_t index = 0;
  std::vector<int> visited(tree.size(), 0);
  euler_helper(root, tree, visited, index, euler_tour);
}

int main(){
  
  std::ios_base::sync_with_stdio(false);

  size_t n, m, l, r, src, dest;
  size_t bucket_size;
  std::cin >> n >> m;
  bucket_size = std::sqrt(n);
  std::vector<size_t> colors(n+1);
  std::vector<std::vector<size_t>> edges(n+1);
  std::vector<size_t> euler_tour(2*n-1);

  std::vector<query> Q(m);

  for (size_t i = 1; i <= n; ++i) std::cin >> colors[i]; // read colors
  for (size_t i = 0; i < n-1; ++i) { // read edges
    std::cin >> src >> dest; // read input
    edges[src].push_back(dest);
    edges[dest].push_back(src);
  }



  build_euler_tour(1, edges, euler_tour);
  printarr(euler_tour,0);

  for(int i = 0; i< euler_tour.size(); ++i) std::cout << colors[euler_tour[i]] << " ";
  std::cout << " : colors"<< std::endl;
  /* READ QUERIES
  for (size_t i = 0; i < m; ++i) { // read queries
    std::cin >> sub_root >> k;
    Q[i] = (query{l, r, i});
  }
  */
  return 0;
}
