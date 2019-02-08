#include <iostream>
#include <vector>
#include <deque>


void sliding_window(std::vector<int> const& seq, int k) {
	std::deque<std::pair<int, int>> deq; // first <- value, second <- index of element in first
	std::vector<int> maxs;
	maxs.reserve(seq.size() - k + 1);

	for (int i = 0 ; i < seq.size(); ++i) {
        
		// Removes elements no longer in the window from the front
		// since i is the right end of the window, i-k is the first index out of the range window on the left
		while (!deq.empty() and deq.front().second <= i - k) deq.pop_front();

		// Removes from back elements which are no longer useful, i.e., no greater than the current element
		while (!deq.empty() and deq.back().first <= seq[i]) deq.pop_back();
	
		deq.push_back(std::make_pair(seq[i], i));
        
		if (i >= k - 1) maxs.push_back(deq.front().first);
	}
	// print result
	for(size_t i = 0; i < maxs.size(); ++i) std::cout << maxs[i] << " ";
	std::cout << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	size_t t, n, k;
	std::cin >> t;

	while(t > 0) {
		std::cin >> n >> k;
		std::vector<int> input(n,0);
		
		for (int i = 0; i < n ; ++i) std::cin >> input[i];

		sliding_window(input, k);
		input.clear();
		--t;
	}
	return 0;
}