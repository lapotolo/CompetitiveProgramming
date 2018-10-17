#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< pair<int, int>> build_forest_from_leaves(vector<int> & degrees, vector<int> & sums, queue<int> & leaves){
    vector< pair<int,int>> result;
    int current_node;
    while(! leaves.empty()){
        current_node = leaves.front();
        // special case
        if(degrees[current_node] == 0) leaves.pop();
        else {
            leaves.pop();
            degrees[current_node]--;
            degrees[sums[current_node]]--;
            
            if( degrees[sums[current_node]] == 1) leaves.push(sums[current_node]);
            
            sums[sums[current_node]] ^= current_node; // remove current from sum of j
            
            result.emplace_back(make_pair(current_node, sums[current_node]));
        }
    }
    return result;
}

int main(){
    int num_vertices, deg, sum;
    
    cin >> num_vertices;
    
    vector<int> degrees;
    vector<int> sums;
    degrees.reserve(num_vertices);
    sums.reserve(num_vertices);

    queue<int> leaves;
    for(int i = 0; i < num_vertices; ++i){
        cin >> deg >> sum;
        degrees.push_back(deg);
        sums.push_back(sum);
        if(deg == 1) leaves.push(i);            
    }
    auto edges = build_forest_from_leaves(degrees, sums, leaves);
    
    cout << edges.size() << endl;
    for(auto e: edges) cout << e.first << " " << e.second << endl;

    return 0;
}
