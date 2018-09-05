#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define WHITE 0
#define BLACK 1

using namespace std;


struct junction{
    bool visited;
    int64_t cost;
    std::vector<junction*> edges;
    std::vector<junction*> transposed_edges;
};

void dfs_visit(junction* junction_u_ptr, stack<junction*> & stack) {

    junction_u_ptr->visited = true;
    cout << "junct_u->cost = " << junction_u_ptr->cost << endl;
    for (auto& v_ptr : junction_u_ptr->edges){
        cout << v_ptr->visited << " | v->cost = " << v_ptr->cost << endl;
        if (!v_ptr->visited) {
            cout << "I'm going deeper...\n";
            dfs_visit(v_ptr, stack);
        }
    }
    cout <<" ----- Gonna be pushed on stack = "<< junction_u_ptr->cost << endl; 
    stack.push(junction_u_ptr); // BLACKENING THE NODE
}

void dfs(vector<junction> & city, stack<junction*> & stack) {
    for (auto& junction_v : city){
        
        cout <<"node cost in dfs = "<< (&junction_v)->cost << endl;
        
        if (!junction_v.visited) dfs_visit(&junction_v, stack);
    }
}

void dfs_visit_transposed(junction* n, int64_t& min_cost, int64_t& min_occurrences) {

    n->visited = true;
    cout << n->cost << endl;

    for (auto v : n->transposed_edges)
        if (!v->visited) {
            if (v->cost < min_cost) {
                min_cost = v->cost;
                min_occurrences = 1;
            } else
            if (v->cost == min_cost)
                min_occurrences++;

            dfs_visit_transposed(v, min_cost, min_occurrences);
        }
}

pair<int64_t, int64_t> dfs_transposed(stack<junction*> & stack) {
    int64_t total_cost = 0, min_cost = 0;
    int64_t possibilities = 1, min_occurrences;

    while (!stack.empty()) {
        auto v = stack.top();
        stack.pop();
        if (!v->visited) {
            cout << "A root: visited="<<v->visited << ", cost=" << v->cost << endl;

            min_cost = v->cost;
            min_occurrences = 1;
            dfs_visit_transposed(v, min_cost, min_occurrences); // going out from here means I've closed a scc
            total_cost += min_cost;
            possibilities *= min_occurrences;
        }
    }
    return make_pair(total_cost, (possibilities%1000000007));
}

int main() {

    std::ios_base::sync_with_stdio(false);

    size_t n, m, ui, vi;
    int64_t cost;
    cin >> n;
    vector<junction> city;
    city.reserve(n);
    stack<junction*> stack;

    for (auto i=0; i<n; ++i){
        cin >> cost;
        city.emplace_back(junction { WHITE, cost, {}, {}});
    }

    cin >> m;

    for (auto i = 0; i < m; ++i) {
        cin >> ui >> vi;
        // u-1 and v-1 cause vector is zero base
        city[ui-1].edges.push_back(&city[vi-1]);
        city[vi-1].transposed_edges.push_back(&city[ui-1]);
    }

    for (auto j : city){
        for(auto& neigh : j.transposed_edges){
            cout << neigh->cost << " | ";
        }
        cout << endl;
    }

    cout << "who is visited before first dfs = [ ";
    for(auto el:city) cout << el.visited << " ";
    cout << "]\n";

    dfs(city, stack);

    cout << "\nDFS FINISHED\n\n";

    cout << "who is visited after first dfs = [";
    for(auto el:city) cout << el.visited << " ";
    cout << "]\n";

    // setting up visited before second dfs
    for(auto& junct : city) (&junct)->visited = false;

    cout << "who is visited BEFORE second dfs = [ ";
    for(auto el:city) cout << el.visited << " " << el.cost << "|";
    cout << "]\n";
    cout << "\nSTARTING SECOND DFS\n\n";

    pair<int64_t,int64_t> result = dfs_transposed(stack);
    cout << result.first << " " << result.second << endl;

    return 0;
}