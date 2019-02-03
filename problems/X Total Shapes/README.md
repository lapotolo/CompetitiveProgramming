# X Total Shapes
Problem: http://practice.geeksforgeeks.org/problems/x-total-shapes/0

### Description:
A standard usage of DFS to count the number of connected components of the given graph represented via adj matrix
Every time we exit from a stack of recursive calls we increment the number of connected components found.

## Time cost  = O (test_cases * #rows * #columns)
## Space cost = O (2 * #rows * #columns) to store the graph and the visited matrix
