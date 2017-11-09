#include <iostream>
#include <vector>

using namespace std;

void fill_vector(vector<int> & vec, size_t n) {
    int x = 0;
    for(size_t i = 0; i < n; ++i){
        cin >> x;
    	vec.push_back(x);
    }	
}

void kadane(vector<int> const& vec){
    // inizialitze both the counters to the first element
    // in case all numbers are negative
	int sum = vec.front();
    int max_sum = sum;

    for (auto it = vec.begin() + 1; it != vec.end(); ++it) {
        if (sum > 0) {
            sum += *it;
        } else {
            sum = *it;
        }
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    cout << max_sum << endl;
}

	
int main(){

	int test_cases, n;

	cin >> test_cases;

	vector<int> seq;

	for (int i = 0; i < test_cases; ++i){
		cin >> n;
		seq.reserve(n);
		fill_vector(seq, n);
		kadane(seq);
		seq.clear();
	}
	
	return 0;
}