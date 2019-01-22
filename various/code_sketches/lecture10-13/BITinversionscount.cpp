#include <iostream>
#include <vector>
#include <algorithm>

#define debugln(x) std::cout << x << std::endl
#define debug(x)   std::cout << x

// BIT OPERATION: returns sum  ([ A[0],..,A[index] ])  where A is the vector the BIT is built on
int sum(std::vector<int> const& BIT, int index) { 
    int sum = 0; // Initialize result 
    while (index > 0) { 
        sum += BIT[index]; 
        index = index - index & (-index); 
    } 
    return sum; 
} 

// BIT OPERATION: update the BIT starting from index and moving following the relation "right siblings or parent right siblings"
void add(std::vector<int> & BIT, int index, int val) {
  while (index <= BIT.size()) { 
    BIT[index] += val;   
    index = index + index & (-index); 
   } 
}

template<typename T>
void printv(std::vector<T> const& v){
  for(auto el : v) std::cout<< el << " ";
  std::cout << std::endl;
}

void to_ranks(std::vector<int> & A) {
  size_t n = A.size();
  std::vector<int> B(A);
  std::sort(B.begin(), B.end()); // sort array B
  for(size_t i = 0; i < n; ++i) {
    int ind = lower_bound(B.begin(), B.end(), A[i]) - B.begin(); // lower_bound takes O(log n) time
    A[i] = ind + 1; // incremented by one so that we can directly use these ranks to index the bit 
  }
}

int main() {

  std::vector<int> A{9,1,0,5,4};
  size_t n = A.size();
  int inversions = 0;
  std::vector<int> bit(n+1, 0);

  to_ranks(A);
  printv(A);
  for(int i = n-1; i >= 0; --i) {
    inversions += sum(bit, A[i]-1); 
    add(bit, A[i], 1);
  }
  std::cout << inversions << std::endl;
}
