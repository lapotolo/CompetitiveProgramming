#include <iostream>
#include <vector>
#include <stack>

int isBSTTraversal(std::vector<int> & v) {
  int last_max = -1;
  std::stack<int> s;
  s.push(v.front()); // push the root onto the stack

  size_t i = 1;
  while (i != v.size()) {
    if (v[i] < s.top()) {
      if (v[i] < last_max) return 0;
      else s.push(v[i]);
    }
    else {
      while (!s.empty() and v[i] > s.top()) {
        last_max = s.top();
        s.pop();
      }
      s.push(last_max);
      s.push(v[i]);
    }
    i++;
  }
  return 1;
}

int main() {
  int t, n;
  std::cin >> t;

  while(t > 0) {
    std::cin >> n;
    std::vector<int> input(n);
    for (size_t i = 0; i < n; ++i) std::cin >> input[i];
    
    std::cout << isBSTTraversal(input) << std::endl;
    
    input.clear();
    --t;
  }
  return 0;
}