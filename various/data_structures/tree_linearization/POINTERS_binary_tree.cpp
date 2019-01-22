#include <iostream>
#include <deque>

struct node {
    node(int k,
         node* l = nullptr,
         node* r = nullptr)
            : key(k), left(l), right(r)
    {}

    int key;
    node* left;
    node* right;
};

uint64_t sum(node* n) {

    if (n == nullptr) {
        return 0;
    }

    uint64_t left_subtree_sum = 0;
    if (n->left != nullptr) {
        left_subtree_sum = sum(n->left);
    }
    uint64_t right_subtree_sum = 0;
    if (n->right != nullptr) {
        right_subtree_sum = sum(n->right);
    }

    return n->key + left_subtree_sum + right_subtree_sum;
}

int main() {

    std::ios_base::sync_with_stdio(false);

    node* root = nullptr;

    {
        std::deque<node *> q;
        int n = 0;
        std::cout << "gimme number of leaves: ";
        std::cin >> n;

        // get input
        for (int i = 0; i < n; ++i) {
            int x = 0;
            std::cin >> x;
            node* node_ptr = new node(x);
            q.push_back(node_ptr);
        }

        node *last = nullptr;
        if (n % 2 != 0) {
            last = q.back();
            q.pop_back();
        }

        // helper function
        auto min_parent = [&](node *left, node *right) {
            int min = std::min<int>(left->key, right->key);
            node *parent = new node(min, left, right);
            q.push_back(parent);
        };

        // build tree topology
        while (q.size() != 1) {
            min_parent(q[0], q[1]);
            q.pop_front();
            q.pop_front();
        }

        if (last != nullptr) { // create a new root node with
            // the old root as left child
            // and the last node as right child
            min_parent(q.front(), last);
            q.pop_front();
        }

        root = q.front();
    }
}