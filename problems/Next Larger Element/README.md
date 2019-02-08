# Next Larger Element
Problem : https://practice.geeksforgeeks.org/problems/next-larger-element/0

### Description:
Scan the input right to left mantaining a stack. At every iteration the stack stores the set of possible greater elements than the currently processed element.
For each element we process we check if the top of the stack is greater than the current element. If it is so report the top as the next greater element of the current element otherwise pop from the stack. Repeat while the stack is not empty or a greater element is found. Then push that element onto the stack.


# Time cost:
O(n)
# Space cost:
O(2*n) = O(n) to store the input array and the stack
