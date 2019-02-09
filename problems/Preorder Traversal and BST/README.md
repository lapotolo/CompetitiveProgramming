

# Preorder Traversal and BST
Problem : http://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0


### Description:
Combine solution of Next Greater Element and Next smaller Element. (same problem, solved using a stack. Just change the scan direction of the input).

Since a preorder traversal follows the processing order NLR (node-left-right) and since we want the BST property to hold
we know that starting from  the current (sub)tree root `x` we can have a possibly empty sequence of values smaller than x (if x has a left subtree) then a sequence of greater elements. After having found the first next greater element than x there cannot be any element smaller than x. If it so then we have a BST otherwise not.

# Time cost:
O(n)
# Space cost:
O(n)