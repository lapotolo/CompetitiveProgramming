#include <iostream>
#include <vector>


int solve_01knapsack(std::vector<int> const& w, std::vector<int> const& v, size_t N, size_t W) { // O(nW)
  int T[N+1][W+1];
  for(size_t i = 0; i <= N; ++i) T[i][0] = 0;
  for(size_t i = 0; i <= W; ++i) T[0][i] = 0;
  
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
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  size_t num_test, N, W, i;
  
  std::vector<int> values, weights;
  
  std::cin >> num_test;
  
  for(size_t t = 0; t < num_test; ++t) {
    std::cin >> N;
    std::cin >> W;
    values.resize(N);
    weights.resize(N);
    
    for(i = 0; i < N; ++i) std::cin >> values[i];
    for(i = 0; i < N; ++i) std::cin >> weights[i];
    std::cout << solve_01knapsack(weights, values, N, W) << '\n';    
  }
  return 0;

}
