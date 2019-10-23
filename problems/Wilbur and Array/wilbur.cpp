#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  
  int64_t n, input, left_val = 0, op_count = 0;
  std::cin >> n;
  
  for(int i = 0; i < n; ++i){
    std::cin >> input;
    op_count += abs(left_val - input);
    left_val = input;  
  }
  std::cout << op_count << std::endl;
  return 0;
}
