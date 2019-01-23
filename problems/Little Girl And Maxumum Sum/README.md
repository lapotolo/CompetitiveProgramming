# Little girl and maximum sum
Problem : http://codeforces.com/problemset/problem/276/C?locale=en

### Description:
We exploit a support array whose elements represent how many time an element of the input array is requested in a query (access frequency).

After having computed all the frequencies we sort both the input and the suppor array so that we can compute the result by multiplying the elements in the arrays pairwise.

The trick to get a nice time complexity is in the strategy we adopt to build the support array:

instead of accessing all the position of a query we just do 2 updates: the first in position l by +1 and the second in position r+1 by -1. Then we can compute the prefix-sum in linear time.

## Time cost  = O(n * log n) dominated by the two sorts
## Space cost = O(2 * n) = O(n) needed to store the two arrays
