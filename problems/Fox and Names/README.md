# Fox and names
Problem : https://codeforces.com/problemset/problem/510/C

### Description:

Consider a graph made of 26 vertices where each node represents a letter of the english alphabet
The we scan the strings given in input and every mismatch we find by comparing these strings we add a directed edge
between the two letters in the graph.


Then we simply run a DFS on this graph in order to check if it is possible to find a topological
sorting.
If the graph we get is NOT acyclic then there not exists a lexicographical ordering based on the given input

 
### Time  complexity: O()
### Space complexity: O()