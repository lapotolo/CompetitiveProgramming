#  Maximum of all subarrays of size k 
Problem: http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

### Description:
As described in class. 
Keep a deque whose invariant property is that the max element in the current range is always at its front end.

 For every `i` in the range `[0, n-1]` mantain the window updated. 
 
 Let `seq[i]` be the next element entering in the window:
 - The first step is to remove from the front the elements that were in the windows up to the previous iteration but that they are going out from the current covered range because of the new i. (ie elements in the range `[0, i-k]`)
 - The second step is to remove from the back every element that is dominated, that is that are less than `seq[i]`
 - The third step is to insert from the back `seq[i]`
 - In the end we report the front of the deque. (`(i >= k - 1)` checks if the window is fully initialized)

# Time cost:
O(n) 
# Space cost:
O(n)