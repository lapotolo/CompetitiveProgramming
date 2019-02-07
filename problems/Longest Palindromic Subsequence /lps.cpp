#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int solve_LPS_naive(std::string & s1, std::string & s2) {
  std::vector<std::vector<int> > T(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));
  for (int i = 1; i <= s1.size(); ++i) {
    for (int j = 1; j <= s2.size(); ++j) {
      if (s1[i-1] == s2[j-1]) T[i][j] = T[i - 1][j - 1] + 1; // [i-1][j-1] inside the if??
      else T[i][j] = std::max(T[i - 1][j], T[i][j - 1]);
    } 
  }
  return T[s1.size()][s2.size()];
}

int lps(std::string const& s) {
  // int T[s.size()][s.size()];
  std::vector<std::vector<int> > T(s.size(), std::vector<int>(s.size()));

  for (size_t i = 0; i < s.size(); ++i) T[i][i] = 1; // fill the diagonal with 1s
  for (size_t i = 1; i < s.size()-1; ++i) T[i][i-1] = 0;

  int k = 1, i = 0, j = 1;
  while (k < s.size()) {
    (s[i] != s[j]) 
                  ? T[i][j] = std::max(T[i+1][j], T[i][j-1]) 
                  : T[i][j] = T[i+1][j-1] + 2;
    i++;
    j++;   
    if (j == s.size()) {
      k++;
      j = k;
      i = 0;
    }
  }
  return T[0][s.size()-1];
}

int main() {
  std::ios_base::sync_with_stdio(false);

  size_t num_test, len1, len2;

  std::string s1;
  std::string s1_rev;
  

  std::cin >> num_test;

  while(num_test != 0){
    std::cin >> s1;
    s1_rev = s1;
    std::reverse(s1_rev.begin(), s1_rev.end());
    std::cout << solve_LPS_naive(s1, s1_rev) << std::endl;

    s1.clear();
    num_test--;
  }
}