#include <iostream>
#include <vector>
#include <algorithm>
#include "myBIT.hpp"

using namespace std;

// trasform the input array into a rank of element array
// i.e. remap({44, 2, 5, 9}) )= {3, 0, 1, 2} 
template<typename T>
size_t remap(std::vector<T>& v) {

    // make a copy of v in temp
    std::vector<T> temp(v);

    std::sort(temp.begin(), temp.end());

    // count the num of distinct element of temp
    // unique returns an iterator .end() to the 
    // new sequence without duplicates
    auto sz = (size_t) std::distance(temp.begin(),
                                     std::unique(temp.begin(), temp.end()));
    temp.resize(sz);

    for (auto& x : v)
        x = std::distance(temp.begin(),
                          std::lower_bound(temp.begin(), temp.end(), x));
    return sz;
}


int main(){
    int n;
    int64_t result = 0;
    cin >> n;
    vector<int> input;
    input.reserve(n);
    BIT<int> bit(n);

    vector<int> suffix_sum(n);


    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        input.push_back(x);

    }

    auto counter_size = remap(input);
    vector<int> counter(counter_size);

    for (int i = 0; i < bit.B.size(); ++i) std::cout << bit.B[i] << " ";
    std::cout << std::endl;

    for(int i = n-1; i >= 0; --i){
        counter[input[i]]++; // count num of occurrences of element input[i]
        suffix_sum[i] = counter[input[i]]; // use the counter value to save the suffix sum up to position i
        bit.add(counter[input[i]]-1, 1);
        
        for (int i = 0; i < bit.B.size(); ++i) std::cout << bit.B[i] << " ";
        std::cout << std::endl;

    }
    std::cout << std::endl  << std::endl  << std::endl;
    for (int i = 0; i < input.size(); ++i) std::cout << input[i] << " ";
    std::cout << std::endl;    
    for (int i = 0; i < counter.size(); ++i) std::cout << counter[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < suffix_sum.size(); ++i) std::cout << suffix_sum[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < bit.B.size(); ++i) std::cout << bit.B[i] << " ";
    std::cout << std::endl;

    //suffix_sum[i] == f(i, n, test[i])
    //bit counts the number of equal elements in suffix_sum
    //bit[i] == x -> there are x entries in suffix_sum equal to i

    fill(counter.begin(), counter.end(), 0);;

    for (int i=0; i<n; ++i) {
        bit.add(suffix_sum[i]+1, -1); //we don't consider element i
        counter[input[i]]++; // == f(1, i, test[i])
        result += bit.sum(counter[input[i]]+1);
        cout << result << endl;
        //get number of elements smaller then counter[test[i]]
    }
    std::cout << std::endl;
    cout << result << endl;

    return 0;
}