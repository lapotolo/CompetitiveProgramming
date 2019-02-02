# Powerfull array
Problem : https://codeforces.com/contest/86/problem/D

### Description:

This is a standard application of Mo's algorithm:

- the elements in input are logically put in logic buckets of size `sqrt(n)` and length `n`
- queries are sorted with respect to the left value so that each query belongs to a bucket. Queries inside the same bucket  are sorted  with respect to the right end of the query.

Having done this preprocessing we can apply the standard `add` and `remove` functions:
we keep a vector to count frequencies of the elements inside the range of each query and we store the result of a query in `tmp_result`.

If we do the computation Ks·Ks·s in a naive way, the algorithm would be too slow, so we use a trick: if we have already computed the value (k^2)*s, and we have to compute (k+1)^2*s we have that (k+1)^2*s = k^2*s + 2*k*s + s so we just need to add 2*k*s + s. This is true also if it is the first occurrence of the element (since k = 0) and when we have to subtract an occurance of the element.


## Time cost  = O((m + n) * sqrt(n)) from Mo's algorithm
## Space cost = O(n) to store the input and the counter