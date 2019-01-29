#include <iostream>
#include <vector>
#include <algorithm>
#include <algorithm>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


template <typename T>
class Fenwick_Tree
{
public:
  int n;
  std::vector<T> B;

  Fenwick_Tree(int size) : n(size) { B = std::vector<T>(n+1, 0); }
  
  void add(int i, T v) {for (++i; i <= n; i += (i&(-i))) B[i] += v;}
  
  T sum(int i) {
    T sum = 0;
    for (++i; i != 0; i -= (i&(-i))) sum += B[i];
    return sum;
   }
};

void to_ranks(std::vector<int> & a, std::vector<int> & tmp){
  std::sort(tmp.begin(), tmp.end());  
  for (int i = 0; i < tmp.size(); i++) a[i] = std::lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
}


int main(){
  int n;
  int64_t left_count = 0, right_count = 0, result = 0;
  
  std::cin >> n;
  std::vector<int> input(n);
  Fenwick_Tree<int> L(n);
  Fenwick_Tree<int> R(n);

  for(int i = 0; i < n; ++i){
    std::cin >> input[i];
    R.add(input[i], 1);
  }
  // #elements less than input[i]    is => L.sum(input[i] - 1)
  // #elements greater than input[i] is => R.sum(n - 1) - R.sum(input[i]);
  for(int i = 0; i < n; ++i){
    left_count  = L.sum(input[i]-1);
    right_count = R.sum(n - 1) - R.sum(input[i]);
    result += left_count * right_count;

    L.add(input[i], 1); // Hey, I've seen element input[i]. I need to remember that
                        // note that the update is done after the sum-query
    R.add(input[i],-1); // Removing the occurrence in R of input[i] so that we do not
                        // count it in the sum-query of the next cycle
    }
  std::cout << result << std::endl;
}
