#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
std::vector<T> get_input_sequence(size_t n) {
    std::vector<T> inputSequence(n);
    for(size_t i = 0; i < n; ++i) 
        std::cin >> inputSequence[i];
    return inputSequence;
}

int main(int argc, char const *argv[]){
	std::ios_base::sync_with_stdio(false);

	size_t N;
	int maxHeight = 0, currentHeight = 0, currentLength = 0, towers = 0;

	//	std::cout << "Give me the number of bars ";
	std::cin >> N;
	// std::cout << "Give me the lenghts of the bars separated by blank spaces ";
	auto lenghts = get_input_sequence<int>(N);
	
	std::sort(lenghts.begin(), lenghts.end(),
		[](int const x, int const y){
			return x > y;
		}
	);

	for (auto it = lenghts.begin(); it != lenghts.end(); ++it){
		if (*it == currentLength){
			++currentHeight;
			if (currentHeight > maxHeight){
				maxHeight = currentHeight;				
			}
		}	
		else { // *it != currentLength
			currentLength = *it;
			currentHeight = 1;
			++towers;
		}
	}
	lenghts.clear();
	std::cout << maxHeight << " " << towers << std::endl;
	return 0;
}
