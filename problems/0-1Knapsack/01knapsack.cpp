#include <iostream>
#include <vector>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

int solve_01knapsack(std::vector<int> const& w, std::vector<int> const& v, size_t N, size_t W) { // O(nW)
  std::vector<std::vector<int>> T(N+1, std::vector<int>(W+1, 0));
  for (size_t i = 1; i <= N; ++i) {
    for (size_t j = 0; j <= W; ++j) {
      if (j < w[i - 1]) T[i][j] = T[i - 1][j]; // the new item does not fit the j capacity so the best we can get is the previous best
      else T[i][j] = std::max(T[i - 1][j],     // the new item fits the capacity j so we have to take the max between  
                              v[i - 1] + T[i - 1][j - w[i - 1]]); //  the previous solution and the one we get by taking i-th item and the items that
                                                                  // fit the the spare capacity
    } 
  }
  return T[N][W];
}



int main(){
  std::ios_base::sync_with_stdio(false);

  size_t num_test, N, W, i;
  std::vector<int> values;
  std::vector<int> weights;

  std::cin >> num_test;

  for(size_t t = 0; t < num_test; ++t) {
    std::cin >> N;
    std::cin >> W;

    values.resize(N);
    weights.resize(N);

    for(i = 0; i < N; ++i) std::cin >> values[i];
    for(i = 0; i < N; ++i) std::cin >> weights[i];
    std::cout << solve_01knapsack(weights, values, N, W) << std::endl;
    
    weights.clear();
    values.clear();
  }
  return 0;

}
