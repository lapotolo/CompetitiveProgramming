# Queue
Problem : http://codeforces.com/problemset/problem/141/C?locale=en

### Description:
After having parsed the input, the people are sorted by the number of people taller than them and in front of them in the previous queue.

By sorting we get two things: we can check if a possible solution exists and if it so we order we have a valid one for the rebuilt queue.


Then we have to assign heights to every person.


Starting from the first position, that is the front of the queue, each person is inserted into the `height` vector at position i-a[i].  
The procedure is correct since inserting at the back of an correct right part of a queue does not influence the already correctly build part.

# Time cost:
O(n * log n) dominated by the sorting
# Space cost:
O(2 * n)