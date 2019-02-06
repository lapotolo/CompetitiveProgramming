# 0-1 Knapsack
Problem : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
### Description:
Using the Weight-DP solution.
We use a memoization matrix of size `(n) * (W)` where `n` is the total number of items avaiable and `W` is the maximum capability for this instance of the 01-Knapsack problem.

`T[i][j]` contains the optimal solution for the 01-knapsack subproblem having the first `i` items and a smaller knapsack with maximum capability `j`.

The recurences we use to fill the matrix T are the following: 
  - `T[i][0] = 0` ie: no items can be taken with a knapsack with 0 capability.

  - `T[i][j] = T[i-1][j]` if `weights[i] > j` 
  ie: if the new item's weight is greater then the current maximum capability `j`, the optimal solution is still the previously computed for the subproblem with the first `i-1` items avaiable.
   
  - `T[i][j] = max(T[i-i][j], values[i-1] + T[i-1] - weights[i-1])` otherwise, ie: the new item fit the current knapsack capability so we can check if by choosing it we get a greater profit. So we have to take the maximum between the solution we got with the same max capability but by not taking i-th item (stored at `T[i - 1][j]`) and the profit we would get by taking the i-th item plus the optimal solution we got with the items up to the i-th - 1 and a spare capability equals to  `j - weight_ith_item`. 

# Time cost:
O( n * W)
# Space cost:
O(n * W) We could only store two rows of T.