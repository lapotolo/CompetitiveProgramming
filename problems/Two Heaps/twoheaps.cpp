#include <vector>
#include <iostream>
#include <map>

#define printele(x) std::cout << x;
#define newline() std::cout << std::endl;
#define printdbg(x) std::cout << #x ": " << x;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

int main() {

	int n;
  std::cin >> n;
  std::vector<size_t> freq(100, 0);
  std::vector<size_t> location(100, -1);
  std::vector<size_t> unique_count(2, 0);  
  std::vector<size_t> stash;

  std::vector<std::vector<size_t> > heaps(2, std::vector<size_t>(n, 0));
  

  std::cout << heaps[0].size() << std::endl;
  std::cout << heaps[1].size() << std::endl; 

  
  size_t x, ind = 0;
  for(size_t i = 0; i < 2*n; ++i) {
    std::cin >> x;
    freq[x]++;
    if(freq[x] == 1) {
      heaps[ind].push_back(x);
      location[x] = ind;
      unique_count[ind]++;
      ind ^= 1;
    }
    else if (freq[x] == 2) {
      ind = 1 ^ location[x];
      heaps[ind].push_back(x);
    }
    else stash.emplace_back(x);
  }
	return 0;
}