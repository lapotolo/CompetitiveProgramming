
# include <iostream>
# include <algorithm>
# include <vector>
# include <stack>
# include <queue>

void dfs_visit( int u
              , std::vector< std::vector<int> > const& graph
              , std::vector< std::pair<int,int> > & times
              , std::vector<unsigned char> & visited 
              , std::vector<int> & parent
              , int & current_time) {
  // string mapping = "yzstxwvu";
  // cout << mapping[u] << " " ;
  current_time++;
  times[u].first = current_time;
  visited[u] = true;
  for (auto v : graph[u])
    if (!visited[v]){
      parent[v] = u;
      dfs_visit(v, graph, times, visited, parent, current_time);
    }
    current_time++;
    times[u].second = current_time;
}

void DFS_from_a_source( int source
                      , std::vector<std::vector<int>> const& graph
                      , std::vector< std::pair<int,int> > & times
                      , std::vector<unsigned char> & visited
                      , std::vector<int> & parent) {
  // string mapping = "yzstxwvu";
  int current_time = 0;
  for (int u = source, count = 0; count < graph.size(); ++u, ++count){
    u %= graph.size();
    // cout << "\nu = " << u << " That is node = "<< mapping[u] << endl;
    if (!visited[u]) dfs_visit(u, graph, times, visited, parent, current_time);
  }
}

void DFS( std::vector<std::vector<int>> const& graph
        , std::vector< std::pair<int,int> > & times
        , std::vector<unsigned char> & visited
        , std::vector<int> & parent) {
  int current_time = 0;
  for (int u = 0; u < graph.size(); ++u){
    if (!visited[u]) dfs_visit(u, graph, times, visited, parent, current_time);        
  }
}

int main() {

    int V, E;
    std::cin >> V >> E;


    std::vector<std::vector<int> > graph(V);
    std::vector<std::pair<int,int>> times(V, std::make_pair(-1,-1));
    std::vector<unsigned char> visited(V, false);
    std::vector<int> parent(V, -1);


    for (int i = 0; i < E; ++i) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        // comment this line if directed graph
        // graph[b].push_back(a);
    }
    DFS_from_a_source(2, graph, times, visited, parent);

    std::string mapping = "yzstxwvu";
    for(int i = 0; i < times.size(); ++i)
        std::cout << "\n| " << mapping[i] << ".d = " << times[i].first << " | " <<  mapping[i] << ".f = " << times[i].second << "| ";
    std::cout << "\n";

    for(int i = 0; i < times.size(); ++i) std::cout << mapping[i] << " parent: " << mapping[parent[i]] << std::endl;
    return 0;
}
