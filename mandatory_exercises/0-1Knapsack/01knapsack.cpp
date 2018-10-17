#include <iostream>
#include <vector>

using namespace std;

// void print_vector(vector<int> & vec){
//     for(auto element : vec){
//         cout << element << " ";
//     }
//     cout << endl;
// }

void fill_vector(vector<int> & vec, size_t n) {
    int x;
    vec.reserve(n);
    for(size_t i = 0; i < n; ++i){
        cin >> x;
        vec.push_back(x);
    }   
}

int solve_01knapsack(vector<int> & weights, vector<int> & values, int W){ // O(nW)
    vector<vector<int>> T(values.size()+1, vector<int>(W+1, 0));
    for(int j = 0; j <= W; ++j) T[0][j] = 0;
    for (int i = 1; i <= values.size(); ++i){
        for (int j = 0; j <= W; ++j){
            if (j < weights[i - 1]) T[i][j] = T[i - 1][j];
            else T[i][j] = max(T[i - 1][j],  values[i - 1] + T[i - 1][j - weights[i - 1]]);
        } 
    }
    // for(int i = 0; i<=values.size(); ++i) print_vector(T[i]);
    return T[values.size()][W];
}

int main(){

    int num_test, N, W;

    vector<int> values;
    vector<int> weights;

    cin >> num_test;

    while(num_test != 0){
        cin >> N;
        cin >> W;

        fill_vector(values, N);
        fill_vector(weights, N);

        cout << solve_01knapsack(weights, values, W) << endl;

        weights.clear();
        values.clear();
        num_test--;
    }

}