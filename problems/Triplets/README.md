# Triplets
Problem : https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text14022018.pdf

### Description:
We fix the index in the middle and we use two fenwick trees `L` and `R` to count respectively the number of elements less than `A[j]` in the prefix `A[0,..,j-1]` and the number of elements greater than `A[j]` in the prefix `A[j+1,..,n]`.
The answer we are asked for is computed summing up for each j the product of:
 - num elements less than    A[j], that comes from `L.sum(input[i]-1)`.
 - num elements greater than A[j], that comes `R.sum(n - 1) - R.sum(A[i])`.


## Time cost  = O(n * log n) given by the queries answered using the BIT.
## Space cost = O(3*n) = O(n)  to store the input and the two BITs.