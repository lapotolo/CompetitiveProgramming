#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	size_t N = std::stoull(argv[1]);
	std::vector<uint32_t> v;
	v.reserve(N);

	for (uint32_t i = 0; i < N; ++i)
	{
		v.push_back(i);
	}

	uint64_t sum = 0;
	for(auto item : v){
		sum += item;
	}

	std::cout << "sum: " << sum << std::endl;

	uint64_t prova = ((N * (N+1))/2) - N;

	std::cout << "riprova: " << prova << std::endl;

	return 0;
}