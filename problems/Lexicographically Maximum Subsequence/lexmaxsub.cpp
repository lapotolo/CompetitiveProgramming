#include <iostream>
#include <string>
#include <algorithm>


std::string find_lex_max_substring(std::string const& input){
  std::string result;
  char max = input[input.size()-1];
  for(auto it = input.rbegin(); it != input.rend(); ++it){
    if(*it >= max){
      result += *it;
      max = *it;
    }
  }
  std::reverse(result.begin(), result.end());
  return result;
}    


int main(){
  std::string input;
  std::cin >> input;
  std::cout << find_lex_max_substring(input) << std::endl;
}
