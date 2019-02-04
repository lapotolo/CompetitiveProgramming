# Kadane algorithm
Problem: https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

### Description:
Scan the input array left to right saving step by step the max sum of contiguous elements encountered so far
The first value of the var max_sum is set to the first element of the input array 
We can achieve the right result straightforward in one pass because of the following properties:
1. the the two elements before and after the the first and the last element of the sub-array with maximum sum have to be negative 
2. Every prefix of the sub-array with maximum sum must be positive

# Time cost:
O(n)
# Space cost:
O(n) for the input, O(1) to solve Kadane's problem (we just use two variables)