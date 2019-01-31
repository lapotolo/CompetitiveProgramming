#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <cmath>

#define LEFT(i)     2 * i + 1
#define RIGHT(i)    2 * i + 2
#define PARENT(i) (i - 1) / 2

using namespace std;

struct query {
    query(size_t xx, size_t yy,size_t kk)
            : x(xx)
            , y(yy)
            , k(kk)
    {}

    size_t x, y, k;
};

template<typename IntType>
struct segment_tree {
  
  segment_tree(size_t n) :
    num_leaves(n),
    leaves_positions(n) {
    // build the segment tree and save leaves positions
    // m is the next power of two of n and it's the size of the
    // left-complete binary tree having n leaves
      size_t m = size_t(1) << static_cast<size_t>(ceil(log2(n)));
        tree.resize(2 * m - 1, IntType(0));
        // cout << "m = " << m << endl;
        // cout << "tree.size() = " << tree.size() << endl;
        
        // first build is called on the range covered by the root.
        // third argument is the root position in the vector tree
        build(0, n - 1, 0);
        // cout << "SEGMENT TREE BUILT!" << endl;
  }
  
    struct range {
      range(size_t l, size_t h) : r_low(l), r_high(h) {}
      
        size_t r_low, r_high;
    };

  void copy(query const &q, size_t query_id) {
    range q_range(q.y, q.y + q.k);
        range root_range(0, num_leaves); // why not num_leaves - 1
        size_t root_position = 0;
        copy_helper(q_range, root_range, root_position, query_id);
    }

  size_t get_query_id(size_t i){
    size_t max_id = 0;
    size_t pos_in_tree = leaves_positions[i];
    bool in_root = false;
        while(!in_root){
          if(tree[pos_in_tree] > max_id)
            max_id = tree[pos_in_tree];
          if(pos_in_tree == 0)
            in_root = true;
          pos_in_tree = PARENT(pos_in_tree);
        }
        // cout << "max_id = " << max_id << endl;
        return max_id;
    }
  
  void print_tree() const {
        cout << "segment_tree = [";
        for (auto x : tree) {
          std::cout << x << " ";
        }   std::cout << "]\n";
  }
  void print_leaves() const {
    cout << "leaves_position = [";
    for (auto x : leaves_positions) {
      std::cout << x << " ";
    }   
    std::cout << "]\n";
  }
  
  
private:
  size_t num_leaves;
  vector<size_t> leaves_positions;
  vector<IntType> tree;
  
    void build(size_t low, size_t high, size_t pos_in_tree) {
      if (low == high) {
        leaves_positions[low] = pos_in_tree;
        //tree[pos_in_tree] = low;
            return;
      }
        size_t mid = (low + high) / 2;
        build(low, mid, LEFT(pos_in_tree));
        build(mid + 1, high, RIGHT(pos_in_tree));
        // at this point
        // we should tree[pos_in_tree]=0 but it's that by default;
    }
  
  void copy_helper(range const &query_range, range node_range, size_t pos, size_t query_id) {
    // std::cout << "node_range = " << node_range.r_low << ", " << node_range.r_high << std::endl;
        // std::cout << "query_range = " << query_range.r_low << ", " << query_range.r_high << std::endl;
        // std::cout << "pos = " << pos << std::endl;
        // REMEMBER the three overlapping
    
        // total-overlap do stuff now
        if (query_range.r_low <= node_range.r_low
            and query_range.r_high >= node_range.r_high) {
          // std::cout << "TotalOverlap, pos =  "<< pos << std::endl;
          // std::cout << "tree[" << pos << "] = " << query_id << "\n\n";

          
          tree[pos] = query_id;
          if (node_range.r_low == node_range.r_high)
            return;
        }
        
        // no-overlap
        if (query_range.r_low > node_range.r_high
            or  query_range.r_high < node_range.r_low)
            return;
        
        // partial overlap so split goin left and right subtrees
        size_t mid = (node_range.r_low + node_range.r_high) / 2;
        copy_helper(query_range, {node_range.r_low, mid}, LEFT(pos), query_id);
        copy_helper(query_range, {mid + 1, node_range.r_high}, RIGHT(pos), query_id);

  }
};

void fill_vector(vector<int> & v, int len){
  int x;
  v.reserve(len);
  for(int i = 0; i < len; ++i){
    cin >> x;
    v.push_back(x);
  }
}


int main() {
  
  std::ios_base::sync_with_stdio(false);
  // typedef int int_type;
  
  
  vector<int> source_vector;
  vector<int> dest_vector;
  vector<query> queries;

  uint64_t n = 0, num_queries = 0;
  cin >> n >> num_queries;
  
  queries.reserve(num_queries);
  
  fill_vector(source_vector, n);
  fill_vector(dest_vector, n);
  
  // segment_tree<int_type>
  segment_tree<int> seg_tree(n);
  seg_tree.print_tree();
  seg_tree.print_leaves();
  
  int q_type;
  while(num_queries > 0){
    cin >> q_type;
    if (q_type == 1){
      int x, y, k;
      cin >> x >> y >> k;
      queries.emplace_back(x, y, k);
      // cout << queries[0].x << ", " << queries[0].y << ", " << queries[0].k << endl;
      // cout << queries.back().x << ", " << queries.back().y << ", " << queries.back().k << endl;
      seg_tree.copy(queries.back(), queries.size());
      // seg_tree.print_tree();
    }
    else if (q_type == 2){
      int i;
      cin >> i;
      size_t query_id = seg_tree.get_query_id(i);
      if(query_id == 0)
        cout << dest_vector[i] << endl;
      else{
        auto q = queries[query_id-1];
        cout << source_vector[i - q.y + q.x] << endl;
      }
    }
    else {
      cerr << "bad query type" << endl;
      return 1;
    }
    num_queries--;
  }
  return 0;
}
