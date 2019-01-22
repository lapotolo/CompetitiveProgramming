#define ROSE 1

//first call should be query(u, -1)
// query time is O(n)
int query(int u, int p) {
    if (color[u] == ROSE) return 0;

    int mn = oo;

    for (auto v : tree[u])
        if (v != p)
            mn = min(mn, query(v, u));

    return mn + 1;
}

// update time is O(1)
void update(int a) {
    color[a] = ROSE;
}


// other way round
// update function should be initially called as update(u, -1, 0).
int query(int u) {
    return ans[u];
}

void update(int u, int p, int d) {
    ans[u] = min(ans[u], d);

    for (auto v : tree[u])
        if (v != p)
            update(v, u, d+1);
}
