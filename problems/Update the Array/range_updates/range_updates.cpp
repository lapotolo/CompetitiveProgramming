/*
  BONUS: range updates and sum supported => Dynamic prefix sum

  We now support range_updates and prefix-sum queries, not only query for single access to the array!
  Moreover update the array problem assumed we first get all the updates and all the access queries
  so we were in a offline model.
  
  range updates are solved using two bits:
    - the first one is used as in the previous problem, ie: add val at position l and add -val at position r+1
        given a query range_update(l, r, v) we do:
          bit1.add(l,    v);
          bit1.add(r+1, -v);
    - the second bit is used to store linear functions to correct the wrong result we would get by computing a prefix sum using only bit1, ie:

    let p be the position we query for SUM
    using only bit1 we woulg get:
    - if 1 <= p < i   : sum(p) = 0    we would want sum(p) = 0 => OK
    - if i <= p <= j  : sum(p) = v*p  we would want sum(p) = v * (p - i - 1) => WRONG, so we need to add to v*p a factor -v*(i-1)
    - if j <  p <= n  : sum(p) = 0    we would want sum(p) = v * (j - i - 1) => WRONG, so we need to add to 0   a factor  v*(j-i-1) + v*(i-1) = v * j 

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>

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
  
  void add(int i, T v) {for (; i <= n; i += (i&(-i))) B[i] += v;}
  
  T sum(int i) {
    T sum = 0;
    for (; i != 0; i -= (i&(-i))) sum += B[i];
    return sum;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  int n, m, q_type, l, r, v, p;
  std::cin >> n >> m;
  Fenwick_Tree<int> bit1(n); // we start from a 0-filled array with n elems
  Fenwick_Tree<int> bit2(n); // this second BIT is used to store corrections
  for(int i = 0; i < m; ++i) {
    std::cin >> q_type;
    if(q_type) { // range update
      std::cin >> l >> r >> v;
      bit1.add(l,    v);
      bit1.add(r+1, -v);
      
      bit2.add(l,  -v*(l-1));
      bit2.add(r+1, v*(r));
    }
    else if(!q_type) {
      std::cin >> p;
      std::cout << (bit1.sum(p) * p) + bit2.sum(p) << std::endl;
    }
  }
}
