/*

author: Lapo Toloni
problem: https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

*/


#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> & vec){
    for(auto element : vec){
        cout << element << " ";
    }
    cout << endl;
}

void solve_subsetsum(vector<int> vec, int halved_sum){
    int lookback_index;
    bool dp_table[vec.size()+1][halved_sum+1];
    for(int j = 0; j <= halved_sum ; ++j)
        dp_table[0][j] = 0;

    for(int i = 0; i <= vec.size() ; ++i)
        dp_table[i][0] = 1;

    for(int i = 1; i <= vec.size() ; ++i){
        for(int j = 1; j <= halved_sum ; ++j){
            lookback_index = j - vec[i - 1];
            if(lookback_index >= 0 and dp_table[i-1][lookback_index])
                dp_table[i][j] = dp_table[i-1][lookback_index];
            else
                dp_table[i][j] = dp_table[i-1][j];
        }
    }
    // for(int i = 0; i<=vec.size(); ++i){
    //     for(int j = 0; j<=halved_sum; ++j){
    //         std::cout << (dp_table[i][j]? "Y " : "N ");
    //     }
    //     std::cout << std::endl;
    // }

    cout << (dp_table[vec.size()][halved_sum] ? "YES\n" : "NO\n");


}

int main() {

    std::ios_base::sync_with_stdio(false);

    int num_tests, N, x, sum = 0;
    cin >> num_tests;
    while(num_tests > 0){
        vector<int> test;
        cin >> N;
        test.reserve(N);
        for(int i = 0; i < N; ++i){
            cin >> x;
            test.push_back(x);
            sum += x;
        }
        if(sum % 2 == 1) 
            cout << "NO\n";
        else{
            sum /= 2;
            solve_subsetsum(test, sum);
        }
        sum = 0;
        test.clear();
        num_tests--;
    }

    return 0;
}
