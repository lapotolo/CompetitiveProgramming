#include <iostream>
#include <vector>
#include <string>

int solve_LCS(std::string & s1, std::string & s2) {
  std::vector<std::vector<int> > T(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));

  for (int i = 1; i <= s1.size(); ++i) {
    for (int j = 1; j <= s2.size(); ++j) {
      if (s1[i-1] == s2[j-1]) T[i][j] = T[i - 1][j - 1] + 1; // [i-1][j-1] inside the if??
      else T[i][j] = std::max(T[i - 1][j], T[i][j - 1]);
    } 
  }
  return T[s1.size()][s2.size()];
}

int main() {
  std::ios_base::sync_with_stdio(false);

  size_t num_test, len1, len2;

  std::string s1;
  std::string s2;

  std::cin >> num_test;

  while(num_test != 0){
    std::cin >> len1 >> len2;
    std::cin >> s1;
    std::cin >> s2;

    std::cout << solve_LCS(s1, s2) << std::endl;

    s1.clear();
    s2.clear();
    num_test--;
  }
}