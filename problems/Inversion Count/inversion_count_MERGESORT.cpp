#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<typename T>
std::vector<T> get_input_sequence(size_t n) {
    std::vector<T> inputSequence(n);
    for(size_t i = 0; i < n; ++i) 
        std::cin >> inputSequence[i];
    return inputSequence;
}

uint64_t merge_and_count(vector<uint64_t>& sequence, size_t left, size_t middle, size_t right){
	uint64_t inversions_count = 0;
	size_t i = left;
	size_t j = middle + 1;
	size_t k = 0;

	vector<uint64_t> res_array(right-left+1);

	while((i <= middle) and (j <= right)){
		if (sequence[i] < sequence[j]){
			res_array[k] = sequence[i];
			k++;
			i++;
		} else{
			res_array[k] = sequence[j];
			k++;
			j++;
			inversions_count += middle-i+1;
		}
	}

	while(i <= middle){
    	res_array[k++] = sequence[i++];
  	}
  
  	while(j <= right){
  		res_array[k++] = sequence[j++];
  	}

	/*
	if (i <= middle){
		copy(sequence.begin()+i, sequence.begin()+middle, res_array.begin()+k);
	}

	if (j <= right){
		copy(sequence.begin()+j, sequence.end(), res_array.begin()+k);
	}
	*/
	copy(res_array.begin(), res_array.end(), sequence.begin()+left);
	
	return inversions_count;
}

uint64_t mergesort_count(vector<uint64_t>& sequence, size_t left, size_t right){
	if (left >= right){
		return 0;
	}
	size_t middle = (left+right)/2;
	uint64_t left_subarray_count = mergesort_count(sequence, left, middle);
	uint64_t right_subarray_count = mergesort_count(sequence, middle+1, right);
	return left_subarray_count + right_subarray_count + merge_and_count(sequence, left, middle, right);
}

// use mergesort
int main(){
	std::ios_base::sync_with_stdio(false);

	string blank;

	size_t test_cases;
	cin >> test_cases;
	getline(cin, blank);
	for (int i = 0; i < test_cases; ++i){
		size_t array_size;
		cin >> array_size;
		auto sequence = get_input_sequence<uint64_t>(array_size);
		getline(cin, blank);

		uint64_t inversions_count = mergesort_count(sequence, 0, array_size-1);

		cout << inversions_count << endl;
	}
	return 0;
}
