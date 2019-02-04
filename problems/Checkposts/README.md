# Checkposts
Problem : https://codeforces.com/problemset/problem/427/C

### Description:
We compute the strongly connected components of the graph representation of the city by using
the standard two-dfs based algorithm to compute strongly connected components.
The cost we are asked for is the sum of the minimum cost for each scc 
while the number of ways to obtain that cost is obtained
by multiplying the number of node with the minimum cost for each cc.
  Time  complexity: O(N+M)
  Space complexity: O(N+M)
  Where:

## Time cost  = O(|V| + |E|) since we are using two DFS over a graph with |V| nodes and |E| edges
## Space cost = O(|V| + |E|) same as above