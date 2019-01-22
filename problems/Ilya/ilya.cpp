// JUST TEST IT

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int number_of_queries, l, r;
    string input_string;
    cin >> input_string;

    size_t n = input_string.length();
    vector<int> prefix_sum(n+1);

    prefix_sum[0] = 0;
    for (int i = 1; i < n; ++i){
        if (input_string[i] == input_string[i-1]){
            prefix_sum[i] = prefix_sum[i-1] + 1;
        }else {
            prefix_sum[i] = prefix_sum[i-1];
        }
    }
    prefix_sum[n] = prefix_sum[n-1];
    
    for(auto e : prefix_sum){
        cout << e << " ";
    }
    cout << endl;

    cin >> number_of_queries;
    for(int i = 0; i < number_of_queries; ++i){
        cin >> l >> r;
        cout << (prefix_sum[r-1] - prefix_sum[l-1]) << endl;
    }

    return 0;
}
