#include <iostream>
#include <vector>
#include <algorithm>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

void fill_vector(std::vector<int> & vec, int n) {
  int x;
  vec.reserve(n);
  for(int i = 0; i < n; ++i){
    std::cin >> x;
    vec.push_back(x);
  }
}

// void optimized_lis(std::vector<int> const& v, std::vector<int> & LIS) {
//   std::vector<int> V;
//   for(int a : v) {
//     auto it = std::lower_bound(V.begin(), V.end(), a);
//     LIS.push_back(it - V.begin() + 1);
//     if(it == V.end()) {
//       V.push_back(a);
//     } else {
//       *it = a;
//     }
//   }
// }

 
int binary_search(std::vector<int> const& v, int l, int r, int key) { 
  while (r - l > 1) { 
    int m = l + (r - l) / 2; 
    if (v[m] >= key) r = m; 
    else l = m; 
  } 
  return r; 
} 

void optimized_lis(std::vector<int> const& v, std::vector<int> & LIS) { 
  size_t predecessor_index;
  std::vector<int> tail(v.size(), 0); // tail stores the last elements of the currently active lists 
  LIS.reserve(v.size());
  int length = 1; // always points to the first next empty slot in tail
  tail[0] = v[0]; 
  LIS.push_back(1);
  for (size_t i = 1; i < v.size(); i++) { 
    // v[i] is less than the smaller element seen so far so it becomes the end of the lis of length 1
    if (v[i] < tail[0]) { 
      tail[0] = v[i];
      LIS.push_back(1); 
    }
    // v[i] is the greatest element seen so far, for sure it extends the largest lis so far computed 
    else if (v[i] > tail[length - 1]) { // se l'elemento corrente è maggiore dell'elemento finale della lis massima finora trovata allora estendi la lis
      tail[length] = v[i];
      length++;
      LIS.push_back(length); 
    }
    else {
      predecessor_index = binary_search(tail, -1, length - 1, v[i]);
      tail[predecessor_index] = v[i];
      LIS.push_back(++predecessor_index); // increment since the array is 0 based but for example tail[i] = last element of the current active list with length i+1
    }
    printarr(tail,0);
  } 
  //return length; 
} 


int main() {
  std::ios_base::sync_with_stdio(false);
  
  int test_cases, n;
  std::cin >> test_cases;
  while(test_cases > 0){
    std::cin >> n;
    std::vector<int> input, LIS, LDS;
    fill_vector(input, n);
    
    optimized_lis(input, LIS);     
    std::reverse(input.begin(), input.end());
    optimized_lis(input, LDS);
    
    //std::reverse(LDS.begin(), LDS.end());
    size_t len = LDS.size()-1;
    auto max = LIS[0] + LDS[len];
    int tmp_max = max;
    for (size_t i = 1; i < LIS.size(); ++i) {
      tmp_max = LIS[i] + LDS[len-i];
      if (tmp_max > max) max = tmp_max;
    }
    
    std::cout << --max << std::endl;
    test_cases--;
    input.clear();
    LIS.clear();
    LDS.clear();
    std::vector<int> prova {1,3,4,5,6};
    printele(binary_search(prova, 0, prova.size()-1, 1));
  }
  return 0;
}
