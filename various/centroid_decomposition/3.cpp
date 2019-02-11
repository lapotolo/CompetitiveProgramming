void dfs(int current, int parent) {
	size[current] = 0;
	for(size_t i = 0; i < adjacency_list[current].size(); ++i) {
		int next = adjacency_list[current][i];
		if(next == parent or deleted[next]) continue;
		dfs(next, current);
		size[current] += size[next] + 1;
	}
}

int findcenter(int current, int parent, int total){
  for(int i=0;i<(int)adjacency_list[current].size();i++) {
    int next = adjacency_list[current][i];  
    if(next == parent or deleted[next])continue;
    if(total/2 < size[current] + 1) return findcenter(next, current, total);
  }
    return current;
}

void divideandconquer(int current, int total) {
  if(total == 1) return;
  dfs(current, -1);
  int newcenter = findcenter(current, -1, total);
  delete[center] = 1;	
  // Add the conditions needed to be checked with the current center
  int sum = 0, nextinline = -1;
  for(size_t i = 0; i < (int)adjacency_list[center].size(); ++i) {
		int next = adjacency_list[center][i];
		if(delete[next]) continue;
		if(size[next] < size[center]) {
			divide_conquer(next, size[next] + 1);
			sum += size[next] + 1;
		}
		else nextinline = next;
	}
	if(nextline != -1) divide_conquer(nextinline, total - sum - 1);
	return ;
}