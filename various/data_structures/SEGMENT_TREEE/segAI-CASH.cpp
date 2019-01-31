// source: https://codeforces.com/blog/entry/18051

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define LEFT(i)     (2 * i + 1)
#define RIGHT(i)    (2 * i + 2)
#define PARENT(i)   ((i - 1) / 2)

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

const int N = 1e5;  // limit for array size
int n=5;  // array size
int t[2 * N];

int main() {
  for (int i = n - 1; i > 0; --i) {

    printdbg(i);
    printdbg(i << 1);
    printdbg((i << 1 | 1));
    t[i] = t[i<<1] + t[i<<1|1];
  }
//   return 0;
  
}
