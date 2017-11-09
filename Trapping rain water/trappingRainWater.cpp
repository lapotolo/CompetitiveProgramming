/*

solution to:
http://practice.geeksforgeeks.org/problems/trapping-rain-water/0

THINK LOCALLY

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> get_input_sequence() {
    size_t n = 0;
    cin >> n;
    vector<int> inputSequence(n);
    for(size_t i = 0; i < n; ++i) 
        cin >> inputSequence[i];
    return inputSequence;
}

	
int main(){
	int test_cases, trapped_water;
    cin >> test_cases;
    vector<vector<int>> tests(test_cases);

    for (int i = 0; i < test_cases; ++i){
        tests[i] = get_input_sequence();
    }

    for(auto t : tests){
        trapped_water = 0;
        int len = t.size();
        vector<int> maxs_to_the_left(len); 
        vector<int> maxs_to_the_right(len);

        maxs_to_the_left[0] = 0;
        for (int i = 1; i < len-1; ++i){
            maxs_to_the_left[i] = max(maxs_to_the_left[i-1], t[i-1]);            
        }


        maxs_to_the_right[len-1] = 0;
        for (int i = len-2; i >= 0; --i){
            maxs_to_the_right[i] = max(t[i+1], maxs_to_the_right[i+1]);            
        }

        for (int i = 1; i<len-1; ++i){
            trapped_water += max(min(maxs_to_the_left[i], maxs_to_the_right[i])-t[i], 0);
        }
        maxs_to_the_left.clear();
        maxs_to_the_right.clear();

        cout << trapped_water << endl;
       
	}
	return 0;
}