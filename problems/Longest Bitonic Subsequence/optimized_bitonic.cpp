/*
By employing the same technique as in problem "Longest Increasing Subsequence",
for each 0<=n<N we compute the longest increasing subsequence ending at position
n (LIS[n]) and the longest decreasing subsequence starting at position n (LDS[n]).
The answer is simply the maximum of LIS[n]+LDS[n]-1.

Time complexity:  O(NlogN)
Space complexity: O(N)
*/

#include <bits/stdc++.h>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int& a : A) {
        cin >> a;
    }
    vector<int> V;
    vector<int> LIS, LDS;
    for(int a : A) {
        auto it = lower_bound(V.begin(), V.end(), a);
        LIS.push_back(it - V.begin() + 1);
        if(it == V.end()) {
            V.push_back(a);
        } else {
            *it = a;
        }
    }

    reverse(A.begin(), A.end());
    V.clear();
    for(int a : A) {
        auto it = lower_bound(V.begin(), V.end(), a);
        LDS.push_back(it - V.begin() + 1);
        if(it == V.end()) {
            V.push_back(a);
        } else {
            *it = a;
        }
    }
    printarr(LIS,0);
    printarr(LDS,0);

    reverse(LDS.begin(), LDS.end());
    int ans = 0;
    for(int n = 0; n < N; ++n) {
        ans = max(ans, LIS[n] + LDS[n] - 1);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
