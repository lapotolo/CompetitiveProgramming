# Pashmak and Parmida's problem
Problem: http://codeforces.com/problemset/problem/459/D?locale=en

### Description:
We remap the input vector into a a vector of ranks in the sorted input to work with a sequence of integers in the range [0, n-1].


By looping right to left we compute the support vector suffix_counter. `suffix_counter[i] = f(i, n, input[i])`
At the same time we build a fenwick tree over suffix_counter such that given an index i, `bit[i]` counts the number of times
that elements in suffix_counter equal `i`.
Note that, given an index k > i `bit.sum(k)` gives the number of times `f(i, n, input[i]) < k`

Then we loop left to right




## Time cost  = O(n * log n) dominated by the sort needed to remap input elements in a compressed range.
## Space cost =O(n) to store the input array, the suffix_counter, the counter and the Fenwick tree.
