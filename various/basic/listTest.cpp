#include <iostream>
#include <forward_list>

int main(int argc, char const *argv[])
{
	size_t N = std::stoull(argv[1]);
	std::forward_list<uint32_t> l;

	for (uint32_t i = 0; i < N; ++i)
	{
		l.push_front(i);
	}

	uint64_t sum = 0;
	for(auto item : l){
		sum += item;
	}

	std::cout << "sum: " << sum << std::endl;

	uint64_t prova = ((N * (N+1))/2) - N;

	std::cout << "riprova: " << prova << std::endl;

	return 0;
}