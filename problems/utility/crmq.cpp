/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/52/C>

  Solution description:

    Just implement a segment tree with lazy update.
    For circular query/update [l, r] where l > r separate them in two query/update
    [0, r] and [l, N-1]

  Time  complexity: O((N+Q)*log(N))
  Space complexity: O(N)

  Where:
  - N is the size of the input vector
  - Q is the number of queries
*/

#include <iostream>
#include <bitset>
#include <functional>
#include <utility>
#include <tuple>
#include <limits>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>

struct SegmentTree
{

  int N;
  std::vector<long long int> ST, LU;

  SegmentTree(const std::vector<int> &V)
  {
    N = V.size();
    ST.resize(N*4, 0);
    LU.resize(N*4, 0);
    build(V, 1, 0, N-1);
  }

  void build(const std::vector<int> &V, int idx, int l, int r)
  {
    if(l > r) return;
    if(l == r)
    {
      ST[idx] = V[l];
      return;
    }
    int m = (l+r)/2;
    build(V, 2*idx, l, m);
    build(V, 2*idx+1, m+1, r);
    ST[idx] = std::min(ST[2*idx], ST[2*idx+1]);
  }

  void update(int l, int r, long long int add){
    if(l > r)
    {
      update(1, 0, N-1, l, N-1, add);
      update(1, 0, N-1, 0, r, add);
    }
    else update(1, 0, N-1, l, r, add);
  }

  void update(int idx, int s, int e, int l, int r, long long int add)
  {
    if(LU[idx] != 0)
    {
      ST[idx] += LU[idx];
      if(s != e)
      {
        LU[2*idx+0] += LU[idx];
        LU[2*idx+1] += LU[idx];
      }
      LU[idx] = 0;
    }

    if(s > e || s > r || e < l) return;

    if(s >= l && e <= r)
    {
      ST[idx] += add;
      if(s != e)
      {
        LU[2*idx+0] += add;
        LU[2*idx+1] += add;
      }
    }
    else
    {
      int m = (s+e)/2;
      update(2*idx, s, m, l, r, add);
      update(2*idx+1, m+1, e, l, r, add);
      ST[idx] = std::min(ST[2*idx], ST[2*idx+1]);
    }
  }

  long long int query(int l, int r)
  {
    if(l > r) return std::min(query(l, N-1), query(0, r));
    return query(1, 0, N-1, l, r);
  }

  long long int query(int idx, int s, int e, int l, int r)
  {
    if(LU[idx] != 0)
    {
      ST[idx] += LU[idx];
      if(s != e)
      {
        LU[2*idx+0] += LU[idx];
        LU[2*idx+1] += LU[idx];
      }
      LU[idx] = 0;
    }

    if(s > e || s > r || e < l) return (1<<30);
    if(s >= l && e <= r) return ST[idx];

    int m = (s+e)/2;
    return std::min(query(2*idx, s, m, l, r), query(2*idx+1, m+1, e, l, r));
  }
};


std::vector<std::string> split(std::string str, char delimiter)
{
  std::vector<std::string> internal;
  std::stringstream ss(str);
  std::string tok;
  while(getline(ss, tok, delimiter)) internal.push_back(tok);
  return internal;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N;
  std::vector<int> V(N);
  for(int i=0; i<N; i++) std::cin >> V[i];

  std::cin >> Q;
  std::string line;
  std::getline(std::cin, line);

  struct SegmentTree st(V);

  for(int i=0; i<Q; i++)
  {
    std::getline(std::cin, line);
    auto el = split(line, ' ');

    if(el.size() == 2)
      std::cout << st.query(std::stoi(el[0]), std::stoi(el[1])) << std::endl;
    else
      st.update(std::stoi(el[0]), std::stoi(el[1]), std::stoi(el[2]));
  }

  return 0;
}
