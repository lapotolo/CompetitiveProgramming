#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

struct query {
  int l, r, k;
  size_t id;
};

// Sorry, I dont like doing these global declarations too :(
std::vector<int> color;                  // vertices colors
std::vector<std::vector<int>> tree;      // adjacency list
std::vector<query> Qs;
std::vector<int> freq;        // freq[i] counts how many times we saw color i
std::vector<int> freq_counter;       // freq_counter[i] counts how many colors we saw i times
std::vector<int> solution;    // query solutions
std::vector<int> dfs_grey;    // discovery time of a node. Here starts its subtree
std::vector<int> dfs_black;   // Closing time of a node. Here finishes its subtree
std::vector<int> flat_tree;   // tree flattened to handle 2d queries

void dfs(int u, int parent, int & time) { // dfs of the tree to flatten it in an array.
  dfs_grey[u] = ++time;
  flat_tree[time] = color[u];
  for(int & node : tree[u]) if(node != parent) dfs(node, u, time);
  dfs_black[u] = time;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int N, M, bucket_size = 512, time = 0;
  std::cin >> N >> M; // |V|, |E|

  color.resize(N+1);
  tree.resize(N+1);
  Qs.resize(M);
  solution.resize(M+1, 0);
  freq.resize(100001, 0);
  freq_counter.resize(100001, 0);
  dfs_grey.resize(N+1, 0);
  dfs_black.resize(N+1, 0);
  flat_tree.resize(N+1, 0);

  // Read colors
  for(size_t i = 0; i < N; i++) std::cin >> color[i];
  // Read edges
  int u, v;
  for(size_t i = 0; i < N-1; ++i) {
    std::cin >> u >> v;
    --u; 
    --v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  // Start dfs from root 0
  dfs(0, -1, time);
  // printarr(flat_tree,0);
  // printarr(dfs_grey,0);
  // printarr(dfs_black,0);

  // Read and create queries
  for(size_t i = 0; i < M; ++i) {
    int v, k;
    std::cin >> v >> k;
    v--; // because of 0 based counting in vectors
    Qs[i] = query{ dfs_grey[v]
                 , dfs_black[v]
                 , k
                 , i
                 };
  }

  auto mo_cmp = [&](query const& a, query const& b) -> bool
    {
      int left1 = a.l /bucket_size;
      int left2 = b.l /bucket_size;
      return (left1 != left2) ? (a.l < b.l) : (a.r < b.r);
    };

  // Sort queries by bucket
  std::sort(Qs.begin(), Qs.end(), mo_cmp);
  
  auto add = [&](int pos)     // Increment window
  {
    freq[flat_tree[pos]]++; // freq[i] counts the occurrences of  color i in the current window
    freq_counter[freq[flat_tree[pos]]]++; // freq_counter[i] counts h
  };

  auto remove = [&](int pos)  // Decrement window
  {
    freq_counter[freq[flat_tree[pos]]]--;
    freq[flat_tree[pos]]--;
  };

  int curr_l = Qs[0].l;
  int curr_r = curr_l-1;

  for(size_t i = 0; i < M; ++i) {
    // std::cout << "(" <<Qs[i].l <<", " << Qs[i].r << ", " << Qs[i].k << ", " << Qs[i].id << ")\n";
    // printdbg(curr_l); printdbg(curr_r);
    // printdbg(Qs[i].l); printdbg(Qs[i].r);
    // printele("starting from freq-freq_counter");
    // printarr(freq,0);
    // printarr(freq_counter,0);
    while(curr_l > Qs[i].l) { /* printele("ADD L"); */ curr_l--; add(curr_l); }
    while(curr_r < Qs[i].r) { /* printele("ADD R"); */ curr_r++; add(curr_r); }
    while(curr_l < Qs[i].l) { /* printele("REM L"); */ remove(curr_l); curr_l++; }  
    while(curr_r > Qs[i].r) { /* printele("REM R"); */ remove(curr_r); curr_r--; }
    //std::cout << "Every operation finished for query " << i << std::endl;
    //printarr(freq,0);
    //printarr(freq_counter,0);
    //printele("");
    //printele("*******************************************************************")
    solution[Qs[i].id] = freq_counter[Qs[i].k];
  }

  for(size_t i = 0; i < M; ++i) 
    std::cout << solution[i] << std::endl;

  return 0;
}
