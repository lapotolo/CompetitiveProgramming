# Maximum Path Sum
Problem : https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

### Description:
DFS over the given tree to compute the max of every path on the left and on the right subtree.
So starting from the subtrees rooted at the leaf of the given tree, for every subtree root is computed the maximum path from that root to every leaf. As the recursion unwinds the path are summed and compared in order to choose the maximal one.

# Time cost:
O(2 * n - 1) = O(n)
# Space cost:
O(2 * n - 1) = O(n)
