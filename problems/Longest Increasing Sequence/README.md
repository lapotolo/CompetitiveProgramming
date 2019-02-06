# Longest Increasing Subsequence
Problem : https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

### Description:
Quadratic solution: dynamic programming bottom up approach.


For every element store LIS(i) = LIS for the prefix `[0, i)`
- `LIS[0] = 1` trivially.
- `LIS[i] = 1` if the current element at position i is the smallest seen so far.
- `LIS[i] = 1 + max(LIS(j))` for `0 <= j < i`.

every time we use the third equation we check if the just computed LIS[i] is greater then the previous optimum if it is so we update the variable used to store the optimum.

# Time cost:
O(n * n)
# Space cost:
O(n)