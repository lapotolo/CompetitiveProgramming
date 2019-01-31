// https://codeforces.com/contest/86/problem/D


// per ogni elemento distinto del subarray A[l, r] voglio il prodotto tra
// numero di occorrenze nel subarray alla seconda  il numero stesso

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>



#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

struct query {
  size_t l, r, ind;
};

void add( size_t p
        , std::vector<int> const& input
        , std::vector<int> & counter
        , int64_t & result)
{
  result += 2 * counter[input[p]] * input[p] + input[p];
  counter[input[p]]++;
}

void remove( size_t p
        , std::vector<int> const& input
        , std::vector<int> & counter
        , int64_t & result)
{
  counter[input[p]]--;
  result -= 2 * counter[input[p]] * input[p] + input[p];
}

void momo( std::vector<int> const& input
         , std::vector<query> const& Q
         )
{
  size_t current_l = 0, current_r = 0;
  int64_t res;
  std::vector<int> counter(input.size());
  for (auto q : Q){
    res = 0;
    
    while( current_l > q.l) { add(current_l, input, counter, res); current_l--; }
    
    while( current_r < q.r) { add(current_r, input, counter, res); current_r++; }

    while( current_l < q.l) { remove(current_l, input, counter, res); current_l++; }

    while( current_r > q.r) { remove(current_r, input, counter, res); current_r--; } 

    std::cout << res << std::endl;
  }
  
}
int main() {
  size_t n, m, l, r;
  size_t bucket_size;
  std::cin >> n >> m;
  bucket_size = sqrt(n);
  std::vector<int> input(n);
  std::vector<query> Q(m);
  for (size_t i = 0; i < n; ++i) std::cin >> input[i];
  for (size_t i = 0; i < m; ++i) {
    std::cin >> l >> r;
    Q.emplace_back(query{l, r, i});
  }

  auto mo_sort = [&](query const& a, query const& b) -> bool
    {
      if (a.l / bucket_size < b.l / bucket_size)
        return true;
      if (a.l / bucket_size > b.l / bucket_size)
        return  false;
      return (a.r < b.r);
    };

  sort(Q.begin(), Q.end(), mo_sort);
  momo(input, Q);
  return 0;
  
}

/*
3 2
1 2 1
1 2
1 3
 */

/*
	for( int i = 1; i <= n; i++ )
		cin >> A[i];
	for( int i = 1; i <= q; i++ ){
		cin >> Q[i].l >> Q[i].r;
		Q[i].ind = i;
	}
	sort( Q + 1, Q + q + 1, f );
	//for( int i = 1; i <= q; i++ )
	//	cout << Q[i].l << " " << Q[i].r << "\n";
	
	for( int i = 1; i <= q; i++ )
		ans[ Q[i].ind ] = query( i );
	for( int i = 1; i <= q; i++ )
		cout << ans[i] << "\n";
	
	
	return 0;	
*/
