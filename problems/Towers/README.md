# Towers
Problem : https://codeforces.com/problemset/problem/37/A

### Description:
Sort the lengths in input in decreasing order. 
Then scan the sorted sequence left to right keeping some useful informations in four variables.

- Every time we find a new length we increment the counter for the towers.
- If we find the same length of the last iteration then we increment the current height by one and we check if this new value is the maximum.

# Time cost:
O(n * log n) dominated by the sorting of the input sequence of bars lengths.
# Space cost:
O(n)