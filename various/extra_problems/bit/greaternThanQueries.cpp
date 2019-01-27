/*

PROBLEM:
Given an array with n elements, how to find the number of elements greater than or equal to a given value (x) in the given range index i to index j in O(log n) complexity?

The queries are of the form (i, j, x) which means find number of elements greater than x from the ith till jth element in the array

The array is not sorted. i, j & x are different for different queries. Elements of the array are static. Edit: i, j, x all can be different for different queries
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) /*std::cout<< #a ": ";*/ for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


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

template<typename T> 
void remap(std::vector<T>& a, std::vector<T>& tmp) {
  std::sort(tmp.begin(), tmp.end());
  size_t sz = std::distance(tmp.begin(), std::unique(tmp.begin(), tmp.end()));
  tmp.resize(sz);
  for(auto &x : a) x = distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), x));
}

struct range
{
  int left, right, val;
  range(int l, int r, int v) : left(l), right(r), val(v) {}
};
  
int main() {
  int n,m, l, r, x;
  std::cin >> n >> m;
  
  std::vector<int> input(n + m);
  Fenwick_Tree<int> bit(n + m);
  
  for(auto it = input.begin(); it != input.end(); ++it) {
    std::cin >> x;
    input.push_back(x);
  }
  std::vector<range> queries(n + m);
  for(int i = 0; i < m; ++i) {
    std::cin >> l >> r >> x;
    queries.push_back(range(l, r, x));
    input.push_back(x);
  }
  remap(input, tmp);
  }
