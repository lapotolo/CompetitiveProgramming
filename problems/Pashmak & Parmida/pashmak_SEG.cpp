#include <iostream>
#include <vector>
#include <algorithm>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

template <typename OpType, typename NumType>
struct Segment_Tree
{
private:
}

void to_ranks(std::vector<int> & a, std::vector<int> & tmp){
  std::sort(tmp.begin(), tmp.end());  
  for (int i = 0; i < tmp.size(); i++) a[i] = std::lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  size_t n;
  int64_t res = 0;
  std::cin >> n;
  std::vector<int> input(n, 0), tmp(n, 0);

  for (int i = 0; i < n; ++i) { std::cin >> input[i]; tmp[i] = input[i]; }
  to_ranks(input, tmp);

  std::vector<int> suffix_counter(n, 0);
  std::vector<int> counter(n, 0);
  Fenwick_Tree<int> bit(n);
  for(int i = n-1; i >= 0; --i){
    counter[input[i]]++;
    suffix_counter[i] = counter[input[i]]; // suffix_counter[i] == f(i, n, input[i])
    bit.add(counter[input[i]], 1);         // bit[i] = x means that there are x entries in suffix_counter equal to i
  }
  std::fill(counter.begin(), counter.end(), 0);

  for(size_t i = 0; i < n; ++i) {
    counter[input[i]]++;                   // counter stores the prefix occurrences for each input[i]
    bit.add(suffix_counter[i], -1);        // since we want only j > i
    res += bit.sum(counter[input[i]] - 1); // how many times f(j, n, input[j]) < i
  }
  std::cout << res << std::endl;
  return 0;
}
