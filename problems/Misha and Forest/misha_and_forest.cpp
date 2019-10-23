#include <iostream>
#include <vector>
#include <queue>


std::vector< std::pair<int, int>> build_forest_from_leaves(std::vector<int> & degrees, std::vector<int> & sums, std::queue<int> & leaves){
  std::vector< std::pair<int,int>> result;
  size_t current_node;
  while(!leaves.empty()){
    current_node = leaves.front();
    // special case
    if(degrees[current_node] == 0) leaves.pop();
    else {
      leaves.pop();
      degrees[current_node]--;
      degrees[sums[current_node]]--;
      if( degrees[sums[current_node]] == 1) leaves.push(sums[current_node]);
      sums[sums[current_node]] ^= current_node; // remove current from sum of j
      result.emplace_back(std::make_pair(current_node, sums[current_node]));
    }
  }
  return result;
}

int main(){
  int num_vertices, deg, sum;
  
  std::cin >> num_vertices;
  
  std::vector<int> degrees;
  std::vector<int> sums;
  degrees.reserve(num_vertices);
  sums.reserve(num_vertices);

  std::queue<int> leaves;
  for(int i = 0; i < num_vertices; ++i){
    std::cin >> deg >> sum;
    degrees.push_back(deg);
    sums.push_back(sum);
    if(deg == 1) leaves.push(i);            
  }
  auto edges = build_forest_from_leaves(degrees, sums, leaves);
  std::cout << edges.size() << std::endl;
  for(auto e: edges) std::cout << e.first << " " << e.second << std::endl;
  
  return 0;
}
