# Ilya and queries
Problem: http://codeforces.com/problemset/problem/313/B?locale=en

### Description:
Using the input string we build a prefix-sum array. The element *prefix_sum[i]* contains the number of contiguous equal character in the string *input_string* up to position i.

Using this prefix-sum array we can answer each query in constant time by doing two acceses to *prefix_sum[]*, two decrements and a difference.

let n by the length of the input string and m the number of queries. Then :
# Time cost: 
O(n + m) dominated by the time spent in building the prefix-sum array
# Space cost:
O(n) needed to store the input string