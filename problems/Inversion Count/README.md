# Inversions count


Problem : https://www.spoj.com/problems/INVCNT/ 

### Description:
(using a Fenwick Tree)

We transform the given vector in a vector of ranks in the sorted vector so that we can use these ranks to directly
index an array storing the frequencies of the elements of the vector.


We keep track of the encountered values using a BIT so that we can answer the needed queries in logarithmic time.


In particular for every element we use the add BIT operation to record the fact that we encoutered that elements
and then we increment the number of inversions by the number of values smaller than the current element.


This number is given by the prefix-sum up to position i in the data structure used for keeping the cumulative frequencies,
ie it's equal to sum(bit, ranks[i]-1)
 
#Time  complexity:
O(n * log(n))
#Space complexity:
O(n)