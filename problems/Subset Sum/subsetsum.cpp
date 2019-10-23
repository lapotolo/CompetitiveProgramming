#include <iostream>
#include <vector>

void solve_subsetsum(std::vector<int> vec, int halved_sum) {
  int lookback_index;
  bool T[vec.size()+1][halved_sum+1];
  for(int j = 0; j <= halved_sum; ++j) T[0][j] = 0;
  for(int i = 0; i <= vec.size(); ++i) T[i][0] = 1;
  
  for(int i = 1; i <= vec.size(); ++i) {
    for(int j = 1; j <= halved_sum ; ++j) {
      lookback_index = j - vec[i];
      if(vec[i] <= j) T[i][j] = T[i-1][j] or T[i-1][lookback_index];
      else                   // the new number is too big to fit the sum j
        T[i][j] = T[i-1][j]; // then just keep the solution we add not tanking i-th item
    }
  }
  std::cout << (T[vec.size()][halved_sum] ? "YES\n" : "NO\n");
}


int main() {
  std::ios_base::sync_with_stdio(false);
  
  int num_tests, N, x, sum = 0;
  std::cin >> num_tests;
  while(num_tests > 0) {
    std::vector<int> test;
    std::cin >> N;
    test.reserve(N);
    for(int i = 0; i < N; ++i) {
      std::cin >> x;
      test.push_back(x);
      sum += x;
    }
    if(sum % 2 == 1) std::cout << "NO\n";
    else {
      sum /= 2;
      solve_subsetsum(test, sum);
    }
    sum = 0;
    test.clear();
    num_tests--;
  }
  return 0;
}
