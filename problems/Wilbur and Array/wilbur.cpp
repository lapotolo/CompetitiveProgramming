// author: Lapo Toloni
// problem: http://codeforces.com/problemset/problem/596/B?locale=en

// wrong on answer 12 

#include <iostream>
#include <vector>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);

    int n;
    int64_t val, last_val_seen = 0, steps = 0;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> val;
        steps = steps + abs(last_val_seen - val);
        last_val_seen = val;  
    }
    cout << steps << endl;
}
