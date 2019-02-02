#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


struct query {
  size_t l, r, index;
};

int input[200005];
query Q[200005];
int counter[1000006];
int64_t res[200005];

int main() {
  std::ios_base::sync_with_stdio(false);
  size_t n, m, l, r, bucket_size;
  int current_l = 0, current_r = 0;
  int64_t tmp_result = 0;

  std::cin >> n >> m;
  bucket_size = 1000;//sqrt(n);

  for (size_t i = 1; i <= n; ++i) std::cin >> input[i]; // read input
  for (size_t i = 0; i < m; ++i) { // read queries
    std::cin >> l >> r;
    Q[i] = (query{l, r, i});
  }

  // cmp source: https://codeforces.com/blog/entry/59346
  std::sort(Q, Q+m, [&](query const& a, query const& b) -> bool
    {
      int bucketed_al = a.l/bucket_size;
      int bucketed_bl = b.l/bucket_size;
      if(bucketed_al != bucketed_bl) return bucketed_al < bucketed_bl;
      return (a.r < b.r) ^ ((bucketed_al) % 2);   
    });
  
  int64_t el = 0;

  for (size_t i = 0; i < m; ++i){
    l = Q[i].l;
    r = Q[i].r;
    while( current_l > l) {
      current_l--;

      el = input[current_l];
      tmp_result += ((counter[el]++ << 1) + 1) * el;
    }

    while( current_r < r) {
      current_r++;

      el = input[current_r];
      tmp_result += ((counter[el]++ << 1) + 1) * el;
    }

    while( current_l < l) {
      el = input[current_l];
      tmp_result -= ( (--counter[el] << 1) + 1) * el;

      current_l++;     
    }

    while( current_r > r) {
      el = input[current_r];
      tmp_result -= ( (--counter[el] << 1) + 1) * el;

      current_r--; 
    } 
    res[Q[i].index] = tmp_result;
  }
  for (int i = 0; i < m; ++i) std::cout << res[i] << std::endl;
  return 0;
}
