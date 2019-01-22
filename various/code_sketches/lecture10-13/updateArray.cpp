#include <iostream>
#include <vector>
#include <algorithm>
#include "myBIT.hpp"

using namespace std;

int main() {
  size_t n_tests; 
  cin >> n_tests;
    
  for(size_t i = 0; i < n_tests; ++i) {
    size_t n, u;
    cin >> n;
    cin >> ;u
    BIT<int64_t> F(n+1);
  }
  
  // vector<int> A{3,2,-1,5,7,-3,2,1};
  // vector<int> C(A.size(), 0);

  // std::transform(A.begin(), A.end(), C.begin(),
  //                [](int x) ->  int {return x * x;}
  //                );
  
  // for(auto el : C) std::cout<<el<< " ";
  // std::cout << std::endl;
  
  // BIT<int> bit(A);
  // for(auto el : bit.B) std::cout<<el<< " ";
  // std::cout << std::endl;

  // for(int i = 0; i<A.size(); ++i) std::cout<< bit.sum(i) <<"\n";

  // bit.add(0,10);
  // for(auto el : bit.B) std::cout<<el<< " ";
  // std::cout << std::endl;
}
