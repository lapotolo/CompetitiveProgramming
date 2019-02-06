# Minimum Number Of Jumps
Problem : https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0

### Description: 
Bottom up dynamic programming solution.
For every position in the input array we compute the minimum number of jumps required to get there. The simple recurrence used is:
- `J[0] = 0` obviously since no jumps are needed to land in the first node.
- `J[j] = 1 + J[i]` fixed an `i`,  `next <= j <= i + vec[i]` with `next > i`.

Even if two nested for-loops are used the solution is still linear in time since the index `next` used to iterate in the inner loop
is always greater than `i` and it never decreases. Moreover the outer main loop ends not when `i` comes to the end but when `next` does

# Time cost:
O(n)
# Space cost:
O(n)