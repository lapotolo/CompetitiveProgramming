#include <iostream>
#include <vector>

using namespace std;

// O(n)

int compute_min_jumps(vector<int> & vec, int n){
    if(n <= 1) return 0;

    vector<int> dp(n);
    dp[0] = 0;
    for(int i = 0, next = 1; i < n and next < n ; ++i) {
        if( i == next - 1 and vec[i] == 0) 
            return -1;
        // i + vec[i] is the range covered jumping from node i
        for(int j = next; j < n and j <= i + vec[i]; ++j, ++next){
            dp[j] = 1 + dp[i];
        }
    }

    return dp[n-1];
}

int main(){
    std::ios_base::sync_with_stdio(false);

    int num_test, x, n;
    cin >> num_test;
    vector<int> seq;
    while(num_test > 0){
        cin >> n;
        seq.reserve(n);
        for(int i = 0; i < n; ++i){
            cin >> x;
            seq.emplace_back(x);
        }
        cout << compute_min_jumps(seq, n) << endl;
        seq.clear();
        num_test--;
    }
}