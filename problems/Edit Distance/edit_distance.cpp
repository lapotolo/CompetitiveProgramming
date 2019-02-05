#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int solve_edit_distance(std::string const & s1, std::string const & s2) {
	std::vector<std::vector<int>> T(s1.size()+1, std::vector<int>(s2.size()+1, 0));
	for (int i = 1; i <= s1.size(); ++i) T[i][0] = i;
	for(int j = 1; j <= s2.size(); ++j) T[0][j] = j;
	for (int i = 1; i <= s1.size(); ++i){
		for (int j = 1; j <= s2.size(); ++j){
			if(s1[i-1] == s2[j-1]) T[i][j] = T[i-1][j-1];
			else T[i][j] = 1 + std::min<int>(T[i][j-1],     // INSERT
						  					 std::min<int>(T[i-1][j],     // REMOVE
													             T[i-1][j-1])); // REPLACE      
		} 
	}
	return T[s1.size()][s2.size()];
}

int main() {
  std::ios_base::sync_with_stdio(false);

	int num_test, len1, len2;

	std::string s1;
	std::string s2;

	std::cin >> num_test;

	while(num_test != 0){
		std::cin >> len1 >> len2;
		std::cin >> s1 >> s2;
		std::cout << solve_edit_distance(s1, s2) << std::endl;
		s1.clear();
		s2.clear();
		num_test--;
	}
}