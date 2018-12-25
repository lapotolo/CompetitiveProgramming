#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include "fen.hpp"

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    size_t num_elem;
    cin >> num_elem;
    vector<int> input;
    input.reserve(num_elem);

    for(int i = 0; i < num_elem; ++i){
        int x;
        cin >> x;
        input.push_back(x);
    }

    vector<int> greater;
    vector<int> less;

    greater.reserve(num_elem);
    less.reserve(num_elem);
    for(int j = 1; j < num_elem; ++j) {
        for(int i = 0; i < j; ++i) {
            if(input[j] > input[i]){
                less[j]++;
            }
        }
        for(int k = j+1; k < num_elem; ++k){
            if(input[j] < input[k]){
                greater[j]++;
            }
        }
    }
    uint64_t answer = 0;
    for(int i = 0; i < num_elem; ++i){
        answer += greater[i]*less[i];
    }
    cout << answer << endl;
    return 0;
}
