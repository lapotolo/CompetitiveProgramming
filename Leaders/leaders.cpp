#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void fill_vector(vector<int> & vec, size_t n) {
    int x = 0;
    for(size_t i = 0; i < n; ++i){
        cin >> x;
    	vec.push_back(x);
    }	
}

void find_leaders(vector<int> const& vec){
    vector<int> leaders;
    int current_leader = vec.back();
    leaders.push_back(current_leader);

    for (auto it = vec.rbegin() + 1; it != vec.rend(); ++it){
         if(*it > current_leader){
            current_leader = *it;
            leaders.push_back(current_leader);
         }
    }
    copy(leaders.rbegin(), leaders.rend(), std::ostream_iterator<int>(std::cout, " ")); 
    cout << endl;

}

	
int main(){

	int test_cases, n;

	cin >> test_cases;

	vector<int> seq;

	for (int i = 0; i < test_cases; ++i){
		cin >> n;
		seq.reserve(n);
		fill_vector(seq, n);
		find_leaders(seq);
		seq.clear();
	}
	
	return 0;
}