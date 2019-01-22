#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	size_t N = 10;
	int copy_range_start = N/2;
	int copy_range_end = 10;

	std::vector<int> seq(N);
	std::vector<int> result(N/2);



	for (int i = 0; seq[i]!=*seq.end(); ++i){
		seq[i] = i;
	}
	for(int e : seq){
		std::cout << e << " ";
	}
	std::cout << std::endl;



	copy(seq.begin()+seq[copy_range_start], seq.begin()+seq[copy_range_end], result.begin());
	for(int e : result){
		std::cout << e << " ";
	}
	std::cout << std::endl;
	

	return 0;
}	