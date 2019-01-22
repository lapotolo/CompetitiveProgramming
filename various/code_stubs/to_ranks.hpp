#include <iostream>
#include <vector>
#include <algorithm>

void to_ranks(std::vector<int> & A) {
  size_t n = A.size();
  std::vector<int> B(A);
  std::sort(B.begin(), B.end()); // sort array B
  for(size_t i = 0; i < n; ++i) {
    int ind = lower_bound(B.begin(), B.end(), A[i]) - B.begin(); // lower_bound takes O(log n) time
    A[i] = ind + 1; // incremented by one so that we can directly use these ranks to index the bit 
  }
}
