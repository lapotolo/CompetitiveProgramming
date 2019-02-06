#include <iostream>
#include <vector>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

void fill_vector(std::vector<int> & vec, size_t n) {
  int x;
  vec.reserve(n);
  for(size_t i = 0; i < n; ++i){
    std::cin >> x;
    vec.push_back(x);
    }   
}

int solve_01knapsack(std::vector<int> & weights, std::vector<int> & values, int W) { // O(nW)
  std::vector<std::vector<int>> T(values.size()+1, std::vector<int>(W+1, 0));
  for(int j = 0; j <= W; ++j) T[0][j] = 0;
  for (int i = 1; i <= values.size(); ++i) {
    for (int j = 0; j <= W; ++j) {
      if (j < weights[i - 1]) T[i][j] = T[i - 1][j];
      else T[i][j] = std::max(T[i - 1][j],
                              values[i - 1] + T[i - 1][j - weights[i - 1]]);
    } 
  }
  // for(auto & el : T) { printarr(el,0); }
  return T[values.size()][W];
}

int main(){
  std::ios_base::sync_with_stdio(false);

  int num_test, N, W;

  std::vector<int> values;
  std::vector<int> weights;

  std::cin >> num_test;

  while(num_test > 0){
    std::cin >> N;
    std::cin >> W;
    fill_vector(values, N);
    fill_vector(weights, N);
    // printarr(values, 0);
    // printarr(weights, 0);
    std::cout << solve_01knapsack(weights, values, W) << std::endl;
    weights.clear();
    values.clear();
    --num_test;
  }
  return 0;

}
