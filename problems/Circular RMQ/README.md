# Circular RMQ
Problem : https://codeforces.com/problemset/problem/52/C

### Description:
The problem is solved using a standard segment tree with lazy updates to answer the requested range minimum queries.
The only difference from the standard implementation that was required for this problem is the capability to support
circular queries. This is solved by splitting every circular query (ie: when we have a left range point greater than a right range point)
into two query:
     - the first in the range  [l,.., number_of_leaves -1]
     - the second in the range [0,.., r]

## Time cost  = O(m * log n) 
## Space cost = O(3n) = O(n) to store the input, the segment tree and the lazy tree