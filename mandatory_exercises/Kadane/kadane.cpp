/*
Problem: https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

Description:
Scan the input array left to right saving step by step the max sum of contiguous elements encountered so far
The first value of the var max_sum is set to the first element of the input array 
We can achieve the right result straightforward in one pass because of the following properties:
1. the the two elements before and after the the first and the last element of the sub-array with maximum sum have to be negative 
2. Every prefix of the sub-array with maximum sum must be positive

Time cost = O(n)
Space cost = O(n) for the input, O(1) to solve Kadane's problem (we just use two variables)

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

void kadane(std::vector<int> const& vec){
    // init both the counters to the first element
    // in case all numbers are negative
	int sum = vec.front();
    int max_sum = sum;

    for (auto it = vec.begin() + 1; it != vec.end(); ++it) {
        if (sum > 0) {
            sum += *it;
        } else {
            sum = *it;
        }
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    std::cout << max_sum << std::endl;
}

	
int main(){
    std::ios_base::sync_with_stdio(false);

	int test_cases, n;

	std::cin >> test_cases;

	std::vector<int> seq;

	for (int i = 0; i < test_cases; ++i){
		std::cin >> n;
		seq.reserve(n);
		fill_vector(seq, n);
		kadane(seq);
		seq.clear();
	}
	
	return 0;
}