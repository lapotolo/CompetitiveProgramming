#include <iostream>
#include <vector>
#include <limits>
#include <chrono>

#include "segment.hpp"

template<typename IntType>
struct range_min_query_operator {
    IntType operator()(IntType x, IntType y) {
        return std::min<IntType>(x, y);
    }
};

template<typename IntType>
struct range_max_query_operator {
    IntType operator()(IntType x, IntType y) {
        return std::max<IntType>(x, y);
    }
};


int main() {

    std::ios_base::sync_with_stdio(false);

    uint64_t n = 0; // number of leaves in the tree
    std::cin >> n;

    // typedef std::chrono::high_resolution_clock clock_type;

    // auto start = clock_type::now();
    std::vector<int> leaves;
    leaves.reserve(n);
    for (uint64_t i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        leaves.push_back(x);
    }

    typedef rmq_segment_tree<int, range_min_query_operator<int>> segment_tree_type;
    // typedef rmq_segment_tree<int, range_max_query_operator<int>> segment_tree_type;

    segment_tree_type::type_traits traits;
    traits.invalid = std::numeric_limits<int>::max();
    // traits.invalid = std::numeric_limits<int>::min();

    segment_tree_type segtree(leaves, traits);


}
