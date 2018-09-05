/*
Problem: http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

Description:


Time cost = 
Space cost = 

*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;



pair<vector<int>, int> get_input_sequence(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> t(n);
    for(int i = 0; i < n; ++i){
        cin >> t[i];
    }
    return make_pair(t, k);
}

vector<int> sliding_window(vector<int> const& seq, int k){
    deque<pair<int, int>> deq; // first <- value, second <- position
    vector<int> maxs(seq.size() - k + 1);

    for (int i = 0 ; i < seq.size(); ++i){
        
        // Removes elements no longer in the window i.e
        //
        while (!deq.empty() and deq.front().second <= i - k){
            deq.pop_front();
        }
        
        // Removes from back elements which are no longer useful, i.e., no greater than the current element
        while (!deq.empty() and deq.back().first <= seq[i]){
            deq.pop_back();
        }
        deq.push_back(make_pair(seq[i], i));
        
        if (i >= k - 1){
            maxs.push_back(deq.front().first);
        }
    }
    return maxs;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int test_cases = 0;
    cin >> test_cases;
    vector<pair<vector<int>, int>> tests(test_cases);
    vector<int> result;

    for (int i = 0; i < test_cases; ++i){
        tests[i] = get_input_sequence();
    }

    for (auto const& t : tests) {
        result.clear();
        result = sliding_window(t.first, t.second);
        for (auto e : result) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}