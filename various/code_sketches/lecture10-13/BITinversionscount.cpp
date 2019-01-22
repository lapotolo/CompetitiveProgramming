#include <iostream>
#include <vector>
#include <algorithm>

#include "myBIT.hpp"

int getSum(std::vector<int> BIT, int index) { 
    int sum = 0; // Initialize result 
    while (index > 0) { 
        sum += BIT[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
void updateBIT(std::vector<int> BIT, int index, int val) { 
  // Traverse all ancestors and add 'val' 
  size_t n = BIT.size() - 1;
  while (index <= n) { 
    BIT[index] += val;   
    index += index & (-index); 
   } 
}

template<typename T>
void printv(std::vector<T> const& v){
  for(auto el : v) std::cout<< el << " ";
  std::cout << std::endl;
}

std::vector<int> get_vector_of_ranks(std::vector<int> const& A, std::vector<int> & ranks) {
  size_t n = A.size();
  std::vector<int> B(A);
  std::sort(B.begin(), B.end()); // sort array B
  for(size_t i = 0; i < n; ++i) {
    int ind = lower_bound(B.begin(), B.end(), A[i]) - B.begin(); // lower_bound takes O(log n) time
    ranks[i] = ind + 1;
  }
  return ranks;
}

int main() {
  std::vector<int> A{9,1,0,5,4};
  std::vector<int> ranks(A.size());

  
  BIT<int> bit(A.size());
  printv(bit.B);
  
  // std::vector<int> bit(A.size()+1);
  
  ranks = get_vector_of_ranks(A, ranks);
  printv(ranks);
  
  int inversions = 0;
  for(size_t i = 0; i < A.size(); ++i) {
    bit.add(ranks[i], 1);
    inversions += i - bit.sum(ranks[i]);
    
    printv(bit.B);
    
    //inversions += getSum(bit, A[i]-1); 
    //updateBIT(bit, A[i], 1); 
  }
  std::cout << inversions << std::endl;
}
