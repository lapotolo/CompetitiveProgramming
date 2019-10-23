#include <iostream>
#include <vector>
#include <algorithm>
#include <algorithm>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


template <typename T>
class Fenwick_Tree
{
public:
  int n;
  std::vector<T> B;
  
  Fenwick_Tree(int size) : n(size) { B = std::vector<T>(n+1, 0); }
  
  void add(int i, T v) {for (++i; i <= n; i += (i&(-i))) B[i] += v;}
  
  T sum(int i) {
    T sum = 0;
    for (++i; i != 0; i -= (i&(-i))) sum += B[i];
    return sum;
  }
};

void to_ranks(std::vector<int> & a, std::vector<int> & tmp){
  std::sort(tmp.begin(), tmp.end());  
  for (int i = 0; i < tmp.size(); i++) a[i] = std::lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
}

struct segment {
  int left, right, id;
  
  segment(int l, int r, int i): left(l), right(r), id(i) {}
};

int main(){
  
  std::ios_base::sync_with_stdio(false);
  
  int n, left, right;
  std::vector<segment> input;
  std::cin >> n;
  input.reserve(n);
  std::vector<int> answer(n, 0);
  Fenwick_Tree<int> bit(n);

  for (int i = 0; i < n; ++i){
    std::cin >> left >> right;
    input.push_back(segment{left, right, i});
  }

  // sorting by right-ends
  std::sort(input.begin(), input.end(),
            [](segment const & seg1, segment const & seg2) -> bool {
              return seg1.right < seg2.right;
            });

  // remapping right-end in the interval [0, .. n-1] note that the compression in only needed for right ends because the BIT is built only upon right-ends
  for (int i = 0; i < input.size(); ++i) input[i].right = i;

  // now we sort by left-ends
  std::sort(input.begin(), input.end(),
            [](segment const & seg1, segment const & seg2) -> bool {
              return seg1.left < seg2.left; // substitute with > to decr sorting
            });

  // for(auto seg : input) and every input[i] becomes seg
  for (int i = n - 1; i >= 0; --i){
    answer[input[i].id] = bit.sum(input[i].right); // sum(seg_i.right) = how many segments with right-end less then segment_i right-end have I already seen?
    bit.add(input[i].right, 1); // counting the occurrence of r_i
  }
  for(auto ans : answer) std::cout << ans << std::endl;
  return 0;
}
