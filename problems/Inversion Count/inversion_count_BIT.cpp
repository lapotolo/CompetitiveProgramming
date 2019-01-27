#include <iostream>
#include <vector>
#include <algorithm>

// BIT OPERATION: returns sum  ([ A[0],..,A[index] ])  where A is the vector the BIT is built on
int sum(std::vector<int> const& BIT, int index) { 
    int sum = 0; // Initialize result 
    while (index > 0) {
      //    std::cout << "index before change = " << index << "\n";
      sum += BIT[index]; 
      index -= index & (-index);
      //std::cout << "index after change = " << index << "\n";
    } 
    return sum; 
} 

// BIT OPERATION: update the BIT starting from index and moving following the relation "right siblings or parent right siblings"
void add(std::vector<int> & BIT, int index, int val) {
  while (index <= BIT.size()) { 
    BIT[index] += val;   
    index += index & (-index); 
   } 
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

void solve_inversion_count(){
  long long inversions = 0;

  size_t n;
  std::cin >> n;
  
  std::vector<int> A(n);
  for(int i = 0; i < n; ++i) std::cin >> A[i];

  to_ranks(A); // transforming the input vector in a vector of ranks in the sorted A

  std::vector<int> bit(n+1, 0);

  for(int i = n-1; i >= 0; --i) {
    inversions += sum(bit, A[i]-1);
    add(bit, A[i], 1);
  }
  std::cout << inversions << std::endl;
  A.clear();
  bit.clear();
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int test_cases;
  std::cin >> test_cases;
  for(int i=0; i < test_cases; ++i) solve_inversion_count();
}
