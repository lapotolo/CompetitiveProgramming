#include <iostream>
#include <vector>
#include <stack>
#include <climits>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


int is_BST(std::vector<int> const& v, int n) { 
	std::stack<int> s; 
	int root = INT_MIN; 

	for (size_t i = 0; i < n; ++i) { 
		if (root > v[i]) return 0; // nodes on the right of the root cannot be greater than root in a BST 

		while (!s.empty() and s.top() < v[i]) { 
			root = s.top(); 
			s.pop(); 
		} 
		s.push(v[i]); 
	} 
	return 1; 
} 

int main() {
  int t, n;
  std::cin >> t;
  std::vector<int> input;

  while(t > 0) {
  
    std::cin >> n;
    input.resize(n);
    for (size_t i = 0; i < n; ++i) std::cin >> input[i];
    
    std::cout << is_BST(input, n) << std::endl;

    input.clear();
    --t;
  }
  return 0;
}