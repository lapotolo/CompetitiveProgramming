// ON SPOJ: 0.14 TIME, 16M MEMORY (CPP14) no optimization set for gcc
// SAME TIME wrt the solution without the BIT

#include <iostream>
#include <vector>
#include <algorithm>

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

void compute(){
  int n, us, l, r, val, qs, q;
  std::cin >> n >> us;
  
  Fenwick_Tree<int64_t> bit(n); // we start from a 0-filled array with n elems
  for(size_t i = 0; i < us; ++i) {
    std::cin >> l >> r >> val;
    bit.add(l,    val);
    bit.add(r+1, -val);
  }
  std::cin >> qs;
  for(size_t i = 0; i < qs; ++i) {
     std::cin >> q;
     std::cout << bit.sum(q) << std::endl;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int test_cases;
  std::cin >> test_cases;
  while(test_cases){
    compute();
    --test_cases;
  }
}
