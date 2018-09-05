//
// Sparse Table for Range Minimum Query
//
// Description:
//   The sparse table stores
//     table[h][i] = min(x[i], ..., x[i+2^h-1])
//   to solve
//     RMQ(i,j) = min { x[i], ..., x[j-1] }.
//
// Algorithm:
//   table[h+1][i] = min(table[h][i], table[h][i+2^h]).
//   RMQ(i,j) = min(table[h][i], table[h][j-2^h-1].
//
// Complexity:
//   O(n log n) for construction,
//   O(1) for query.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

#define all(iterable) ((iterable).begin()), ((iterable).end())

template <class T>
struct sparse_table {

    vector<T> const& x;
    vector<vector<int>> table;

    int argmin(int i, int j) { return x[i] < x[j] ? i : j; }

    sparse_table(const vector<T> &x) : x(x) {
        int logn = (sizeof(int)*__CHAR_BIT__) - 1 - __builtin_clz(x.size());
        table.assign(logn+1, vector<int>(x.size()));
        iota(all(table[0]), 0);

        
        for (int h = 0; h+1 <= logn; ++h)
            for (int i = 0; i+(1<<h) < x.size(); ++i)
                table[h+1][i] = argmin(table[h][i], table[h][i+(1<<h)]);
    }

    // = min x[i,j)
    T range_min(int i, int j) {
        int h = sizeof(int)*__CHAR_BIT__-1-__builtin_clz(j-i); // = log2 of range size
        return x[argmin(table[h][i], table[h][j-(1<<h)])];
    }

    void print_elements(){ for(T el : x) cout << el << " "; cout << endl;}
};

int main() {
    vector<int> a = {1,3,4,8,6,1,4,2};
    int n = a.size();
    sparse_table<int> ST(a);
    ST.print_elements();

    // cout << ST.range_min(1,6);

    // try all possible RMQs
    // for (int i = 0; i < n; ++i) {
    //     for (int j = i+1; j <= n; ++j) {
    //         cout << "RMQ(" << i << ", " << j-1 << ") = "<< ST.range_min(i, j) << endl;
    //     }
    //     cout << endl;
    // }
}
