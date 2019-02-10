# Array Copy
Problem: https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text23012018.pdf

### Description:
We build a 0 filled segment tree with as many leaves as the size of A or B, (it's the same).
- `Copy(x, y, k)` is mocked by marking with the query id the nodes of the segment tree that are in the range of the query.
- `Access(i)` starts from the leaf corresponding to `i` in the segment tree and it crawls up to the root of the tree. It reports the max query id found along this path. Taking the max of the ids along the path we are sure to get current right state of B. 

Then by using the i-th query we can easily report the current mocked status of B.

# Time cost:
O(M * log n) to scan the input array
# Space cost:
O(2 m - 1) = O(n) since m is the next power of the wrt n, the number of elements of the given arrays 