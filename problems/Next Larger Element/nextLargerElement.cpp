#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


void compute_next_larger_array(std::vector<int64_t> const& vec){
  std::vector<int64_t> result;
  result.reserve(vec.size());
  std::stack<int64_t> s;
  int64_t next_greater_element;
  bool found = false;
  for(int64_t i = vec.size()-1; i >= 0; --i) {
    next_greater_element = -1;
    while(!s.empty() and !found){
      if(s.top() > vec[i]){
        next_greater_element = s.top(); 
        found = true;
      }
      else s.pop();
    }
    result.push_back(next_greater_element);
    s.push(vec[i]);
    found = false;
  }
  for_each(result.rbegin(),result.rend(), [](int_fast64_t el) { std::cout << el << " "; });
  std::cout << std::endl;
}


int main(){
  size_t t, n;
  std::cin >> t;
  
  while(t > 0) {
    std::cin >> n;
    std::vector<int64_t> vec(n);	
    for (size_t i = 0; i < n; ++i) std::cin >> vec[i];
    // printarr(vec, 0);
    compute_next_larger_array(vec);
    
    vec.clear();
    --t;
  }
  return 0;
}
