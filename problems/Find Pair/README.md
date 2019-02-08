# Find Pair
Problem : http://codeforces.com/problemset/problem/160/C?locale=en

### Description:
The n numbers given can be seen as a division of the space in n buckets. 
Since we are dealing with pairs we can see the second element of every pair as a second level subdivision
in buckets of the space.
If every element in input had been different then the k-th pair would have been `((k-1)/n, (k-1)%n)`.

(k-1 because of 0 based couting)

In this case we can have repeated elements.
The way we compute the first element remains the same while it changes the way we get the second member of the pair.
We need to count the number of elements equal to the first item of the k-th pair and the number of elements smaller than it.
At this point the second element is at index `((k-1)-smaller_count*n)/equal_count` in the sorted input sequence.

# Time cost:
O(n * log n)
# Space cost: 
O(n)