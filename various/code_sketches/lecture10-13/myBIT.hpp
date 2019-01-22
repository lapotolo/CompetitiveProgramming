/*
BIT is implemented using an array and works in form of trees. 
    Letting n be the number of elements,
      - SUM operation where parent of index x is "x - (x & -x)". Time is O(log n) 
      - ADD operation where we move to right siblings of node x or right sibling of parent(x) is "x + (x & -x)".

        note that (x & -x) is a bittrick used to get the rightmost bit of x

    Building a BIT starting from a given vector requires n SUM operation on a 0-filled BIT with n+1 positions so that
    time complexity is O(n * log n)
*/

#include <vector>

using namespace std; 

template<class T>
struct BIT{
  vector<T> B;
  
  BIT(size_t size) : B(size+1, 0) {}
  
  BIT(vector<T> const& A) : B(A.size()+1, 0) {
    B[0] = 0; // dummy root node
    // for (int i = 1; i <= A.size(); ++i){
    //   add(i, A[i-1]);
    for (int i = 0; i <= A.size(); ++i) add(i, A[i]);
  }

  // B[k] = B[k] + val  for k = i , i = i + (i&(-i)), ... , B.size()
  void add(int i, T val){
    i += 1; // we expose an interface where i is considered an index in the original array
    while(i<= B.size()){
      B[i] += val;
      i = i + (i & (-i));
    }
  }

  //sum from A[0] + A[1] + ... + A[i] (inclusive)
  T sum(int i){
    T result = 0;
    i += 1; // need to increment i by one because of in the BIT every position is shifted one position to the right with respect to the original array
    while(i > 0){
      result += B[i];
      i = i - (i & (-i));
    }
    return result;
  }
};
