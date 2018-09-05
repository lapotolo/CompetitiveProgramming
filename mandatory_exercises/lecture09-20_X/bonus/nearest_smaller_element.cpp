/*
Problem: 

Description:


Time cost = O() 
Space cost = O()

*/

#include <iostream>
#include <vector>
#include <stack>

void fill_vector(std::vector<int> & vec, size_t n) {
    int x = 0;
    for(size_t i = 0; i < n; ++i){
        std::cin >> x;
    	vec.push_back(x);
    }	
}

void print_vector(std::vector<int> const& v){
    for(auto e : v) std::cout << e << " ";
    std::cout << std::endl;

} 

std::vector<int> next_smaller_element(std::vector<int> & v, size_t n){
    std::vector<int> answer;
    answer.reserve(n);
    std::stack<int> buffer;

    for(size_t i = 0; i < n; ++i){
        while( !buffer.empty() && buffer.top() >= v[i] )
            buffer.pop();
        if( !buffer.empty() )
            answer.push_back(buffer.top());
        buffer.push(v[i]);
    }
    return answer;
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
		print_vector(next_smaller_element(seq, n));
        
        seq.clear();
	}

	return 0;
}