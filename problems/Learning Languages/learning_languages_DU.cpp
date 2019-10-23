#include <iostream>
#include <vector>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";

std::vector<int> parent(100);
std::vector<int> ranks(100);

void make_set(int emp) {
  parent[emp] = emp;
  ranks[emp] = 0;
}

int find(int a) {
  if(a == parent[a])	return a;
  
  int x = find(parent[a]);
  parent[a] = x;
  return x;
}

int link(int x, int y) {
  if (x == y) return 0;
  if (ranks[x] > ranks[y]) std::swap(x,y);
  parent[x] = y;
  ranks[y] += ranks[x];
  return 1;
}

int unite(int x, int y) {
  link(find(x), find(y));
}


int main() {
  std::ios_base::sync_with_stdio(false);
  size_t n, m, num_lang_known, lang_j;
  std::cin >> n >> m;
  std::vector<std::vector<size_t>> langs_known_by(m);
  
  int component = n;
  int emp_zero_knowledge = 0; 
	
  for(size_t emp_i = 0; emp_i < n; ++emp_i) {
    make_set(emp_i);
    std::cin >> num_lang_known;
    if(!num_lang_known)	emp_zero_knowledge++;
    else {
      for(size_t j = 0; j < num_lang_known; ++j) {
        std::cin >> lang_j;
        langs_known_by[--lang_j].push_back(emp_i);
      }
    }
  }

  if(emp_zero_knowledge == n)	{ 
    std::cout << component << std::endl;
    return 0;
  }
  
  for(size_t i = 0; i < m; ++i) {
    int emps_lang_i = langs_known_by[i].size()-1;
    if( emps_lang_i > 0) {
      for(size_t j = 0; j < emps_lang_i; ++j) {
        component -= unite(langs_known_by[i][j], langs_known_by[i][j+1]);
      }
    }
  }
  
  std::cout << --component << std::endl;
  return 0;
}
