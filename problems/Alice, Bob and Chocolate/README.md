# Alice, Bob and Chocolate
Problem : http://codeforces.com/problemset/problem/6/C?locale=en

### Description:
We keep two "pointers" to the beginning of the array representing alice current position and the other to the end representing bob current position.
Then we loop over the array while the two pointers don't arrive to the same potion.
At each loop we check the remainig time needed to eat the next chocolate bar. The one with less remaining time can consume the current piece of chocolate.

## Time cost  = O(n) to read the input array and to traverse it to solve the problem
## Space cost = O(n) to store the input