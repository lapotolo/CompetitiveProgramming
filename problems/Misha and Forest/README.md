# Misha and Forest
Problem : http://codeforces.com/problemset/problem/501/C?locale=en

### Description:
We start building the forest starting from the leaves that for sure exist because we know Misha had a forest that is a disjoint set of trees.

We select a vertex `X` whose degree is 1 that is a leaf.

Since its degree is 1 the XOR Sum field corresponds to its unique neighbor.
So for each leaf we already have the (index of the) vertex which is adjacent to `X`. (call it `Y`)

For each leaf we have to delete its occurrence in the XOR sum of its unique adjacent vertex and decrement by one the degree of `Y`. The first operation is easily achieved thanks to XOR sum properties. It is enough to XOR `Y` sum and index of `X`.
We repeat the process for each vertex with a degree 1 until we find all the edges of the initial graph.
We are assured to terminate with the correct graph since we know that there are no loops and no parallel edges, so we have always at least a leaf.

# Time cost:
O(n)
# Space cost:
O(n)
