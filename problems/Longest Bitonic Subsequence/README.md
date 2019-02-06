# Longest Bitonic Subsequence
Problem : https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0

### Description:
Just an application of the LIS problem. 

Infact it is enough to compute the LIS for the given sequence left to right and then we reverse the given input and we compute the LIS for the reversed sequence. In the end we reverse the LIS computed right to left to get the LDS.*
At this point we look for the index `i` in LIS and LDS such that `LIS[i] + LDS[i] -1` is maximal.
Note that is needed to subtract by one to not count two times the element `input[i]`.

At this point the solution is computed by: 
- `max_i{LIS[i] + LDS[i]}` for `i in [0..n]`

* In the implementation to avoid doing the reverse of the "right-LIS" we scan at the same time LIS from left to right and LDS from right to left
# Time cost:
O(n * log n) 
# Space cost:
O(n)