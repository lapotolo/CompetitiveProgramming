#include <iostream>
#include <vector>

template<>
std::vector<int> fo()


int main(){
	int input_num, length, num_test_cases = 0;
    std::cin >> num_test_cases;

    std::vector<int> vec;

    for (int i = 0; i < num_test_cases; ++i){
    	std::cin >> length;
    	vec.reserve(length);
    	for (int j = 0; j < count; ++j){
    		std::cin input_num;
    		vec.push_back(input_num);
    	}

    	auto result = foo(vec, [](int x, int y){
    					return x > y;});

    }
	return 0;
}