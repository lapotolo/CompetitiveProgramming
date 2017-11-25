#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve_LCS(string & s1, string & s2){
    vector<vector<int>> T(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    // for (int i = 0; i <= s1.size(); ++i) T[i][0] = 0;
    // for(int j = 0; j <= s1.size(); ++j) T[0][j] = 0;

    for (int i = 1; i <= s1.size(); ++i){
        for (int j = 1; j <= s2.size(); ++j){
            if (s1[i-1] == s2[j-1]) T[i][j] = T[i - 1][j - 1] + 1; // [i-1][j-1] inside the if??
            else T[i][j] = max(T[i - 1][j], T[i][j - 1]);
        } 
    }
    return T[s1.size()][s2.size()];
}

int main(){

    int num_test, len1, len2;

    string s1;
    string s2;

    cin >> num_test;

    while(num_test != 0){
        cin >> len1 >> len2;
        cin >> s1;
        cin >> s2;

        cout << solve_LCS(s1, s2) << endl;

        s1.clear();
        s2.clear();
        num_test--;
    }
}