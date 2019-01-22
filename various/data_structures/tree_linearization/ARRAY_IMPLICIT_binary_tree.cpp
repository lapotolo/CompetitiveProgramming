#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

#define LEFT_CHILD(i)     2 * i + 1
#define RIGHT_CHILD(i)    2 * i + 2
#define PARENT(i) (i - 1) / 2


using namespace std;


int main() {

    std::ios_base::sync_with_stdio(false);

    vector<int> tree;
    vector<int> input_array({5,3,1,2,0});
    //int n = input_array.size();
    int n = 0;
    std::cin >> n;

    int tree_size = 2 * n - 1;
    tree.resize(tree_size);

    int h = ceil(log2(n));

    // left-most internal node id
    int left_most_node = (int(1) << (h - 1)) - 1;
    int offset = LEFT_CHILD(left_most_node);


    cout << "leftmost tree node = "<< left_most_node << endl;
    cout << "offset = "<< offset << endl;
    // set leaves circularly

    // 1. go forward
    int i = 0;
    for (int j = offset; j != tree_size; ++i, ++j) {
        int x = 0;
        std::cin >> x;
        tree[j] = x;
    }

    // 2. fall back
    for (int j = 0; i != n; ++i, ++j) {
        int x = 0;
        std::cin >> x;
        tree[n - 1 + j] = x;
    }

    // set internal nodes
    for (int i = tree_size - 1; i != 0; i -= 2) {
        int min = std::min<int>(tree[i], tree[i - 1]);
        tree[PARENT(i)] = min;
    }

    for(int el : tree) cout << el << " ";
    cout << endl;
}