/*
Problem: 

Description:


Time cost = O() 
Space cost = O()

*/

#include <iostream>
#include <vector>

void fill_vector(std::vector<int> & vec, size_t n) {
    int x = 0;
    for(size_t i = 0; i < n; ++i){
        std::cin >> x;
    	vec.push_back(x);
    }	
}

int main(){
    
    std::ios_base::sync_with_stdio(false);

	int test_cases, n;
	std::cin >> test_cases;
	std::vector<int> seq;

	for (int i = 0; i < test_cases; ++i){
        int n = 0;
		std::cin >> n;
		seq.reserve(n);
		fill_vector(seq, n);
        // DO STUFF
		seq.clear();
	}

	return 0;
}