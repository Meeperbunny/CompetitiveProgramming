ll depth[200001];
ll parent[200001];
ll blift[200001][20];
void lcaDfs(int c, int l, vector<vector<int>> &adj) {
    for(auto e : adj[c]) if (e != l) {
        parent[e] = c;
        depth[e] = depth[c] + 1;
        lcaDfs(e, c, adj);
    }
}
void initLca(vector<vector<int>> &adj) {
    ll n = adj.size();
    for(int i = 0; i < n; i++) depth[i] = 0;
    for(int i = 0; i < n; i++) parent[i] = -1;
    for(int i = 0; i < n; i++) for(int q = 0; q < 20; q++) blift[i][q] = -1;
    lcaDfs(0, -1, adj);
    for(int j = 0; j < 20; j++) {
        for(int i = 0; i < n; i++) {
            if (!j) {
                blift[i][j] = parent[i];
            }
            else {
                if (blift[i][j - 1] == -1) {
                    blift[i][j] = -1;
                }
                else {
                    blift[i][j] = blift[blift[i][j - 1]][j - 1];
                }
            }
        }
    }
}
ll lca(ll u, ll v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 19; i >= 0; i--) {
        if ((diff >> i) & 1) {
            u = blift[u][i];
        }
    }
    if (u == v) return u;
    for(int i = 19; i >= 0; i--) {
        while (blift[u][i] != -1 && blift[u][i] != blift[v][i]) {
            u = blift[u][i], v = blift[v][i];
        }
    }
    return parent[u];
}