#include <vector>
#include <iostream>

using namespace std;

// debug purposes
void print_tree(vector<vector<int>> const& tree, int n){
    for(int i = 0; i <= n; ++i){
      cout << "node=" << i << " -> [ ";
      for(auto el : tree[i]){
          cout << el << " ";
      } 
      cout << "]\n";
    }
}
void print_dp_table(vector<vector<int>> const& dp_table){
    cout << "dp =\n";
    for(int i = 0; i < dp_table.size(); ++i){
      cout << "    [ ";
      for(int j = 0; j < 2; ++j){
          cout << dp_table[i][j] << " ";
      } 
      cout << "]\n";
    }
}

void dfs(int source , int parent, vector<vector<int>> const& tree, vector<vector<int>> & dp_table){

    dp_table[source][1] = 1;

    for(int i = 0 ; i < tree[source].size() ; ++i){
        int v = tree[source][i];
        if(v != parent){
            dfs(v, source, tree, dp_table);
            dp_table[source][1] += (min(dp_table[v][0] , dp_table[v][1]));
            dp_table[source][0] += (dp_table[v][1]);
        }
    }
}

int main(){

    int n;
    cin >> n;
    vector<vector<int>> tree;
    tree.reserve(n+1);
    vector<vector<int>> dp(n+1, vector<int>(2));
    for(int i = 1 ; i < n ; ++i){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    // print_tree(tree, n);
    dfs(1 , 0, tree, dp);
    // print_dp_table(dp);
    cout << max(min(dp[1][0], dp[1][1]), 1) << endl;
}