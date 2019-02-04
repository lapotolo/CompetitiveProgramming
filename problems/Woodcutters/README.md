# Woodcutters
Problem: http://codeforces.com/contest/545/problem/C

### Description:
We follow a greedy strategy: for each tree (but the first one and the last one that can always be cut respectively left and right) we check if a tree can be cut left. If we can we do it otherwise we try to cut it to the right. If any cut-direction is good then we skip that tree.


# Time cost:
O(2*n) = O(n) to scan the input and to select which trees can be cut
# Space cost:
O(n) to store the input forest


