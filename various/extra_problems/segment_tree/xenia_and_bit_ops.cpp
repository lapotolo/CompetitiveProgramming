// Author: Lapo Toloni
// problem: http://codeforces.com/contest/339/problem/D

#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <cmath>

#define LEFT(i)     2 * i + 1
#define RIGHT(i)    2 * i + 2
#define PARENT(i) (i - 1) / 2

#define OR 1
#define XOR 0


using namespace std;

template<typename IntType>
struct segment_tree {

    segment_tree(vector<int> input) :
            leaves(input) {
        num_leaves = input.size();
        size_t m = size_t(1) << static_cast<size_t>(ceil(log2(num_leaves)));
        height = static_cast<size_t>(ceil(log2(m)));
        tree.resize(2 * m - 1, -1);
        first_op = (height % 2 == 1) ? OR : XOR;
        build(0, num_leaves - 1, 0, first_op);
        // print_tree();
        // print_leaves();
    }

    int get_root_value() const { return tree[0]; }

    void print_tree() const {
        cout << "segment_tree = [";
        for (auto x : tree) {
            std::cout << x << " ";
        }
        std::cout << "]\n";
    }

    void print_leaves() const {
        cout << "leaves = [";
        for (auto x : leaves) {
            std::cout << x << " ";
        }
        std::cout << "]\n";
    }

    void update(size_t p, int b) {
        // if(first_op) cout << "OR" << endl;
        // else cout << "XOR" << endl;
        update(p-1, b, 0, num_leaves - 1, 0, first_op);
    }


private:
    size_t num_leaves;
    size_t height;
    int first_op;
    vector<int> leaves;
    vector<int> tree;

    void build(size_t low, size_t high, size_t pos_in_tree, size_t operation) {
        if (low == high) {
            tree[pos_in_tree] = leaves[low];
            return;
        }
        size_t mid = (low + high) / 2;
        build(low, mid, LEFT(pos_in_tree), (1 ^ operation));
        build(mid + 1, high, RIGHT(pos_in_tree), (1 ^ operation));

        tree[pos_in_tree] = apply(operation, tree[LEFT(pos_in_tree)], tree[RIGHT(pos_in_tree)]);
    }

    int apply(size_t op, size_t first, size_t second) {
        if (op) return first | second; // op == OR=1
        return first ^ second; // // op == XOR=0
    }

    // it's a single point update!
    void update(size_t leaf, int value, size_t node_lo, size_t node_hi, size_t pos_in_tree, int operation) {
        if (leaf < node_lo or leaf > node_hi) { // overlap
            return;
        }
        if (node_hi == node_lo) { // we are in a leaf
            tree[pos_in_tree] = value;
            return;
        }
        int mid = (node_lo + node_hi) / 2;
        update(leaf, value, node_lo, mid, LEFT(pos_in_tree), (1 ^ operation));
        update(leaf, value, mid + 1, node_hi, RIGHT(pos_in_tree), (1 ^ operation));
        tree[pos_in_tree] = apply(operation, tree[LEFT(pos_in_tree)], tree[RIGHT(pos_in_tree)]);

    }
};

void fill_vector(vector<int> &v, int len) {
    int x;
    v.reserve(len);
    for (int i = 0; i < len; ++i) {
        cin >> x;
        v.push_back(x);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);


    int n = 0, m = 0;
    cin >> n >> m;

    vector<int> input;
    int num_elem = 1 << n;
    fill_vector(input, num_elem);

    // for (auto el : input) cout << el << " ";
    // cout << endl;

    segment_tree<int> tree(input);

    int p, b;
    while (m > 0) {
        cin >> p >> b;
        // cout << "p = " << p << ", b = " << b << endl;
        tree.update(p, b);
        // cout << "after update" << endl;
        // tree.print_tree();
        cout << tree.get_root_value() << endl;
        m--;
    }
    return 0;
}
