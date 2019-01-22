#include <iostream>
#include <vector>
#include <algorithm>

#define debugln(x) std::cout << x << std::endl
#define debug(x)   std::cout << x


template<typename T>
void printv(std::vector<T> const& v){
  for(auto el : v) std::cout<< el << " ";
  std::cout << std::endl;
}
