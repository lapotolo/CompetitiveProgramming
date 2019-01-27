#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for iota

void to_ranks(std::vector<int> & A) {
  size_t n = A.size();
  std::vector<int> B(A);
  std::sort(B.begin(), B.end()); // sort array B
  for(size_t i = 0; i < n; ++i) {
    int ind = lower_bound(B.begin(), B.end(), A[i]) - B.begin(); // lower_bound takes O(log n) time
    A[i] = ind + 1; // incremented by one so that we can directly use these ranks to index the bit 
  }
}

template <typename T>
void to_ranks(std::vector<T> & a, size_t n){
  std::vector<T> tmp(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
    tmp[i] = a[i];
  }
  sort(tmp, tmp + n);
  for (size_t i = 0; i < n; i++) a[i] = lower_bound(tmp, tmp + n, a[i]) - tmp;
}

void to_ranks(std::vector<int> & a, int n){
  std::vector<int> tmp(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    tmp[i] = a[i];
  }
  sort(tmp.begin(), tmp.end());
  
  for (int i = 0; i < n; i++) a[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
}


template<typename T>
void remap(std::vector<T> & a) {
  std::vector<T> tmp(a.size());
  std::copy(a.begin(), a.end(), tmp.begin());
  std::sort(tmp.begin(), tmp.end());
  size_t sz = std::distance(tmp.begin(), std::unique(tmp.begin(), tmp.end()));
  tmp.resize(sz);
  for(auto &x : a)
    x = distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), x));
}


template <typename T>
std::vector<size_t> sort_indexes(const std::vector<T> &v) {

  // initialize original index locations
  std::vector<size_t> idx(v.size());
  std::iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}


int main() {

    std::vector<int> x = {15, 3, 0, 20};

    std::vector<int> y;

    std::vector<int> y(x.size());
    std::size_t n(0);
    std::generate(std::begin(y), std::end(y), [&]{ return n++; });

    std::sort(  std::begin(y), 
                std::end(y),
                [&](int i1, int i2) { return x[i1] < x[i2]; } );

    for (auto v : y)
        std::cout << v << ' ';

    return 0;
}
