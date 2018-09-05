
# include <iostream>
# include <algorithm>
# include <vector>
# include <stack>
# include <queue>

using namespace std;


void dfs_visit(int u, vector<vector<int>> const& graph, vector< pair<int,int> > & times, vector<unsigned char> & visited, vector<int> & parent, int & current_time) {
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

void DFS_from_a_source(int source, vector<vector<int>> const& graph, vector< pair<int,int> > & times, vector<unsigned char> & visited, vector<int> & parent) {
    // string mapping = "yzstxwvu";
    int current_time = 0;
    for (int u = source, count = 0; count < graph.size(); ++u, ++count){
        u %= graph.size();
        // cout << "\nu = " << u << " That is node = "<< mapping[u] << endl;
        if (!visited[u]) dfs_visit(u, graph, times, visited, parent, current_time);
    }
}

void DFS(vector<vector<int>> const& graph, vector< pair<int,int> > & times, vector<unsigned char> & visited, vector<int> & parent) {
    int current_time = 0;
    for (int u = 0; u < graph.size(); ++u){
        if (!visited[u]) dfs_visit(u, graph, times, visited, parent, current_time);        
    }
}

int main() {

    int V, E;
    cin >> V >> E;


    vector<vector<int> > graph(V);
    vector<pair<int,int>> times(V, make_pair(-1,-1));
    vector<unsigned char> visited(V, false);
    vector<int> parent(V, -1);


    for (int i = 0; i < E; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        // comment this line if directed graph
        // graph[b].push_back(a);
    }
    DFS_from_a_source(2, graph, times, visited, parent);

    string mapping = "yzstxwvu";
    for(int i = 0; i < times.size(); ++i)
        cout << "\n| " << mapping[i] << ".d = " << times[i].first << " | " <<  mapping[i] << ".f = " << times[i].second << "| ";
    cout << "\n";

    for(int i = 0; i < times.size(); ++i) cout << mapping[i] << " parent: " << mapping[parent[i]] << endl;
    return 0;
}
