#include <iostream>
#include <vector>

using namespace std;

void fill_vector(vector<int> & vec, int n) {
    int x;
    vec.reserve(n);
    for(int i = 0; i < n; ++i){
        cin >> x;
        vec.push_back(x);
    }
}

int solve_lis(vector<int> const& v){
    int min_seen = v[0], lis_len = 1;
    vector<int> inc_seqs_lengths;
    inc_seqs_lengths.reserve(v.size());
    inc_seqs_lengths.push_back(1);
    for(int i = 1; i < v.size(); ++i){
        if(v[i] <= min_seen){
            inc_seqs_lengths.push_back(1);
            min_seen = v[i];
        } else {
            int best = 0;
            for(int j = 0; j < i ; ++j){
                if(v[j] < v[i] and best < inc_seqs_lengths[j]){
                    best = inc_seqs_lengths[j];    
                }
            }
            inc_seqs_lengths.push_back(best+1);
            if((best+1) > lis_len) // check if new lis is the longest
                lis_len = best+1;
        }
    }
    return lis_len;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int test_cases, n;
    cin >> test_cases;
    while(test_cases > 0){
        vector<int> input;
        cin >> n;
        fill_vector(input, n);
        if(n > 0)
            cout << solve_lis(input) << endl;
        else 
            cout << 0 << endl;
        input.clear();
        test_cases--;
    }
    return 0;
}