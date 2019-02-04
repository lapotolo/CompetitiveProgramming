#include <iostream>
#include <string>

std::string hello(std::string const& input){
  int pos = 0;
  std::string s("hello");
  for (int i = 0; i < input.size(); ++i){
    if (input[i] == s[pos]){
      ++pos;
      if (pos == s.size()) return "YES";
    }
  }
  return "NO";
}

int main() {
  std::string input;
  std::getline(std::cin, input);
  std::cout << hello(input);
}