#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> & vec){
    for(auto element : vec){
        cout << element << " ";
    }
    cout << endl;
}

void fill_vector(vector<int> & vec, size_t n) {
    int x;
    vec.reserve(n);
    for(size_t i = 0; i < n; ++i){
        cin >> x;
        vec.push_back(x);
    }   
}

int solve_01knapsack(vector<int> & weights, vector<int> & values, int W){ // O(nW)
    print_vector(weights);
    print_vector(values);

    vector<vector<int>> T(values.size()+1, vector<int>(W+1, 0));
    for(int j = 0; j <= W; ++j) T[0][j] = 0; // fill first row with zero cause we cant take any item with W=0
    for (int i = 1; i <= values.size(); ++i){
        for (int j = 0; j <= W; ++j){ // j here represents all the possible W from 0 to W
            // if the i-th item does not fit the current weight j
            // copy the value chose for the suboptimal solution w/ this new item (look one cell up ie T[i-1][j])
            if (j < weights[i-1]) T[i][j] = T[i-1][j]; 
            // otherwise take the max between the last suboptimal solution (stored in T[i - 1][j])
            // and the solution given by choosing the new item (ie values[i-1])
            // plus the value given by the optimal solution for the remaining capacity (ie T[i - 1][j - weights[i - 1]])
            else T[i][j] = max(T[i - 1][j],  values[i - 1] + T[i - 1][j - weights[i - 1]]);
        } 
    }
    // uncomment to print the table
    // for(int i = 0; i<=values.size(); ++i) print_vector(T[i]);
    return T[values.size()][W]; // the solution is stored in the bottom right corner of the table
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