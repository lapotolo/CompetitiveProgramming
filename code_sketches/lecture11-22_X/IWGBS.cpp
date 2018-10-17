// Fibonacci sequence!
//                    S
//              /           \
//             0              1         |-> 2
//               \          /   \
//                1        0     1      |-> 3
//               / \        \   / \
//              0   1        1 0   1    |-> 5 



// v_1  9 8
// v_2  4 4 1

// v_i  3 3 2

#include <iostream>
#include <vector>

using namespace std;

void generate_fibonacci_sequence(vector<vector<int>>& v) {
    size_t j;
    v[0].emplace_back(0);
    v[1].emplace_back(2);
    v[2].emplace_back(3);

    for (size_t n = 3; n <= v.size()-1; ++n) {
        int carry = 0;
        j = 0;
        auto v1 = v[n-2];
        auto v2 = v[n-1];

        while(j < v1.size()){
            int sum = v1[j] + v2[j] + carry;
            if (sum > 9) {
                v[n].emplace_back(sum % 10);
                carry = sum / 10;
            } else {
                v[n].emplace_back(sum);
                carry = 0;
            }
            ++j;
        }
        while (j < v2.size()) {
            int sum = v2[j] + carry;
            if (sum > 9) {
                v[n].emplace_back(sum % 10);
                carry = sum / 10;
            } else {
                v[n].emplace_back(sum);
                carry = 0;
            }
            ++j;
        }
        if (carry > 0) v[n].emplace_back(carry);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int num_digits;
    cin >> num_digits;

    vector<vector<int>> fibonacci_seq(num_digits+1, vector<int>());
    generate_fibonacci_sequence(fibonacci_seq);

    // we need to print in reverse order!
    for (auto it = fibonacci_seq[num_digits].rbegin(); it != fibonacci_seq[num_digits].rend(); ++it) 
        cout << *it;
    cout << endl;

    return 0;
}