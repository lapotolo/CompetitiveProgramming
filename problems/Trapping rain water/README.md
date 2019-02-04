# Trapping rain water

Problem: http://practice.geeksforgeeks.org/problems/trapping-rain-water/0

### Description:
We get to the solution thinking locally: we compute how much water can be trapped by any single cell computing for each cell
the max height to its left and to its right. This information is stored in the two vector<int> maxs_to_the_left and maxs_to_the_right and computed 
using the same approach used to computer the leaders of an array (see previus problem).  
The amount of water that can be trapped by a single cell is equal to the min between the max to the right and the max to the left minus the height of that cell
To discard negative values (e.g: input 0 4 1 we would get for the middle cell a value equal to -4) we take the max between zero and the value computed.

# Time cost:
O(n) 
# Space cost:
O(n)