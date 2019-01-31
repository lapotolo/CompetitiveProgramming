/* ALWAYS ADD FIRST THEN REMOVES
 add(position):
  count[array[position]]++
  if count[array[position]] == 3:
    answer++

remove(position):
  count[array[position]]--
  if count[array[position]] == 2:
    answer--

currentL = 0
currentR = 0
answer = 0
count[] = 0 * #distinct(A)
for each query:
  // currentL should go to L, currentR should go to R
  while currentL &amp;gt; L:
    add(currentL)
    currentL--
  while currentR &amp;lt; R:
    add(currentR)
    currentR++
  while currentL &amp;lt; L:
    remove(currentL)
    currentL++
  while currentR &amp;gt; R:
    remove(currentR)
    currentR--
 
  output answer

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>  // used in split function

#define LEFT(i)     (2 * i + 1)
#define RIGHT(i)    (2 * i + 2)
#define PARENT(i)   ((i - 1) / 2)

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";



int main() {
  std::ios_base::sync_with_stdio(false);
  size_t n, m;
  return 0;
}
