#include <iostream>
#include <string>
#include <vector>

int main(){
  int number_of_queries, l, r;
  std::string input_string;
  std::cin >> input_string;
  
  size_t n = input_string.length();
  std::vector<int> prefix_sum(n+1);
  
  prefix_sum[0] = 0;
  // building the prefix sum array based on input string
  for (int i = 1; i < n; ++i){
    if (input_string[i] == input_string[i-1]){
      prefix_sum[i] = prefix_sum[i-1] + 1;
    } else {
      prefix_sum[i] = prefix_sum[i-1];
    }
  }
  prefix_sum[n] = prefix_sum[n-1];
  
  std::cin >> number_of_queries;
  for(int i = 0; i < number_of_queries; ++i){
    std::cin >> l >> r;
    std::cout << (prefix_sum[r-1] - prefix_sum[l-1]) << std::endl;
  }
  return 0;
}
