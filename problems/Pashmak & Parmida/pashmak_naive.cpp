#include <iostream>
#include <vector>
#include <algorithm>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) /*std::cout<< #a ": ";*/ for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


template<typename T> 
void remap(std::vector<T>& a) {
  std::vector<T> tmp(a.size());
  std::copy(a.begin(), a.end(), tmp.begin());
  std::sort(tmp.begin(), tmp.end());
  size_t sz = std::distance(tmp.begin(), std::unique(tmp.begin(), tmp.end()));
  tmp.resize(sz);
  for(auto &x : a)
    x = distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), x));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  size_t n;
  int64_t res = 0;

  std::cin >> n;

  std::vector<int> input(n, 0);

  for (int i = 0; i < n; ++i) std::cin >> input[i];

  remap(input);

  std::vector<int> prefix_counter(n, 0);  
  std::vector<int> suffix_counter(n, 0);
  std::vector<int> counter(n, 0);

  std::fill(counter.begin(), counter.end(), 0);

  for(int i = 0; i < n; ++i) {
    counter[input[i]]++;
    prefix_counter[i] = counter[input[i]];
  }
  std::fill(counter.begin(), counter.end(), 0);
  
  for(int i = n-1; i>=0; --i){
    counter[input[i]]++;
    suffix_counter[i] = counter[input[i]];
   }
  // printarr(input);
  // printarr(prefix_counter);
  // printarr(suffix_counter);

  
  for(int i = 0; i < n; ++i)
    for(int j =i+1; j < n; ++j)
      if(prefix_counter[i] > suffix_counter[j]) res++;
  
  std::cout << res << std::endl;
  return 0;
}
