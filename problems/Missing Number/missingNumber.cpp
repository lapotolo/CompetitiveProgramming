#include <iostream>
#include <vector>


int sum_input_sequence(int input_stream_len){
    int x; 
	int sum = 0;
    for (int i = 0; i < input_stream_len ; ++i){
        std::cin >> x;
        sum += x;
    }
    return sum;
}

	
int main(){
  	std::ios_base::sync_with_stdio(false);

	int test_cases, n, input_sum, missing_number;

	std::cin >> test_cases;

	std::vector<int> seq;

	for (int i = 0; i < test_cases; ++i){
		std::cin >> n;
		input_sum = sum_input_sequence(n-1);
		missing_number = (n*(n+1)/2) - input_sum;
        std::cout << missing_number << std::endl;
	}
	
	return 0;
}