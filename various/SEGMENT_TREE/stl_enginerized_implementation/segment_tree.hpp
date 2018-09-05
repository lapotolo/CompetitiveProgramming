#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

#define LEFT(i)     2 * i + 1
#define RIGHT(i)    2 * i + 2
#define PARENT(i) (i - 1) / 2

template<typename IntType, typename BinaryFunct>
struct segment_tree {

    struct type_traits {
        IntType invalid;
        BinaryFunct funct;
    };

    struct range {
        range(size_t l, size_t h)
                : lo(l), hi(h)
        {}

        size_t lo, hi;
    };

    segment_tree(std::vector<IntType> const& leaves, type_traits traits)
            : m_traits(traits)
    {
        num_leaves = leaves.size();
        size_t m = size_t(1) << static_cast<size_t>(ceil(log2(num_leaves)));
        tree.resize(2 * m - 1, m_traits.invalid);
        build(leaves, 0, num_leaves-1, 0);

    }



    range root_segment() const {
        return range(0, num_leaves-1);
    }

    IntType rmq(range const& query, range node_segment, size_t pos) {

        if (query.lo <= node_segment.lo
            and query.hi >= node_segment.hi) { // total overlap
            return tree[pos];
        }
        if (query.lo > node_segment.hi
            or  query.hi < node_segment.lo) { // no overlap
            return m_traits.invalid;
        }

        // partial overlap
        size_t mid = (node_segment.lo + node_segment.hi) / 2;
        return m_traits.funct(
                rmq(query, {node_segment.lo, mid}, LEFT(pos)),
                rmq(query, {mid + 1, node_segment.hi}, RIGHT(pos))
        );
    }

    // increment the i-th leaf by delta
    void update(size_t i, IntType delta, range node_segment, size_t pos) {

        if (i > node_segment.hi
            or  i < node_segment.lo) {
            return;
        }

        if (node_segment.lo == node_segment.hi) { // leaf
            tree[pos] += delta;
            return;
        }

        size_t mid = (node_segment.lo + node_segment.hi) / 2;
        update(i, delta, {node_segment.lo, mid}, LEFT(pos));
        update(i, delta, {mid + 1, node_segment.hi}, RIGHT(pos));
        tree[pos] = m_traits.funct(tree[LEFT(pos)], tree[RIGHT(pos)]);
    }

    // increment all leaves in the range [query.lo, query.hi] by delta
    void update_range(range const& query, IntType delta, range node_segment, size_t pos) {

        if (query.lo > node_segment.hi
            or  query.hi < node_segment.lo) {
            return;
        }

        if (node_segment.lo == node_segment.hi) { // leaf
            tree[pos] += delta;
            return;
        }

        size_t mid = (node_segment.lo + node_segment.hi) / 2;
        update_range(query, delta, {node_segment.lo, mid}, LEFT(pos));
        update_range(query, delta, {mid + 1, node_segment.hi}, RIGHT(pos));
        tree[pos] = m_traits.funct(tree[LEFT(pos)], tree[RIGHT(pos)]);
    }

private:
    type_traits m_traits;
    size_t num_leaves;
    std::vector<IntType> tree;

    void build(std::vector<IntType> const& leaves, size_t low, size_t high, size_t pos) {
        if (low == high) {
            tree[pos] = leaves[low];
            return;
        }
        size_t mid = (low + high) / 2;
        build(leaves, low, mid, LEFT(pos));
        build(leaves, mid + 1, high, RIGHT(pos));
        tree[pos] = m_traits.funct(tree[LEFT(pos)],tree[RIGHT(pos)]);
    }
};
