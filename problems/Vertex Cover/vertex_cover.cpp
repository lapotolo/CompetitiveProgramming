// source: https://riptutorial.com/dynamic-programming/example/25808/minimum-vertex-cover

#include <vector>
#include <iostream>

#define printele(x) std::cout << x;
#define newline(x) std::cout << std::endl;
#define printdbg(x) std::cout << #x ": " << x;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

// debug purposes
void print_tree(std::vector<std::vector<int> > const& tree, int n){
  for(int i = 0; i <= n; ++i){
    std::cout << "node = " << i << " -> [ ";
    for(auto el : tree[i]){
      std::cout << el << " ";
    } 
    std::cout << "]\n";
  }
}
void print_dp_table(std::vector<std::vector<int> > const& dp_table){
  std::cout << "dp =\n";
  for(int i = 1; i < dp_table.size(); ++i){
    std::cout << "    [ ";
    for(int j = 0; j < 2; ++j){
      std::cout << dp_table[i][j] << " ";
    } 
    std::cout << "] : " << i <<"\n";
  }
}

void dfs(int source , int parent, std::vector<std::vector<int> > const& tree, std::vector<std::vector<int>> & dp_table) {
  int v;
  size_t neighbors = tree[source].size();
  dp_table[source][1] = 1;	
  for(int i = 0 ; i < neighbors; ++i) {
    v = tree[source][i];
    if(v != parent) {
      dfs(v, source, tree, dp_table); // going as deep as possible, ie: do things when the recursion unwinds
      dp_table[source][1] += (std::min(dp_table[v][0] , dp_table[v][1]));
      dp_table[source][0] += (dp_table[v][1]); 
    }
  }
}

int main() {
  
  int n, u, v;
  std::cin >> n;
  std::vector<std::vector<int>> tree;
  tree.reserve(n+1);
  std::vector<std::vector<int>> dp(n+1, std::vector<int>(2, 0));
  for(int i = 1 ; i < n ; ++i){
    std::cin >> u >> v;
    tree[u].push_back(v); // add edge u -> v
    tree[v].push_back(u); // add edge v -> u
  }
  dfs(1 , 0, tree, dp);
  std::cout << std::max(std::min(dp[1][0], dp[1][1]), 1) << std::endl;	
  return 0;
}
