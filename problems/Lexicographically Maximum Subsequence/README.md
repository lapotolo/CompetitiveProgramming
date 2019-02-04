# Lexicographically Maximum Subsequence
Problem : http://codeforces.com/problemset/problem/196/A?locale=en

### Description:
We scan the input string from right to left
every time we read a char that is lexicographically greater or equal to the current maximum read character then we add it to the result and we record this char in a variable.
Note that initially the maximum is the last character of the input string.

# Time cost:
O(2*n) = O(n) to scan the input and to reverse the result
# Space cost:
O(n) to store the input


