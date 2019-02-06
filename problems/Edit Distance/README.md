# Edit Distance
Problem : https://practice.geeksforgeeks.org/problems/edit-distance/0

### Description:
Classical dynamic programming problem solved by using a memoization matrix T of size `(|s1|+1) * (|s2|+1)` and a bottom-up approach.


`T[i-1][j-1]` contains the number of edit operations needed to get the `prefix[0..i]` of s1 from the `prefix[0..j]` of s2.

  - `T[0][i] = i` 
  - `T[j][0] = j`

  - `T[i][j] = T[i-1][j-1] if we have a match ie s1[i-1] == s2[i-1]`
  - `T[i][j] = 1 + min { T[i][j-1], T[i-1][j], T[i-1][j-1] } `

The number of edit operation we look for is in the bottom right corner of T

# Time cost:
O( |string1| * |string2| )
# Space cost:
O( |string1| * |string2| )