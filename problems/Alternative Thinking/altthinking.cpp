#include <iostream>
#include <string>

int max_alt_subsequence_len(std::string const& input){
  int len = 1;
  for(int i = 1; i < input.size(); i++)
	len += (input[i] != input[i - 1]);
  return len;
}

int main(){
  std::ios_base::sync_with_stdio(false);

  int input_len, len_alt_sub;
  std::string input;
  std::cin >> input_len >> input;

  len_alt_sub = max_alt_subsequence_len(input);

  std::cout << std::min<int>(len_alt_sub + 2, input_len) << std::endl;
  return 0;
}

