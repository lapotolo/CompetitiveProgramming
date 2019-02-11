# Centroid Decomposition 
 Build: 2 DFSs: the first to count the "components" sizes, the second to find the centroids. (form a random node always move to comp >= n/2)
Now, consider any two vertices A and B in the tree and the path connecting them,
and let's find the vertex C with the smallest label on that path.
It's not hard to see that the path connecting A and B lies entirely in the part that vertex C was the centroid of in the above process,
and that A and B lie in different parts that appear after removing C.
So our path is concatenation of two paths: from C to A, and from C to B.

Finding C given A and B is also easy:
let's just keep a link from each vertex to its "parent" in the above process
(if our vertex has label K, the parent will have label K-1),
and let's repeatedly follow this link either on A or on B, whichever currently has a higher label, until the two coincide.

Notice that we've chosen O(NlogN) paths in the tree 
(from each centroid to all vertices in the corresponding part)
such that every path is a concatenation of two paths from that set,
and we can find those two paths in O(logN) time. Such decomposition of paths turns out useful in many problems.

# RMQ with Fenwick Trees
Since a node represents the minimum value of itself and its children, changing a node will affect its parents, but not its children. Therefore, to update a tree we start from the node we are modifying and move up all the way to the fictional root node (0 or N+1 depending on which tree).

Suppose we are updating some node in some tree:

    If new value < old value, we will always overwrite the value and move up
    If new value == old value, we can stop since there will be no more changes cascading upwards

    If new value > old value, things get interesting.
        If the old value still exists somewhere within that subtree, we are done
        If not, we have to find the new minimum value between real[node] and each tree[child_of_node], change tree[node] and move up

