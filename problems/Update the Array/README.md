# Update the array
Problem : https://www.spoj.com/problems/UPDATEIT/

### Description:
Quite similar to the already solved problem "Little Girl and Maximum sum"
.
We smartly build a prefix-sum array not by adding to every position in the range of a query but just doing 2 updates.

It's not really needed to implement the prefix-sum using a BIT because the problem is offline.

## Time  cost = O(n + q + u)
## Space cost = O(n)

