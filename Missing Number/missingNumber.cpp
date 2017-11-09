#include <iostream>
#include <vector>

using namespace std;


int sum_input_sequence(int input_stream_len){
    int x, sum = 0;
    for (int i = 0; i < input_stream_len ; ++i){
        cin >> x;
        sum += x;
    }
    return sum;
}

	
int main(){

	int test_cases, n, input_sum, missing_number;

	cin >> test_cases;

	vector<int> seq;

	for (int i = 0; i < test_cases; ++i){
		cin >> n;
		input_sum = sum_input_sequence(n-1);
		missing_number = (n*(n+1)/2) - input_sum;
        cout << missing_number << endl;
	}
	
	return 0;
}