// author: Lapo Toloni
// problem: http://codeforces.com/problemset/problem/313/B?locale=en

#include <iostream>
#include <vector>

using namespace std;

vector<int> build_prefix_sum_array(string const& str){
    vector<int> prefix_sum(str.size());
    for (int i = 1; i < str.size(); ++i){
        if (str[i] == str[i-1]) prefix_sum[i] = 1 + prefix_sum[i-1];
        else prefix_sum[i] = prefix_sum[i-1];
    }
    return prefix_sum;
}

int main(){
    int number_of_queries, l, r;
    string input_string;
    cin >> input_string;

    size_t n = input_string.length();
    auto prefix_sum_arrray = build_prefix_sum_array(input_string);
    
    // cout << endl;
    // for(auto e : B){
    //     cout << e << " ";
    // }
    // cout << endl;

    cin >> number_of_queries;
    for(int i = 0; i < number_of_queries; ++i){
        cin >> l >> r;
        cout << (prefix_sum_arrray[r-1] - prefix_sum_arrray[l-1]) << endl;
    }

    return 0;
}
