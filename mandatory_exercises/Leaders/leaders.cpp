#include <iostream>
#include <vector>

void fill_vector(std::vector<int> & vec, size_t n) {
    int x = 0;
    for(size_t i = 0; i < n; ++i){
        std::cin >> x;
    	vec.push_back(x);
    }	
}

void find_leaders(std::vector<int> const& vec){
    std::vector<int> leaders;
    leaders.reserve(vec.size());
    int current_leader = vec.back();
    leaders.push_back(current_leader);

    for (auto it = vec.rbegin() + 1; it != vec.rend(); ++it){ // rbegin + 1 because we skip the last element
        if(*it >= current_leader){
            current_leader = *it;
            leaders.push_back(current_leader);
        }
    }
    for(auto it = leaders.rbegin(); it != leaders.rend(); ++it){
        std::cout << *it << " ";
    } 
    std::cout << std::endl;
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
		find_leaders(seq);
		seq.clear();
	}

	return 0;
}