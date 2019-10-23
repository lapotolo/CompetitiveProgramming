#include <iostream>
#include <vector>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

void fill_vector(std::vector<int> & vec, int n) {
  int x;
  vec.reserve(n);
  for(int i = 0; i < n; ++i){
    std::cin >> x;
    vec.push_back(x);
  }
}


int solve_lis(std::vector<int> const& v) { // quadratic solution
  int best_lis_in_prefix, min_seen = v[0], best_lis = 1;
  std::vector<int> LIS;
  LIS.reserve(v.size());
  LIS.push_back(1);
  for(int i = 1; i < v.size(); ++i) {
    // printdbg(i);
    // printarr(LIS, 0);
    if(v[i] <= min_seen) {
      LIS.push_back(1);
      min_seen = v[i];
    } else { // current elements greater then the minimum encountered so far
      best_lis_in_prefix = 0;
      for(int j = 0; j < i ; ++j) { // check in the current prefix [0..i) for elements v[j] smaller then v[i]
        if(v[j] < v[i] and best_lis_in_prefix < LIS[j]) {
          best_lis_in_prefix = LIS[j];    
        }
      }
      LIS.push_back(best_lis_in_prefix+1);
      
      if((best_lis_in_prefix+1) > best_lis)
        best_lis = best_lis_in_prefix+1;
    }
  }
  return best_lis;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int test_cases, n;
  std::cin >> test_cases;
  while(test_cases > 0){
    std::vector<int> input;
    std::cin >> n;
    fill_vector(input, n);
    if (n > 0) std::cout << solve_lis(input) << std::endl;
    else std::cout << 0 << std::endl;
    input.clear();
    test_cases--;
  }
  return 0;
}
