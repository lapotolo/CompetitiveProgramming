# Largest Even Number
Problem : https://practice.geeksforgeeks.org/problems/largest-even-number/0

### Description:
Counting sort based solution. We read digit by digit the input string and we count the occurrences of each digit.
The we scan and empty the buckets right to left to get the value we are asked for.

# Time cost:
O(n) to read the input and scan the buckets left to right.
# Space cost:
O(n) to store the input and the buckets.