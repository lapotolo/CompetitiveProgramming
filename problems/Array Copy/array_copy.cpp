#include <iostream>
#include <vector>
#include <cmath>

#define LEFT(i)     2 * i + 1
#define RIGHT(i)    2 * i + 2
#define PARENT(i) (i - 1) / 2

struct query {
  query(size_t xx, size_t yy, size_t kk) : x(xx), y(yy), k(kk) {} 
  size_t x, y, k;
};

template<typename IntType>
struct segment_tree {
  
  segment_tree(size_t n) : num_leaves(n), leaves_positions(n) { 
    // build the segment tree and save leaves positions.
    // m is the next power of two of n and it's the number of leaves
    // the (left) complete binary tree
    // left-complete binary tree having n leaves
    size_t m = size_t(1) << static_cast<size_t>(ceil(log2(n)));
    // std::cout << "m : " << m << '\n';
    tree.resize(2 * m - 1, IntType(0));
    // std::cout << "tree.size() : " << tree.size() << '\n';


    // first build is called on the range covered by the root.
    // third argument is the root position in the vector tree
    build(0, n - 1, 0);
    // print_leaves();
    // print_tree();
    }

      // debug purposes
  void print_tree() const {
    std::cout << "segment_tree = [";
    for (auto x : tree) {
      std::cout << x << " ";
    }   
    std::cout << "]\n";
  }

  void print_leaves() const {
    std::cout << "leaves_position = [";
    for (auto x : leaves_positions) {
      std::cout << x << " ";
    }   
    std::cout << "]\n";
  }

  struct range {
    range(size_t ll, size_t rr) : l(ll), r(rr) {}
    size_t l, r;
  };

  range root() const { return range(0, num_leaves); }

  void copy(query const& q, size_t query_id) {
    range q_range(q.y, q.y + q.k);
    size_t root_position = 0;
    copy_helper(q_range, root(), root_position, query_id);
  }

  size_t get_query_id(size_t i){
    size_t max_id = 0;
    size_t pos = leaves_positions[i];
    while(true) {
      if(tree[pos] > max_id) max_id = tree[pos];
      if(pos == 0) break;
      pos = PARENT(pos);
    }
    // std::cout << "max : " << max_id << '\n';
    return max_id;
  }

private:
  size_t num_leaves;
  std::vector<size_t> leaves_positions;
  std::vector<IntType> tree;

  void build(size_t low, size_t high, size_t pos) {
    if (low == high) {
      leaves_positions[low] = pos;
      return;
    }

    size_t mid = (low + high) / 2;
    build(low, mid, LEFT(pos));
    build(mid + 1, high, RIGHT(pos));
    // we should tree[pos_in_tree]=0 but it's that by default;
  }

  void copy_helper(range const& qrange, range nrange, size_t pos, size_t q_id) {
    // std::cout << "node_range = " << nrange.l << ", " << nrange.r << std::endl;
    // std::cout << "query_range = " << qrange.l << ", " << qrange.r << std::endl;
    // std::cout << "pos = " << pos << std::endl << "**********************************\n";
    
    // total-overlap do stuff now
    if (qrange.l <= nrange.l and qrange.r >= nrange.r) {
      tree[pos] = q_id; // annotate current query id but dont stop going deeper if u are not in a leaf
      if (nrange.l == nrange.r) return; // leaf reached
    }

    // no-overlap
    if (qrange.l > nrange.r or qrange.r < nrange.l) return;

    // partial overlap so split goin left and right subtrees
    size_t mid = (nrange.l + nrange.r) / 2;
    copy_helper(qrange, {nrange.l, mid}, LEFT(pos), q_id);
    copy_helper(qrange, {mid + 1, nrange.r}, RIGHT(pos), q_id);
  }
};



int main() {

  std::ios_base::sync_with_stdio(false);

  std::vector<int> A; // copy source
  std::vector<int> B; // copy dest
  std::vector<query> queries;

  uint64_t N = 0, M = 0;
  std::cin >> N >> M;

  queries.reserve(M);
  A.reserve(N);
  B.reserve(N);

  for(size_t i = 0; i < N; ++i) std::cin >> A[i];
  for(size_t i = 0; i < N; ++i) std::cin >> B[i];

  // segment_tree<int_type>
  segment_tree<int> seg_tree(N);

  int q_type, x, y, k, i;

  while(M > 0) {
    std::cin >> q_type;
    
    if (q_type == 1) {
      std::cin >> x >> y >> k;
      queries.emplace_back(x, y, k);
      seg_tree.copy(queries.back(), queries.size());
      //seg_tree.print_tree();
    }
    else if (q_type == 2) {
      std::cin >> i;
      size_t query_id = seg_tree.get_query_id(i);
      if(query_id == 0) std::cout << B[i] << '\n'; // if query_id is 0 then It means no copies have been called on that position so we return B[i] as it is 
      else {
        auto q = queries[query_id-1]; // decrements because of 0-indexing
        std::cout << A[i - q.y + q.x] << '\n';
      }
    }
    M--;
  }

  return 0;
}
