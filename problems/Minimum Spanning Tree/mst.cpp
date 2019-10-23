#include <iostream>
#include <vector>
#include <algorithm>


struct Edge {
  int source, dest, weight;
  bool operator < (const Edge& e) const {return (weight < e.weight);} 
};

struct Element {
  int parent;
  int rank;
};

struct DisjointSet{
  
	DisjointSet(int n) : sets(n){
          elements.resize(n, Element {-1, -1});
          //initialize set
		// for (int i = 0; i < n; ++i) elements.emplace_back(Element {-1, -1});
	}
  
  void make_set(int x) {
    if (elements[x].rank == -1) {
      elements[x].parent = x;
      elements[x].rank = 0;
    }
  }
  
  void unite(int x, int y) { link(find_set(x), find_set(y)); }
  
  int find_set(int x){
    if( x != elements[x].parent) elements[x].parent = find_set(elements[x].parent);
    return elements[x].parent;
  }
  
  int get_num_sets() const { return sets; }
  
private:
  
  std::vector<Element> elements;
  int sets;
  
  void link(int x, int y) {
    if(x != y){
      if(elements[x].rank > elements[y].rank) elements[y].parent = x;
      else { // y >= x
        elements[x].parent = y;
        if(elements[x].rank == elements[y].rank) elements[y].rank += 1;
      }
      sets--;
    }
  }
  
};

int64_t kruskal(DisjointSet & union_find, std::vector<Edge> & edges){
  int64_t mst_weight = 0;
  std::sort(edges.begin(), edges.end());
  for(size_t i = 0; (i < edges.size()) and union_find.get_num_sets() > 1 ; ++i) {  // and union_find.get_num_elements() == 1
    if(union_find.find_set(edges[i].source) != union_find.find_set(edges[i].dest)){
      union_find.unite(edges[i].source, edges[i].dest);
      mst_weight += edges[i].weight;
    }
  }
  return mst_weight;
  
}

int main() {
  
  int V, E;
  int src, dst, w;
  
  std::cin >> V >> E;
  
  std::vector<Edge> edges;
  edges.reserve(E);
  DisjointSet union_find(V);
  
  for (size_t i = 0; i < E; ++i) {
    std::cin >> src >> dst >> w;
    edges.emplace_back(Edge {--src, --dst, w});
    union_find.make_set(src);
    union_find.make_set(dst);
  }

  auto result = kruskal(union_find, edges);
  
  std::cout << result << std::endl;
  return 0;
}
