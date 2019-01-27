// 1-based indexing managed internally!

#include <iostream>
#include <vector>

template <typename T>

class fenwick
{
  int N;
  std::vector<T> B;
  
public:
  fenwick(int size) : N(size) { B = std::vector<T>(N+1, 0); }
  
  void add(int i, T v){ for (++i; i <= N; i += (i&(-i))) B[i] += v; }
  
  T sum(int i) {
    T sum = 0;
    for (++i; i > 0; i -= (i&(-i))) sum += B[i];
    return sum;
  }
};
