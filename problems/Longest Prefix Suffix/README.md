# Longest Prefix Suffix
Problem: https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0

### Description:
Standard implementation of the failure automaton used in KMP algorith for exact pattern matching

BONUS: (Notes on how to build the failure function for KMP)

The failure function tells us this: if you matched X characters of a string, what is the longest suffix of such string such that it's also a prefix of a search string.

If you add a new character at the end of a string, that is you are computing `pi[x]`, and if it matches with character at position `pi[x-1]`, then `pi[x]` is simply `pi[x-1] + 1`.

In the other cases we have a mismatch. So we have to try to find smaller and smaller suffixes, check if we have a match every time we backtrack.

example:
- given the string `"accadaccac"`. We are at the point we need to fill the last element of pi and so far we have `pi = {0,0,0,1,0,1,2,3,4,_}`.
- First you check the failure function of the previous letter, its failure function was 4 because you can match suffix "acca" with the prefix "acca"; 
  and now you add the letter `'c'`, it doesn't match with the letter `'d'` succeeding prefix `"acca"`.
- So you backtrack, to the last good suffix. You are now searching for a suffix of "acca" which is also a prefix of "accadaccac", but is smaller than "acca". The answer to that question is `pi[length("acca")-1]`, or `pi[3]`, which is `pi[3] = 1`, because suffix of length 1 (just the letter 'a') is also a prefix of a search string.
- And now you can try if the 'c' matches with the character on the position 1, and voila, it matches, so now you know `pi[9] = pi[pi[8]-1] + 1 = 2`.

# Time cost:
O(n) where n is the length of the input string
# Space cost:
O(n)