//We could use vector<bool>, 
//but it's slow and broken :( , 
//CPP's byte array http://stackoverflow.com/questions/10077771/what-is-the-correct-way-to-deal-with-medium-sized-byte-arrays-in-modern-c

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

void BFS( std::vector<std::vector<int>> const& adj_list
        , std::vector<int> & distances
        , std::vector<unsigned char> & visited
        , std::vector<int> & parent
        , int source) {
  int u;
  distances[source] = 0;
  visited[source] = 1;
  parent[source] = -1;
  std::queue<int> frontier;
  frontier.push(source);

  while (!frontier.empty()) {
    u = frontier.front();
    frontier.pop();
    std::cout << u << " ";
    for (int v : adj_list[u]) {
      if (!visited[v]) {
        visited[v] = 1;
        distances[v] = distances[u] + 1;
        parent[v] = u;
        frontier.push(v);
      }
    }
  }
}


int main() {

  int V, E; // num vertices, num edges
  std::cin >> V >> E;

  std::vector<std::vector<int> > adj_list(V);

  std::vector<int> distances(V, -1);
  std::vector<unsigned char> visited(V, false);
  std::vector<int> parent(V, -1);


  for (int i = 0; i < E; ++i) {
    int a, b;

    std::cin >> a >> b;
    adj_list[a].push_back(b);
    // comment this line if directed graph
    adj_list[b].push_back(a);
  }
  BFS(adj_list, distances, visited, parent, 1);
  return 0;
}
