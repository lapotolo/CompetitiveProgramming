# Magic Numbers
Problem: http://codeforces.com/problemset/problem/320/A?locale=en

### Description:
Greedly (check in this order) if the last 3, 2, or just the rightmost digit/s of the input number is one of the three magic numbers "atoms" ({144,14,1}).
We keep on decreasing the number by subtracting the rightmost magic number atom and dividing by the power of then of the order of the subtracted number. 
If we reach zero then the input is a magic number.

## Time cost  = O(#digits_input_number)
## Space cost = O(1) It is enough to store an integer.