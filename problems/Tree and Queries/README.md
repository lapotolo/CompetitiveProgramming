# Tree and queries
Problem: 

### Description:
We start by doing a Preorder traversal of the given tree to flatten it.

For every node the discovery time and the finishing time corresponds respectively to the start and to the end of its rooted subtree.

The tree flattening is useful in order to be able to process subtree queries as range queries on an array.

To get the required performaces constraints we relies on Mo's algorithm to sort the queries.

The typical `ADD` and `REMOVE` operations used in this kind of problems to mantain the window of current-in-range items
are here implemented as counter for two frequencies vector:

- `freq` => `freq[i]` counts how many times we saw color `i` 
- `freq_counter` => `freq_counter[i]` counts how many colors we saw i times

# Time cost:
O( (n + m) * sqrt(m))
# Space cost:
O(n + m)