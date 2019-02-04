# Alternative Thinking
Problem: http://codeforces.com/problemset/problem/603/A

### Description:
Count the number of characters different from their predecessor and add. Since a flip of a substring can increase the result at most by 2,
at the end we increment the result by 2.
There's and edge case: when the length of the max alternating subsequence is equal to the length of the original string
the answer is n itself.

## Time cost  = O(n) to scan the input array
## Space cost = O(1) since we just store few variables. It's not needed to store the whole input array