#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

struct query {
    size_t left;
    size_t right;
    // inline bool operator< (const query& lhs, const query& rhs){ /* do actual comparison */ 
    //     if (a.left/sqn != b.left/sqn)
    //         return a.left/sqn < b.left/sqn;
    //     return (a.right < b.right);
    // }
    // inline bool operator> (const query& lhs, const query& rhs){ return rhs < lhs; }
    // inline bool operator<=(const query& lhs, const query& rhs){ return !(lhs > rhs); }
    // inline bool operator>=(const query& lhs, const query& rhs){ return !(lhs < rhs); }
}

vector<int> solve(    vector<int> const& vec vector<query> const& queries){
    size_t cur_left;
    size_t cur_right;
    for
}

int main() {

    std::ios_base::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;

    size_t sqn = (size_t) (std::sqrt(n) + 1);

    vector<int> test;
    test.reserve(n);

    vector<query> queries;
    queries.reserve(t);
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        test.push_back(x);
    }
    for(int i=0; i<t; ++i){
        int l, r;
        cin >> l >> r;
        queries.push_back({l--, r--});
    }

    std::sort(queries.begin(), queries.end(),
          [](query const& a, query const& b) -> bool {
              if (a.left/sqn != b.left/sqn)
                  return a.left/sqn < b.left/sqn;
              return (a.right < b.right);
          });

    solve(test, queries);

    return 0;
}