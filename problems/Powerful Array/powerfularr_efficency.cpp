/*
  Sometimes the solution gets TLE on TEST 5.
  I should speed up the comparison and the way I compute the result
  by using a single expression in add and remove.

  Infact if we have (Ks^2 * s) already in tmp_result, to get (Ks^2 + 1)*s it is enough to add (2Ks*s + s)
  (square of a binomial)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


struct query {
  size_t l, r, index;
};

void add( size_t p
        , std::vector<int> const& input
        , std::vector<int> & counter
        , int64_t & result)
{
  int64_t el = input[p];
  result += ((counter[el]++ << 1) + 1) * el;
}

void remove( size_t p
        , std::vector<int> const& input
        , std::vector<int> & counter
        , int64_t & result)
{
  int64_t el = input[p];
  result -= ( (--counter[el] << 1) + 1) * el;
}

void momo( std::vector<int> const& input
         , std::vector<query> const& Q
         )
{
  int l, r, current_l = 0, current_r = 0;
  int64_t tmp_result = 0;
  std::vector<int> counter(input.size());
  std::vector<int64_t> res(Q.size());

  for (size_t i = 0; i < Q.size(); ++i){
    l = Q[i].l;
    r = Q[i].r;
    while( current_l > l) { // aggiungi perchè siamo all'interna del range nuova 
      current_l--;
      add(current_l, input, counter, tmp_result);
    }

    while( current_r < r) {
      current_r++;
      add(current_r, input, counter, tmp_result);
    }

    while( current_l < l) {
      remove(current_l, input, counter, tmp_result);
      current_l++;     
    }

    while( current_r > r) {
      remove(current_r, input, counter, tmp_result);
      current_r--; 
    } 
    res[Q[i].index] = (tmp_result);
  }
  for (auto result : res) std::cout << result << std::endl;
  
}
int main() {
  std::ios_base::sync_with_stdio(false);
  size_t n, m, l, r;
  size_t bucket_size;
  std::cin >> n >> m;
  bucket_size = sqrt(n);
  std::vector<int> input(n+1);
  std::vector<query> Q(m);
  for (size_t i = 1; i <= n; ++i) std::cin >> input[i]; // read input
  for (size_t i = 0; i < m; ++i) { // read queries
    std::cin >> l >> r;
    Q[i] = (query{l, r, i});
  }

  // source: https://codeforces.com/blog/entry/59346
  auto mo_cmp2 = [&](query const& a, query const& b) -> bool
    {
      int bucketed_al = a.l/bucket_size;
      int bucketed_bl = b.l/bucket_size;
      if(bucketed_al != bucketed_bl) return bucketed_al < bucketed_bl;
      return (a.r < b.r) ^ ((bucketed_al) % 2);   
    };
  sort(Q.begin(), Q.end(), mo_cmp2);
  momo(input, Q);
  return 0;
}
