// author: Lapo Toloni
// problem: https://practice.geeksforgeeks.org/problems/next-larger-element/0

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>    // std::for_each

using namespace std;

// O(n + n) 
vector<int> compute_next_larger_array(vector<int> const& vec){
    vector<int> result;
    result.reserve(vec.size());
    stack<int> s;
    int next_greater_element;
    bool found = false;
    for(int i = vec.size()-1; i >= 0; --i){
        next_greater_element = -1;
        while(!s.empty() and !found){
            if(s.top() > vec[i]){
                next_greater_element = s.top(); 
                found = true;
            }
            else s.pop();
        }
        result.push_back(next_greater_element);
        s.push(vec[i]);
        found = false;
    }
    return result;
}


int main(){
    int input_num, length, num_test_cases = 0;
    cin >> num_test_cases;

    vector<int> vec;

    while(num_test_cases > 0){
        cin >> length;
        vec.reserve(length);
        for (int j = 0; j < length; ++j){
            cin >> input_num;
            vec.push_back(input_num);
        }

        auto result = compute_next_larger_array(vec);
        
        for_each(result.rbegin(),result.rend(),
            [](int el){
                cout << el << " ";
            });
        cout << endl;
        vec.clear();
        num_test_cases--;
    }
    return 0;
}
