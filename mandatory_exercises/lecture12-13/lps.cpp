// author: Lapo Toloni
// problem: https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0

#include <iostream>
#include <vector>

using namespace std;

// just like kmp failure function
int compute_pref_suff_array(string const& pattern){
    int k = 0;
    int m = pattern.size();
    vector<int> pi(m);
    pi[0] = 0;
    for(int q = 1; q < m; ) {
        if(pattern[q] == pattern[k]) {
            pi[q] = k + 1;
            k++;
            q++;
        } else { // mismatch, dont need a while cause q is not incremented in the missmatch case
            if(k != 0) k = pi[k - 1];
            else {
                pi[q] = 0;
                q++;
            }
        }
    }
    return pi[m-1];
}

int main() {
    int num_test;
    string s;

    cin >> num_test;

    while(num_test != 0){
        cin >> s;
        cout << compute_pref_suff_array(s);
        cout << endl;
        s.clear();
        num_test--;
    }
}