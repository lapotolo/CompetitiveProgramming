# Learning Languages
Problem : https://codeforces.com/problemset/problem/277/A?locale=en

### Description:
The problem is solves using standard disjoint set union data structure.
At the beginning we have n sets, one for every employee. The number of components is stored in the variable `components`.
Then if two employees speaks the same language we do a `unite(emp1, emp2)` and we decrement by 1 the number of total components.
The answer we are asked for is the number of components we have in the end minus 1.


#Time cost:
O( n * log n)
#Space cost:
O( n + m)