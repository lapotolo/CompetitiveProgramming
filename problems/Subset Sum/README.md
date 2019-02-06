# Subset Sum
Problem: https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

### Description:
The solution adopted is similar to the one used for the knapsack problem.
Infact this problem can be reduced to check if there exists a subset of the given input that sums to the the halved sum of the whole sequence.

We use a memoization boolean matrix, filled row by row, of size `(n) * (SUM/2)` where `n` is the total number of items avaiable and `SUM` is the sum of the numbers given as input.
In general we encode in T the following subproblem solution:
- `T[i][j] = 1` if `j` can be obtained as sum of elements in the subset represented by the prefix `[vec[0] ... vec[i]]`
                    false otherwise

The recurrences used are:
- `T[i][0] = 1` since we can always obtain zero by not choosing any item
- `T[0][j] = 0` since we cannot obtain any sum from an empty set.

- `T[i][j] = T[i-1][j]` if the new number is too big to fit the sum j, so we just keep the solution we got not taking the i-th item
- `T[i][j] = T[i-1][j] || T[i-1][lookback_index]` otherwise ie: we are in the case we could take the i-th item.

# Time cost:
O( n * (SUM/2) )
# Space cost:
O( n * (SUM/2) )


