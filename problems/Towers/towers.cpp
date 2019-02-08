#include <iostream>
#include <vector>
#include <algorithm>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) /*std::cout<< #a ": ";*/ for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


int main() {
	std::ios_base::sync_with_stdio(false);

	size_t N, h;
	std::cin >> N;
	std::vector<size_t> lens(N);

	for (size_t i = 0; i < N; ++i) std::cin >> lens[i];
	std::sort(lens.begin(), lens.end(),
		[](int const x, int const y){
			return x > y;
		}
	);

	size_t towers = 1, max_h = 1, curr_h = 1, curr_len = lens[0];
	for (size_t i = 1; i < N; ++i) {
		if (lens[i] == curr_len) {
			++curr_h;
			if (curr_h > max_h) max_h = curr_h;				
		}	
		else {
			curr_len = lens[i];
			curr_h = 1;
			++towers;
		}
	}
	lens.clear();
	std::cout << max_h << " " << towers << std::endl;
	return 0;
}
