# N Meetings In One Room
Problem: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

### Description:
Sort and process scheduled meetings by finishing time
For every meeting we choose it if it does not conflict with the previously last chosen activity, i.e.: if its starting time is greater then the last selected activity's finishing time. 


## Time cost  = O(n * log n) dominated by the sort of the finishing time
## Space cost = O(n) to store the input in a vector.