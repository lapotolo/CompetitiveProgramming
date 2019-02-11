/* FIX implementation: problems with types
/* http://stackoverflow.com/questions/31106459/how-to-adapt-fenwick-tree-to-answer-range-minimum-queries/34602284#34602284 */

#include <iostream>
#include <vector>
#include <algorithm>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

template<typename NumType>
struct FenwickMin {

  FenwickMin(int64_t nn) : n(nn) {
    original.resize(n+2);
    bottom_up.resize(n+2);
    top_down.resize(n+2);
  }

  FenwickMin(std::vector<NumType> A) : n(A.size()), original(A) {
    bottom_up.resize(A.size()+2);
    top_down.resize(A.size()+2);
    build();
  }

  void update(NumType k, NumType val) {
    NumType replaced = original[k];
    original[k] = val;
    // Update left tree
    NumType x, child, v = val, i = k;
    while (i <= n) {
      if (v > bottom_up[i]) {
        if (replaced == bottom_up[i]) {
          v = std::min(v, original[i]);
          for (NumType r = 1 ;; ++r) {
            x = (unsigned)(i&-i) >> (unsigned)r;
            if (x == 0) break;
            child = i-x;
            v = std::min(v, bottom_up[child]);
          }
        } else break;
      }
      if (v == bottom_up[i]) break;
      bottom_up[i] = v;
      i += (i&-i);
    }
    // Update right tree
    i = k;
    v = val;
    while (i > 0) {
      if (v > top_down[i]) {
        if (replaced == top_down[i]) {
          v = std::min(v, original[i]);
          for (NumType r = 1 ;; ++r) {
            x = (unsigned)(i&-i) >> (unsigned)r;
            if (x == 0) break;
            child = i+x;
            if (child > n+1) break;
            v = std::min(v, top_down[child]);
          }
        } else break;
      }
      if (v == top_down[i]) break;
      top_down[i] = v;
      i -= (i&-i);
  }
}
    
NumType rmq(int a, int b) {
  NumType c_min = original[a];
  NumType prev = a;
  NumType curr = prev + (prev&-prev); // parent right hand side
  while (curr <= b) {
    c_min = std::min<NumType>(c_min, top_down[prev]); // value from the other tree
    prev = curr;
    curr = prev + (prev&-prev);;
  }
  c_min = std::min<NumType>(c_min, original[prev]);
  prev = b;
  curr = prev - (prev&-prev); // parent left hand side
  while (curr >= a) {
    c_min = std::min<NumType>(c_min, bottom_up[prev]); // value from the other tree
    prev = curr;
    curr = prev - (prev&-prev);
    }
    return c_min;
  }  

private:
  int64_t n;
  std::vector<NumType> original;
  std::vector<NumType> bottom_up;
  std::vector<NumType> top_down;

  void build() {
    for(size_t i = 0; i < n; ++i) update(i, original[i]);
  }

};

int main() {
  std::vector<int> A = {1, 0, 2, 1, 1, 3, 0, 4, 2, 5, 2, 2, 3, 1};
  FenwickMin<int> fen(A);
  printarr(A,0);
  printdbg(fen.rmq(3,6)); // gives 0 should return 1
}