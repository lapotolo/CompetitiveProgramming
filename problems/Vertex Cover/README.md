# Vertex Cover
Problem : https://www.spoj.com/problems/PT07X/
### Description:
Bottom-up dynamic programming solution. `dp_table[n][2]` is a memoization table such that:
- `dp_table[i][0]` stores the minimum vertex cover of the subtree rooted at node i not counting i in the solution

- `dp_table[i][1]` stores the minimum vertex cover of the subtree rooted at node i counting i in the solution

By using a dfs traversal of the tree we go down straight to the leaves. Every time we visit a node `v` for the first time (ie: when we grey it) we set `dp_table[v][i]` to 1. As the recursion unwinds we  crawl the tree up bringing the suproblems solution up to the root.

Recurrences, where `v` is the parent node of one of its children `c`:
- `dp_table[v][1] += (std::min(dp_table[c][0] , dp_table[c][1]))` ie: if we take node v in the cover we choose the minimum sized cover between the one obtained by taking or not taking the node `c` in the solution.
- `dp_table[v][0] += (dp_table[c][1])` ie: for sure if we don't take v in our cover we can take c and the subproblem solution its `dp_table` entry holds. 

The solution is the minimum between the minimum vertex cover obtained by taking or not taking the root that is
- `std::min(dp_table[root][0], dp_table[root][1])`

# Time cost:
O( n ) given by a depth-first-traversal on a rooted tree
# Space cost:
O( n ) to store the tree as an edges-list and to store the memoization table.