
# include <iostream>
# include <algorithm>
# include <vector>
# include <stack>
# include <queue>

using namespace std;


void BFS(vector<vector<int>> const& adj_list, vector<int> & distances, vector<unsigned char> & visited, vector<int> & parent, int source) {

    distances[source] = 0;
    visited[source] = 1;
    parent[source] = -1;
    queue<int> frontier;
    frontier.push(source);

    while (!frontier.empty()) {
        int u = frontier.front();
        frontier.pop();
        cout << u << " ";
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

    int V, E;
    cin >> V >> E;

    vector<vector<int> > adj_list(V);

    vector<int> distances(V, -1);
    //We can use vector<bool>, but it's slow and broken :( , CPP's byte array http://stackoverflow.com/questions/10077771/what-is-the-correct-way-to-deal-with-medium-sized-byte-arrays-in-modern-c
    vector<unsigned char> visited(V, false);
    vector<int> parent(V, -1);


    for (int i = 0; i < E; ++i) {
        int a, b;

        cin >> a >> b;
        adj_list[a].push_back(b);
        // comment this line if directed graph
        adj_list[b].push_back(a);
    }
    BFS(adj_list, distances, visited, parent, 1);
    return 0;
}
