// topological sort is computed using the "in-degree algorithm":
// source: https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>

#define GET_NODE(s, i) sigma[(s[i]-97)]

struct node{
  char letter;
  int color, fan_in;
  std::vector<node*> next_letters;
  
};


std::vector<node> sigma;
std::vector<char> result;
bool error = false;

bool has_edge(node & a, char bi) {
    bool match = false;
    size_t num_children = a.next_letters.size();
    
    if (a.next_letters.empty()) return false;
    for(size_t i = 0; i < num_children && !match; ++i)
      if (a.next_letters[i]->letter == bi) match = true;
    
    return match;
}

void build_alphabet(std::string const& s1, std::string const& s2) {
  size_t i = 0;
  size_t shorter_length = std::min(s1.size(), s2.size());
  
  while (i < shorter_length && s1[i] == s2[i]) i++; // move i on first mismatch
  
  if (i < shorter_length) { // mismatch
    if (!has_edge(GET_NODE(s1, i), s2[i])) { // check if the edge a[i] -> b[i] already exists
      GET_NODE(s1, i).next_letters.push_back(&GET_NODE(s2, i));
      GET_NODE(s2, i).fan_in++;
    }
  } else if (shorter_length == s2.size() && shorter_length < s1.size()) error = true;
}

bool topological_sort() {
  std::queue<node*> q;
  size_t counter = 0;
  
  for (auto& n : sigma) // enqueue every node with fan-in 0
    if (n.fan_in == 0)
      q.push(&n);
  
  while (!q.empty()) {
    node* n = q.front();
    q.pop();
    result.push_back(n->letter);
    for (auto& c : n->next_letters) {
      c->fan_in--;
      if (c->fan_in == 0)
        q.push(c);
    }
    counter++;
  }
  return (counter == 26); //all the letters of the alphabet
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
  size_t n;
  std::cin >> n;
  
  for (int i=97; i<123; ++i)
    sigma.emplace_back(node {char{i}, int{0}, {}});
  
  std::string s1, s2;
  std::cin >> s1;
  for (size_t i = 1; i < n; ++i) {
    std::cin >> s2;
    build_alphabet(s1, s2);
    if (error) { std::cout << "Impossible"; return 0; }
    swap(s1, s2);
  }
  
  if (topological_sort()) {
    for (auto r : result) std::cout << r;
    std::cout << std::endl;
    } else std::cout << "Impossible";
  
  return 0;
}
