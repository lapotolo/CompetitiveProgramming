#define WHITE -1 // never visited
#define RED 0    // open vertex
#define GREEN 1  // closed vertex
// #define MAX 100

bool dfs_visit(int current_node, int graph[][MAX], int V, int parent_color, vector<int> & coloring) {
  coloring[current_node] = (parent_color + 1 ) % 2;
  for(int j = 0; j < V; ++j){
      if(graph[current_node][j] == 1) {
    		if (coloring[j] == WHITE) return dfs_visit(j, graph, V, coloring[current_node], coloring);
        else if (coloring[j] == coloring[current_node]) return false;   
      }
  }  
  return true;
}


bool DFS(int graph[][MAX], int V){
  vector<int> coloring(V, WHITE);
  bool result = true;
  for(int i = 0; i < V and result; ++i){
    if(coloring[i] == WHITE) result = dfs_visit(i, graph, V, GREEN, coloring);
  }
  return result;
}