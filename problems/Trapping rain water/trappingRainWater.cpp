#include <iostream>
#include <vector>

void fill_vector(std::vector<int> & vec, size_t n) {
  int x = 0;
  for(size_t i = 0; i < n; ++i){
    std::cin >> x;
    vec.push_back(x);
  }	
}

int compute_trapped_water(std::vector<int> const& heights){
  int trapped_water = 0;
  int len = heights.size();
  std::vector<int> maxs_to_the_left(len); 
  std::vector<int> maxs_to_the_right(len);
  
  maxs_to_the_left[0] = 0;
  for (size_t i = 1; i < len; ++i){
    maxs_to_the_left[i] = std::max(maxs_to_the_left[i-1], heights[i-1]);             
  }
  
  maxs_to_the_right[len-1] = 0;
  for (int i = len-2; i >= 0; --i){
    maxs_to_the_right[i] = std::max(heights[i+1], maxs_to_the_right[i+1]);            
  }
  
  for (int i = 1; i<len-1; ++i){
    trapped_water += std::max(std::min(maxs_to_the_left[i], maxs_to_the_right[i])-heights[i], 0);
  }
  maxs_to_the_left.clear();
  maxs_to_the_right.clear();
  return trapped_water;
}


int main(){
  std::ios_base::sync_with_stdio(false);

  int test_cases, n, trapped_water;
  std::cin >> test_cases;
  std::vector<std::vector<int>> tests(test_cases);
  
  for (int i = 0; i < test_cases; ++i){
    std::cin >> n;

    tests[i].reserve(n);
    fill_vector(tests[i], n);
  }
  
  for(auto t : tests){
    trapped_water = compute_trapped_water(t);
    std::cout << trapped_water << std::endl;  
  }
  return 0;
}
