#pragma once

/* 
  Code from https://github.com/spaghetti-source/algorithm/blob/master/data_structure/fenwick_tree.cc
 */

#include <vector>

template <class T>
struct fenwick_tree {
  std::vector<T> B;

  // **************************************************
  fenwick_tree(size_t n) : B(n+1) { } 
  
  // initialize by a constant
  fenwick_tree(size_t n, T a) : B(n+1, a) { 
    B[0] = 0;
    for (int k = 1; k+(k&-k) <= n; ++k){
      B[k+(k&-k)] += B[k];
    }
  }
   
  // initialize by a std::vector
  // the first node is DUMMY
  fenwick_tree(std::vector<T> y) : B(y.size()+1) {
    for (int k = 0; k < y.size(); ++k){
      B[k+1] = y[k];
    }
    for (int k = 1; k + (k & -k) < B.size(); ++k){
       B[k + (k & -k)] += B[k];  
    }
  }

  // **************************************************
  
  // b[k] += a
  void add(int k, T a) { 
    for (++k; k < B.size(); k += k & -k){
      B[k] += a;
    }
  }
  
  // sum b[0,k)
  T sum(int k) {
    T s = 0;
    for (++k; k > 0; k &= k-1){
      s += B[k];
    }  
    return s;
  }

/*

  6 = 0110| &
  5 = 0101|
    ______|__
      0100
 */ 

  // min { k : sum(k) >= a }; it requires b[k] >= 0
  int lower_bound(T a) {
    if (a <= 0) return 0;
    int k = B.size()-1; 
    for (int s: {1,2,4,8,16}) k |= (k >> s); 
    for (int p = ++k; p > 0; p >>= 1, k |= p)
      if (k < B.size() && B[k] < a) a -= B[k]; else k ^= p;
    return k+1;
  }
  
  // maB { k : sum(k) <= a }; it requires b[k] >= 0
  int upper_bound(T a) {
    int k = B.size()-1; 
    for (int s: {1,2,4,8,16}){
      k |= (k >> s);
    }   
    for(int p = ++k; p > 0; p >>= 1, k |= p){
      if(k < B.size() && B[k] <= a){
        a -= B[k];
      } else{
        k ^= p;
      }
    }
    return k;
  }
};