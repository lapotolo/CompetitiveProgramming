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

void findKthPair(uint64_t n, uint64_t k, vector<int>& seq){
  uint64_t first_index = (k-1)/n;
  int first = seq[first_index];
  uint64_t l = 0; // number of values smaller than first
  
  while(l !=  first){
    l++;
  }
  l++;
  
  //for(l = 0; l < n; l++)
  //  if(seq[l] == first) break;
  

  cout << "l = " << l << endl;
   
  uint64_t r = count(seq.begin(), seq.end(), first);
  int second = seq[((k-1)-l*n)/r];
  cout << first << " " << second << endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
  uint64_t n, k;
  cin >> n;
  cin >> k;
  
  auto sequence = get_input_sequence<int>(n);

  sort(sequence.begin(), sequence.end());
  findKthPair(n, k, sequence);
  return 0;
}