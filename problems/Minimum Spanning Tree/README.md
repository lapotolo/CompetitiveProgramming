# Minimum Spanning Tree
Problem : https://www.spoj.com/problems/MST/

### Description:
Standard application of Kruskal algorithm. It's a greedy algorithm. The implementation exploits a Union-Find data structure.
Sort and process the edges of the given graph in increasing order. 
Start from a "new" graph with no edges and |V| nodes.
For each edge of the input graph, if the two ends are not already in the same set then 
apply `unite` on them and add to the result the weight of that edge.

# Time cost:
O(|E| * log |V|)
# Space cost:
O(|V| + |E|)
