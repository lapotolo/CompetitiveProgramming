#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


// source : https://cp-algorithms.com/string/prefix-function.html
void compute_pi(std::string const& s, size_t m, std::vector<size_t> & pi) {
  for (int i = 1; i < m; i++) {
    int j = pi[i-1];
    while (j > 0 && s[i] != s[j]) j = pi[j-1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
  std::stringstream ss;
  size_t N, res;
  std::string A, B;
  std::cin >> N;
  std::cin >> A;
  std::cin >> B;

  ss << A << "$" << B << B;
  std::string S = ss.str();
  std::vector<size_t> pi(S.size());
  
  compute_pi(S, S.size(), pi);
  // printarr(pi, 0);
  
  res = N;
  for(size_t i = N; i < S.size(); ++i) if(pi[i] > pi[res]) res = i;
  
  std::cout << res - pi[res] - N << std::endl;
  return 0;
}