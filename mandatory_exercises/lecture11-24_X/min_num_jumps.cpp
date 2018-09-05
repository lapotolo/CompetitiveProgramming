// ACCEPTED BUT CHECK THE SOLUTION

#include <iostream>
#include <vector>

using namespace std;

// O(n)
/*
    Each element of array is visited at most twice
    1. by using i
    2. by using j
    For inner loop, if element is already visited then we increment next, so that it is not visited again.

    How its working : If I can reach ith index in x steps then I can also reach all j<i in x or lesser steps.
    Lets take the example to understand it.

    arr = 3, 5, 2, 4, 0, 3, 1

    From index=0, I can reach index=1,2,3 in 1 step. so dp[1]=dp[2]=dp[3] = 1. (Assuming to reach index=0 take 0 steps)
    for index=1, I can reach index=2,3,4,5,6 but the index 2,3 cannot be reached in less steps than their previous value(which is 1, using dp array).
    So why I should check for those indexes which are already reachable from any other smaller index. 
    Therefore I will only update for index=4,5,6. That is taken care by 'next' variable.
    And similary go ahead.

*/

// Assumption : I can reach first index in 0 step.



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