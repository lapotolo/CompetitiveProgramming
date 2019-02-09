# Two Heaps 
Problem : http://codeforces.com/problemset/problem/353/B?locale=en

### Description:
The max number of different four digits numbers is given by the product of the distinct two-digits number in the two heaps. So in order to maximize this count we need to assign cubes in a round-robin way between the two heaps.
If a number is at its second occurrence then we assign it to the other heap wrt the first assigment. Every items occurring more than 2 times do not make the maximum count increment so we could just stash them and add to the two heaps in the end.  

# Time cost:
O(n)
# Space cost: 
O(n)