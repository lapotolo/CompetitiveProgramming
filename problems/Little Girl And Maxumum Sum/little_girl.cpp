#include <iostream>
#include <vector>
#include <algorithm>

#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);

  int64_t n, m, l, r, answer = 0;
  
  std::cin >> n >> m;

  std::vector<int64_t> input(n);
  std::vector<int64_t> frequencies(n+1, 0);
  for(size_t i = 0; i < n; ++i) std::cin >> input[i];
  for(size_t j = 0; j < m; ++j) {
    std::cin >> l >> r;
    frequencies[l-1] += 1; // l-1 and not l because queries are 1-based
    frequencies[r]   -= 1; // r and not r+1 because queries are 1-based
  }

  // computing the prefix-sum
  for(size_t i = 1; i < n; ++i) frequencies[i] += frequencies[i-1];

  sort(input.begin(), input.end());
  sort(frequencies.begin(), frequencies.end()-1);
  for(size_t i = 0; i < n; ++i)
    answer += frequencies[i] * input[i];

  std::cout << answer << std::endl;
}
