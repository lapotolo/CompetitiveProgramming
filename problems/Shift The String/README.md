# Shift The String
Problem: https://www.codechef.com/problems/TASHIFT

### Description:
I refer to this kmp algorithm version: https://cp-algorithms.com/string/prefix-function.html
Where we compute pi for the string `P + '$' + T`.
- In this instance of the problem when `pi[i] = |P| = n` is computed, it means that the pattern P completely matches the substring `T[i-n+1, i]`.
- Now we have to compute the starting index of the match in T since so for we were reasoning with the indexing of `P + '$' + T`. This is equal to `i − (n+1) −  n+1 = i − 2n` in T.


Now the solution for the problem Shift The String:
We compute the failure function pi for the string `S = A + '$' + B.B`. 
We look for the maximum value `pi[k]` in the suffix of `pi` `pi[N, ... ,pi.size()-1]`
Notes:
- S[N] is the separator character '$', so the maximum value in that suffix is the lenght  of the longest prefix that is also a suffix ie the length of the best match between the pattern A and the text B.B.
- Let's say that maximum value is at index `k`. The number of shits (the problem refers to a left circular shift as a generic shift ie shift(abcd) = bcda)
  equals to `k - pi[k] - N`.

# Time cost:
O(n) where n is the length of the input string
# Space cost:
O(n)