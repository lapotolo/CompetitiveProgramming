#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define WHITE 0
#define BLACK 1

struct junction{
  bool visited;
  int64_t cost;
  std::vector<junction*> edges;
  std::vector<junction*> transposed_edges;
};

void dfs_visit(junction* junction_u_ptr, std::stack<junction*> & stack) {
  junction_u_ptr->visited = true;
  for (auto& v_ptr : junction_u_ptr->edges) if (!v_ptr->visited) dfs_visit(v_ptr, stack);
  stack.push(junction_u_ptr); // BLACKENING THE NODE
}

void dfs(std::vector<junction> & city, std::stack<junction*> & stack) {
  for (auto& junction_v : city) if (!junction_v.visited) dfs_visit(&junction_v, stack);
}

void dfs_visit_transposed(junction* junct, int64_t & min_cost, int64_t & min_occurrences) {
  junct->visited = true;
  for (auto u : junct->transposed_edges)
    if (!u->visited) {
      if (u->cost < min_cost) {
        min_cost = u->cost;
        min_occurrences = 1;
      } 
      else if (u->cost == min_cost) min_occurrences++;
      dfs_visit_transposed(u, min_cost, min_occurrences);
    }
}

std::pair<int64_t, int64_t> dfs_transposed(std::stack<junction*> & stack) {
  int64_t total_cost = 0, min_cost = 0, possibilities = 1, min_occurrences;
  while (!stack.empty()) {
    auto junct_ptr = stack.top();
    stack.pop();
    if (!junct_ptr->visited) {
      min_cost = junct_ptr->cost;
      min_occurrences = 1;
      dfs_visit_transposed(junct_ptr, min_cost, min_occurrences); // going out from here means I've "closed" a scc
      total_cost += min_cost;
      possibilities *= min_occurrences;
    }
  }
  return std::make_pair(total_cost, (possibilities%1000000007));
}

int main() {
  std::ios_base::sync_with_stdio(false);

  size_t n, m, ui, vi;
  int64_t cost;
  std::cin >> n;
  std::vector<junction> city;
  city.reserve(n);
  std::stack<junction*> stack;

  for (auto i=0; i<n; ++i){
    std::cin >> cost;
    city.emplace_back(junction { WHITE, cost, {}, {}});
  }

  std::cin >> m;

  for (auto i = 0; i < m; ++i) {
    std::cin >> ui >> vi;
    // u-1 and v-1 cause vector is zero base
    city[ui-1].edges.push_back(&city[vi-1]);
    city[vi-1].transposed_edges.push_back(&city[ui-1]);
  }

  dfs(city, stack);

  // setting up visited before second dfs

  for(auto& junct : city) (&junct)->visited = false;

  std::pair<int64_t,int64_t> result = dfs_transposed(stack);

  std::cout << result.first << " " << result.second << std::endl;
  return 0;
}