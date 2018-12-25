/*
BIT is implemented using an array and works in form of trees. 

    The sum operation where parent of index x is "x - (x & -x)".
    The update operation where parent of index x is "x + (x & -x)".
*/

#include <vector>
#include <iostream>

using namespace std; 

template<class T>
struct BIT{
    vector<T> B;

    BIT(size_t size) : B(size+1) {}

    BIT(vector<T> a) : B(a.size()+1){
        B[0] = 0; // dummy root node
        for (int i = 0; i < a.size(); ++i){
            add(i, a[i]);
        }
    }

    // B[k] = B[k] + val  for k = i , i = i + (i&(-i)), ... , B.size()
    void add(int i, T val){
        i += 1;
        while(i<= B.size()){
            B[i] += val;
            i = i + (i & (-i));
        }
    }

    //sum from B[0] + B[1] + ... + B[i] (inclusive)
    // we need parent(i) = i - (k) ie: remove rightmost bit of i
    // where k = (i & (-1)) is the rightmost bit of i
    T sum(int i){
        T s = 0;
        i += 1; // indexes shifted by one cause of the dummy root
        while(i > 0){
            s += B[i];
            i = i - (i & (-i));
        }
        return s;
    }

};
