# Longest Common Subsequence
Problem : https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

### Description:
We use a memoization matrix of size `(|s1|+1) * (|s2|+1)`

`T[i-1][j-1]` contains the length of the longest common subsequence for the prefixes `s1[0..i]` and `s2[0..j]`.

The reccurences we use to fill the matrix T are the following
  - `T[0][i] = 0` ie: we cannot have matches between any string and the empty string
  - `T[j][0] = 0` ie: same as above

  - `T[i][j] = 1 + T[i-1][j-1]`  if s1[i-1] == s2[i-1] ie: we have a new optimal solution
  - `T[i][j] = max(T[i-i][j], T[i][j-1]` otherwise, ie: we do not have a match and we keep on using the previous found optimal solution


# Time cost:
O(|string1| * |string2|)
# Space cost:
O(|string1| * |string2|)