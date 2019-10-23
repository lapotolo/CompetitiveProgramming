#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<typename T>
vector<T> get_input_sequence(size_t n) {
  vector<T> inputSequence(n);
  for(size_t i = 0; i < n; ++i) 
    cin >> inputSequence[i];
  return inputSequence;
}

void find_kth_pair(uint64_t n, uint64_t k, vector<int> const& seq){
  int first = seq[(k-1)/n];
  uint64_t smaller_count = 0; // number of values smaller than first
  uint64_t equal_count = 0;
  for(size_t i = 0; i < n; ++i) {
    if(seq[i] == first)  ++equal_count;
    else if(seq[i] < first) ++smaller_count;  
  }
  int second = seq[((k-1)-smaller_count*n)/equal_count];
  std::cout << first << " " << second << std::endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
  uint64_t n, k;
  std::cin >> n;
  std::cin >> k;
  
  auto sequence = get_input_sequence<int>(n);
  
  std::sort(sequence.begin(), sequence.end());
  find_kth_pair(n, k, sequence);
  return 0;
}
