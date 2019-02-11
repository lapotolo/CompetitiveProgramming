int n = 10
int E = 2*n-1

int tree[n][E];
int sub[n];

int dfs(int u, int p) {
    for (auto v : tree[u])
        if (v != p) sub[u] += dfs(v, u);

    return sub[u] + 1;
}

int centroid(int u, int p) {
    for (auto v : tree[u])
        if (v != p and sub[v] > n/2) return centroid(v, u);

    return u;
}