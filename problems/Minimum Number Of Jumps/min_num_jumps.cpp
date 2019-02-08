#include <iostream>
#include <vector>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


int compute_min_jumps(std::vector<int> & vec, int n){
	if(n <= 1) return 0; // im already in the last position

	std::vector<int> J(n);
	J[0] = 0;
	for(int i = 0, next = 1; i < n and next < n ; ++i) {
		if( (i + 1) == next and vec[i] == 0) return -1; // it's impossible to get to the end if 
		// i + vec[i] is the range covered jumping from node i
		for(int j = next; j < n and j <= i + vec[i]; ++j, ++next) J[j] = 1 + J[i];
	}
	return J[n-1];
}

int main(){
	std::ios_base::sync_with_stdio(false);

	int num_test, x, n;
	std::cin >> num_test;
	std::vector<int> seq;
	while(num_test > 0){
		std::cin >> n;
		seq.reserve(n);
		for(int i = 0; i < n; ++i) {
			std::cin >> x;
			seq.emplace_back(x);
		}
		std::cout << compute_min_jumps(seq, n) << std::endl;
		seq.clear();
		num_test--;
	}
}