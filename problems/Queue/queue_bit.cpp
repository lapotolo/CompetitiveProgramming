#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) /*std::cout<< #a ": ";*/ for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";
#define printarr_pair_first(a, start) /*std::cout<< #a ": ";*/ for(int i = start; i < a.size(); ++i) {std::cout<<a[i].first<<" ";}  std::cout<<" : " #a <<"\n";

#define printarr_pair_sec(a, start) /*std::cout<< #a ": ";*/ for(int i = start; i < a.size(); ++i) {std::cout<<a[i].second<<" ";}  std::cout<<" : " #a <<"\n";


int main() {
  std::ios_base::sync_with_stdio(false);

  int64_t n;
  std::cin >> n;
  std::vector<std::pair<std::string, int> > people(n);
  std::vector<int> heights(0, 0);


  for(size_t i = 0; i < n; ++i) { std::cin >> people[i].first >> people[i].second; };
	
  auto m_cmp = [](std::pair<std::string, int> const& a, std::pair<std::string, int> const& b ) -> bool 
    {
      return a.second < b.second;
    };
  
  std::sort(people.begin(), people.end(), m_cmp); // sort to check if a solution exists
  
  for(size_t i = 0; i < n; i++) if(people[i].second > i) { std::cout << -1 << std::endl; return 0; }
  
  // I need to go back "people[i].second" positions 
  for(size_t i = 0; i < n; ++i) heights.insert( heights.begin() + i - people[i].second, i);
  for(size_t i = 0; i < n; ++i) people[heights[i]].second = i + 1;
  for(size_t i = 0; i < n; ++i) std::cout << people[i].first << " " << people[i].second << std::endl;
  
  return 0;
}
