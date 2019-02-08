#include <iostream>
#include <vector>
#include <algorithm>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


struct team {
  size_t member1, member2, strength;
};

void pick_teammates(std::vector<team> const& teams, int n) {
  size_t i = 0, a = 0, b = 0, pair_made = 0;
  std::vector<size_t> pairs(n, 0);
  while (pair_made != n/2) {
    a = teams[i].member1;
    b = teams[i].member2;
    //the output is from 1 to n
    if (!pairs[a] and !pairs[b]) {
      pairs[a] = b + 1;
      pairs[b] = a + 1;
      pair_made++;
    }
    i++;
  }
  for (auto teammate : pairs) std::cout << teammate << " ";
  std::cout << std::endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
  size_t n, strength;
  std::cin >> n;
  
  std::vector<team> teams;
  teams.reserve(n*(n-1)/2); // triangular matrix
  
  for(size_t i = 1; i < 2*n; ++i) {
    for(size_t j = 0; j < i; ++j) {
      std::cin >> strength;
      teams.emplace_back(team{i, j, strength});
    }
  }

  auto strength_cmp = [](team const& a, team const& b) -> bool {
         return a.strength > b.strength;
       };

  std::sort(teams.begin(), teams.end(), strength_cmp);

  pick_teammates(teams, 2*n);
  
  return 0;
}