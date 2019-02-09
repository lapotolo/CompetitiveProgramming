#include<iostream>
#include<cmath>
#include<vector>
#include<queue>

bool primality_test(int n){
	int i = 3;
	int stop = (int) sqrt(n);
	if (n == 2) return true;
	if (n % 2 == 0) return false;
  while (n%i != 0 && i <= stop) i += 2;
	return (i > stop);
}

// vector<bool> generate_sieve(int n){
//     vector<bool> primes(n, true);
//     for(uint64_t i = 2; i <= (uint64_t) sqrt(n); ++i) {
//         if (primes[i]) {
//             uint64_t isquare = i*i;
//             for(uint64_t j = isquare; j < n; j+=i)
//                 primes[j] = false;
//         }
//     }
//     // for(int i = 0; i<n; ++i){
//     //     cout << "i = " << i+1 << " -> "<< primes[i] << " | ";
//     // }
//     // cout << endl;
//     return primes;
// }

void bfs(std::vector<std::vector<int>> & children, int root_rank, std::vector<int> & depths) {
	int current_node;
	int current_depth = 1;
	int num_children = children[root_rank].size();
	std::queue<int> frontier;
	for(auto child : children[root_rank]){
		frontier.push(child);
	}
	while(!frontier.empty()) {
		current_node = frontier.front();
		depths[current_node] = current_depth;
		frontier.pop();
		num_children--;
		for(auto child : children[current_node]) {
			frontier.push(child);
		}
		if (num_children == 0){
			num_children = frontier.size();
			current_depth++;
		}
	}
}

int solve_firing_employees(std::vector<int> const& depths) {
	int num_fired_emp = 0;
	for (size_t i = 1; i < depths.size(); ++i)
		if (depths[i] and primality_test(depths[i]+i))
			num_fired_emp++;    
	return num_fired_emp;
}

int main() {

  int t, num_employees, root_rank, senior_rank, result;
  std::cin >> t;

	while(t > 0) {
		std::cin >> num_employees;
		std::vector<std::vector<int> > children(num_employees + 1); // first element is dummy
		std::vector<int> seniors(num_employees + 1, 0); // seniors[i] is the current_depth==#seniors of employee with rank i


		// children[i] is the list of children of emp with rank i
		for (size_t i = 1; i <= num_employees; ++i) {
			std::cin >> senior_rank;
			if(senior_rank == 0) root_rank = i;
			children[senior_rank].push_back(i);
		}

		bfs(children, root_rank, seniors);
        
		result = solve_firing_employees(seniors);
		std::cout << result << std::endl;    
		seniors.clear();
		children.clear();
		--t;
    }
    return 0;
}