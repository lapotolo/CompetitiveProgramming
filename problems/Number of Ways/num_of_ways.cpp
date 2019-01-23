#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);

  int64_t n;
  std::cin >> n;
  std::vector<int64_t> input(n), good_suffixes_counter(n, 0);

  int64_t sum = 0, target_subsum = 0, answer = 0, partial_sum = 0;
  
  for(int i = 0; i < n; ++i) { std::cin >> input[i]; sum += input[i]; }

  if(sum % 3 == 0) {
    target_subsum = sum / 3;
    // handling edge case last element is equal to sum/3
    partial_sum = input[n - 1];
    if(partial_sum == target_subsum) good_suffixes_counter[n-1] = 1;
    for(int64_t i = n - 2; i >= 0; --i) { // fill the counter of good suffixes
      partial_sum += input[i];
      good_suffixes_counter[i] = good_suffixes_counter[i+1] + (partial_sum == target_subsum);
    }

    partial_sum = 0;
    for(int64_t i = 0; i < n - 2; ++i) { // looking for good_prefixes
      partial_sum += input[i];
      if(partial_sum == target_subsum) answer += good_suffixes_counter[i+2];
    }
  }
  std::cout << answer << std::endl;
  return 0;
}
