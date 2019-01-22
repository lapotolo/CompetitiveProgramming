// author: Lapo Toloni
// problem: http://codeforces.com/problemset/problem/603/A

#include <iostream>

using namespace std;

int max_alt_subsequence_len(string const& input){
    int len = 1;
    for(int i = 1; i < input.size(); i++)
        len += (input[i] != input[i - 1]);
    return len;
}

int main(){
    int input_len, len_alt_sub;
    string input;
    cin >> input_len >> input;

    len_alt_sub = max_alt_subsequence_len(input);

    cout << min<int>(len_alt_sub + 2, input_len) << endl;
    return 0;
}