#include <iostream>
#include "myBIT.hpp"

using namespace std;

int main() {
    size_t n_tests; 
    cin >> n_tests;
    
    for(size_t i = 0; i < n_tests; ++i) {
      size_t n, u;
      cin >> n;
      cin >> u;
      BIT<int64_t> F(n+1);
      
      int l, r, val;
      for(size_t j = 0; j < u; ++j) {
        cin >> l >> r >> val
        F.add(l, val);
        F.add(r+1, -1*val);
      }
      
      size_t q;
      cin >> q;
      for(size_t j = 0; j < q; ++j) {
        cout << F.sum(l) << endl;         
      }   
    }
    
    return 0;
}