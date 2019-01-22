// author: Lapo Toloni
// problem: https://practice.geeksforgeeks.org/problems/bipartite-graph/1#ExpectOP

#include <iostream>
#include <vector>


using namespace std;

#define WHITE -1
#define RED 0
#define GREEN 1
// #define MAX 100

bool dfs_visit(int current_node, int graph[][MAX], int V, int parent_color, vector<int> & coloring) {
    coloring[current_node] = (parent_color + 1 ) % 2;
    for(int j = 0; j < V; ++j){
        if(graph[current_node][j] == 1) {
            if (coloring[j] == WHITE) return dfs_visit(j, graph, V, coloring[current_node], coloring);
            else{
                 if (coloring[j] == coloring[current_node]) 
                    return false;   
            }
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

bool isBipartite(int G[][MAX],int V)
{
    return DFS(G, V);
}

// debug purposes
// int main() {
//     int test_cases;
//     cin >> test_cases;
//     while(test_cases>0){
//         int v = 0;
//         cin >> v;
//         int g[MAX][MAX];
//         for(int i = 0; i < v; ++i){
//             for(int j = 0; j < v; ++j){
//                 cin >> g[i][j];
//             }
//         }
//         for(int i = 0; i < v; ++i){
//             for(int j = 0; j < v; ++j){
//                 cout << g[i][j] << " ";
//             }
//             cout << endl;
//         }
//         bool result = isBipartite(g, v);
//         cout << "result = " << result << endl;

//         test_cases--;
//     }
// }