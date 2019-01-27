// ON SPOJ: 0.14 TIME, 16M MEMORY (CPP14)

#include <iostream>
#include <vector>
#include <algorithm>

void compute(){
  int n, us, l, r, val, qs, q;
  std::cin >> n >> us;
  
  std::vector<int64_t> freqs(n+1, 0); // we start from a 0-filled array with n elems
  for(size_t i = 0; i < us; ++i) {
    std::cin >> l >> r >> val;
    freqs[l]   += val;
    freqs[r+1] -= val;
  }

  // computing the prefix-sum
  for(size_t i = 1; i < n; ++i) freqs[i] += freqs[i-1];
 
  std::cin >> qs;
  for(size_t i = 0; i < qs; ++i) {
     std::cin >> q;
     std::cout << freqs[q]<< std::endl;
  }
}

int main(){
  std::ios_base::sync_with_stdio(false);

  int test_cases;
  std::cin >> test_cases;
  while(test_cases){
    compute();
    --test_cases;
  }
}
