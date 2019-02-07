#include <iostream>
#include <vector>
#include <algorithm>


#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";
// KMP source : https://www.ics.uci.edu/~eppstein/161/960227.html

void kmp_preprocess_T(std::string const& s, size_t m) {
  std::vector<int> pi(m, 0);  
  int j = 0;
  int i = 1;
  while(i < m) {
    if( s[i] == s[j]) pi[i++] = ++j;
    else {
      if(j != 0) j = pi[j-1];
      else pi[i++] = 0;
    }
  }
  // printarr(pi,0);
  std::cout << pi[m-1] << std::endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  size_t t;
  std::string s1;
  std::cin >> t;

  while (t > 0) {
    std::cin >> s1;
    kmp_preprocess_T(s1, s1.size());
    --t;
  }
  return 0;
}