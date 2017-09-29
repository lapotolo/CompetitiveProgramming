#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
std::vector<T> get_input_sequence(size_t n) {
    std::vector<T> sequence(n);
    
    for(size_t i = 0; i < n; ++i) 
        std::cin >> sequence[i];
    return sequence;
}

int main(int argc, char const *argv[]){
	std::ios_base::sync_with_stdio(false);

	size_t N;
	int largestHeight, towers;

	std::cout << "Give me the number of bars ";
	std::cin >> N;
	towers = 1;
	std::cout << "Give me the lenghts of the bars separated by blank spaces ";
	auto lenghts = get_input_sequence<int>(N);

	std::sort(lenghts.begin(), lenghts.end(),
		[](int const x, int const y){
			return x > y;
		}
	);

	// CAN BE IMPROVED. DONT USE COUNT!!
	largestHeight = std::count(lenghts.begin(), lenghts.end(), *(lenghts.begin()));

	for (auto it = lenghts.begin(); it != --lenghts.end(); ++it){
		if (*it != *(std::next(it))){
			++towers;
		}
	}
	std::cout << largestHeight << " " << towers << std::endl;
	return 0;
}
