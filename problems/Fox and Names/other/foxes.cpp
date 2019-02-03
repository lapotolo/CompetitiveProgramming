#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>

std::string ALPHABETS = "abcdefghijklmnopqrstuvwxyz";

class DiGraph {
public:
	DiGraph(const int &v) : num_verts(v) 
	{
		m_g.reserve(num_verts);
		for (int i = 0; i < num_verts; ++i) m_g.push_back({});
	}
    
	bool has_edge(int const& v, int const& w) { return m_g[v].find(w) == m_g[v].end() ? false : true; }
    
	void add_edge(int const& v, int const& w) { m_g[v].insert(w); }
    
	std::set<int> get_adj_set(const int &v) const { return m_g[v]; }
    
	int get_num_vertices() const { return num_verts; }
    
	void print() 
	{
		for (int i = 0; i < num_verts; ++i) {
			std::cout << i << " : ";
			for (auto const& v : get_adj_set(i)) std::cout << v << " ";			
			std::cout << std::endl;
		}
	}
    
private:
	const int num_verts;
	std::vector< std::set<int> > m_g; // implemented via black-red tree 

};

class Topological_Order {
public:
	Topological_Order(DiGraph const& g)
	{
		//for (int i = 0; i < g.get_num_vertices(); ++i) visited.push_back(false);
		visited.resize(g.get_num_vertices(), false);
		for (int u = 0; u < g.get_num_vertices(); ++u)
			if (!visited[u]) 
				dfs(g, u);
	}

	std::deque<char> order; // used as stack
	
private:
	std::vector<bool> visited;

	void dfs(DiGraph const& g, int const& v)
	{
		visited[v] = true;
		for (auto const& w : g.get_adj_set(v)) {
			if (!visited[w])
				dfs(g, w);
		order.push_front(ALPHABETS[v]);
		}
	}
};

class DiCycle
{
public:
	bool has_cycle;

	DiCycle(DiGraph const& g) : has_cycle(false)
	{
		on_stack.resize(g.get_num_vertices(), false);
		visited.resize(g.get_num_vertices(), false);
		for (int i = 0; i < g.get_num_vertices(); ++i) {
			if (!visited[i] and !has_cycle) dfs(g, i);
		}
	}
	
private:
	std::vector<bool> on_stack;
	std::vector<bool> visited;

	void dfs(const DiGraph &g, const int &v)
	{
		if (has_cycle) return;
		
		on_stack[v] = true;
		visited[v] = true;
		
		for (auto const& w : g.get_adj_set(v)) {
			if (!visited[w]) dfs(g, w);
			else if (on_stack[w]) {
				has_cycle = true;
				return;
			}
		}
		on_stack[v] = false;
	}	

};

int main() {
	int n;
	std::string a, b;
	std::cin >> n;

	DiGraph graph(ALPHABETS.size());	
	
	std::map<char, int> m_map;
	for (int i = 0; i < ALPHABETS.size(); ++i) m_map[ALPHABETS[i]] = i; // m_map['a'] = 0 ... m_map['z'] = 25
	
	std::cin >> a;
	for (int i = 0; i < n-1; ++i) { // for each word
		std::cin >> b;
		for (int j = 0; j < a.size() && j < b.size(); ++j) {
			if (a[j] != b[j]) {
				graph.add_edge(m_map[a[j]], m_map[b[j]]);
				break;
			} 
			if ((j == b.size() - 1) 
					&& (a.size() > b.size())) {
				std::cout << "Impossible";
				return 0;
			}
		}	
		swap(a, b);
	}
	
	DiCycle cycle(graph);
	if (cycle.has_cycle) { std::cout << "Impossible"; return 0; }

	Topological_Order topo_sort(graph);
	
	for (auto const& c : topo_sort.order) { std::cout << c; }
	
	return 0;
}