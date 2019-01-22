// LAZY PROPAGATION IS BUGGED

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

#define LEFT_CHILD(i)     (2 * i + 1)
#define RIGHT_CHILD(i)    (2 * i + 2)
#define PARENT(i) (i - 1) / 2


using namespace std;


// this one does not build a complete binary tree
void build_tree_iterative (vector<int> const& input_array, vector<int> & segtree) {

    int n = input_array.size();
    int tree_size = segtree.size();
    int h = ceil(log2(n));

    // left-most internal node id
    int left_most_node = (int(1) << (h - 1)) - 1;
    int offset = LEFT_CHILD(left_most_node);

    // set leaves circularly
    // 1. go forward
    int i = 0;
    for (int j = offset; j != tree_size; ++i, ++j) {
        segtree[j] = input_array[i];
    }

    // 2. fall back
    for (int j = 0; i != n; ++i, ++j) {
        segtree[n - 1 + j] = input_array[i];
    }
    // set internal nodes
    for (int i = tree_size - 1; i != 0; i -= 2) {
        segtree[PARENT(i)] = min<int>(segtree[i], segtree[i - 1]);
    }
}

void build_tree_rec(vector<int> const& input, vector<int> &segtree, int low, int high, int pos){
    if(low == high) {
        segtree[pos] = input[low];
        return;
    }
    int mid = (low + high) / 2;
    build_tree_rec(input, segtree, low, mid, LEFT_CHILD(pos));
    build_tree_rec(input, segtree, mid+1, high, RIGHT_CHILD(pos));
    segtree[pos] = min<int>(segtree[LEFT_CHILD(pos)], segtree[RIGHT_CHILD(pos)]);
}

void update_lazy(vector<int>& segtree, vector<int>& lazytree, int low, int high, int pos) {
    segtree[pos] += lazytree[pos];
    if (low != high) { //not a leaf node
        lazytree[LEFT_CHILD(pos)] += lazytree[pos];
        lazytree[RIGHT_CHILD(pos)] += lazytree[pos];
    }
    lazytree[pos] = 0;
}

void update(vector<int>& segtree, vector<int>& lazytree, int low, int high, int index) {
    update_lazy(segtree, lazytree, low, high, index);
    if (LEFT_CHILD(index) < segtree.size()) {
        update_lazy(segtree, lazytree, low, high, LEFT_CHILD(index));
        segtree[index] = segtree[LEFT_CHILD(index)];
    }
    if (RIGHT_CHILD(index) < segtree.size()) {
        update_lazy(segtree, lazytree, low, high, RIGHT_CHILD(index));
        segtree[index] = min<int>(segtree[index], segtree[RIGHT_CHILD(index)]);
    }
}

void increment(vector<int> & segtree, vector<int> & lazytree, int q_low, int q_high, int low, int high, int pos, int delta){
    if(pos >= segtree.size()) return;

    if(low > high) return;

    if (lazytree[pos] != 0) update_lazy(segtree, lazytree, low, high, pos);

    if(q_low > high or q_high < low) return; // no overlap

    if(q_low <= low and q_high >= high){ // total overlap
        segtree[pos] += delta;
        if(low != high){ // pos is not a leaf so we need to store in lazytree updates to be done
            if(LEFT_CHILD(pos) < segtree.size()) lazytree[LEFT_CHILD(pos)] += delta;
            if(RIGHT_CHILD(pos) < segtree.size()) lazytree[RIGHT_CHILD(pos)] += delta;
        }
        //update parents
        int i = pos;
        while (i != 0) {
            update(segtree, lazytree, low, high, PARENT(i));
            i = PARENT(i);
        }
    } else { // otherwise partial overlap
        int mid = (low + high) / 2;
        increment(segtree, lazytree, q_low, q_high, low, mid, LEFT_CHILD(pos), delta);
        increment(segtree, lazytree, q_low, q_high, mid+1, high, RIGHT_CHILD(pos), delta);
    }
}



int answer_RMQ_lazy(vector<int>& segtree, vector<int>& lazytree, int q_low, int q_high, int low, int high, int pos){
    //make sure all propagation is done at pos. If not update tree
    //at pos and mark its children for lazy propagation.
    if (lazytree[pos] != 0) update_lazy(segtree, lazytree, low, high, pos);
    // from here normal RMQ
    if(q_low <= low and q_high >= high) return segtree[pos]; // total overlap
    if(q_low > high or q_high < low) return numeric_limits<int>::max(); // no overlap
    int mid = (low + high) / 2;
    return min<int>(answer_RMQ_lazy(segtree, lazytree, q_low, q_high, low, mid, LEFT_CHILD(pos)),
                    answer_RMQ_lazy(segtree, lazytree, q_low, q_high, mid+1, high, RIGHT_CHILD(pos)));
}

int main() {
    std::ios_base::sync_with_stdio(false);

    vector<int> input({-1,2,4,1,7,1,3,4});
    int n = input.size();
    int low = 0, high = n - 1;  // range covered by the root node
    int qlow = 3, qhigh = 5;


    int m = 1 << int(ceil(log2(n))); //  round up to the next power of two of n
    int rec_tree_size = (2*m) - 1;
    vector<int> segtree_rec(rec_tree_size, numeric_limits<int>::max());
    build_tree_rec(input, segtree_rec, 0, high, 0);

    // ******** seqtree_rec printing for debug purposes ***********************
    cout << "input.size() = " << n << endl << endl;
    cout << "Recursively-built segtree printings:\n";
    cout << "input = [ ";
    for(int i = 0; i < input.size(); ++i) cout << input[i] << " ";
    cout << "]\nnum_tree_nodes = (2*m) - 1 = " << segtree_rec.size() << "\nsegtree_rec = [ ";
    for(int i = 0; i < rec_tree_size; ++i){
        if(segtree_rec[i] == numeric_limits<int>::max()) cout << "M ";
        else cout << segtree_rec[i] << " ";
    }
    cout << "]" << endl;

    vector<int> lazytree_rec(rec_tree_size);
    int test_rmq_rec = answer_RMQ_lazy(segtree_rec, lazytree_rec, qlow, qhigh, low, high, 0);
    cout << "RMQ(" << qlow << ", " << qhigh << ") = " << test_rmq_rec << endl;


    increment(segtree_rec, lazytree_rec, 0, 0, low, high, 0, 1 );


    // ******** post increment printing ***********************
    cout << "***************** AFTER INCREMENTS *******************\n";
    cout << "segtree = [ ";
    for(int i = 0; i < rec_tree_size; ++i){
        if(segtree_rec[i] == numeric_limits<int>::max()) cout << "M ";
        else cout << segtree_rec[i] << " ";
    }
    cout << "]" << endl;

    int test_rmq_rec_post_inc = answer_RMQ_lazy(segtree_rec, lazytree_rec, qlow, qhigh, low, high, 0);
    cout << "RMQ(" << qlow << ", " << qhigh << ") = " << test_rmq_rec_post_inc << endl;


    cout << "\n\n************************************************************************";
    cout << "\n************************ ITERATIVE PART  *******************************";
    cout << "\n************************************************************************\n\n";

    int iter_tree_size = 2 * n - 1;
    vector<int> segtree_iter(iter_tree_size, numeric_limits<int>::max());
    build_tree_iterative(input, segtree_iter);


    // ******** seqtree_iter printing for debug purposes ***********************
    cout << "Iteratively-built segtree printings: \n";
    cout << "num_tree_nodes = (2*n) - 1 = " << segtree_iter.size() << endl;
    cout << "segtree_iter = [ ";
    for(int i = 0; i< segtree_iter.size(); ++i){
        cout << segtree_iter[i] << " ";
    }
    cout << "]" << endl;

    vector<int> lazytree_iter(iter_tree_size);
    int test_rmq_iter = answer_RMQ_lazy(segtree_iter, lazytree_iter, qlow, qhigh, low, high, 0);
    cout << "RMQ(" << qlow << ", " << qhigh << ") = " << test_rmq_iter << endl;

    increment(segtree_iter, lazytree_iter, 0, 0, low, high, 0, 1 );


    // ******** post increment printing ***********************
    cout << "***************** AFTER INCREMENTS *******************\n";
    cout << "segtree = [ ";
    for(int i = 0; i < rec_tree_size; ++i){
        if(segtree_rec[i] == numeric_limits<int>::max()) cout << "M ";
        else cout << segtree_rec[i] << " ";
    }
    cout << "]" << endl;

    int test_rmq_iter_post_inc = answer_RMQ_lazy(segtree_rec, lazytree_rec, qlow, qhigh, low, high, 0);
    cout << "RMQ(" << qlow << ", " << qhigh << ") = " << test_rmq_iter_post_inc << endl;
}