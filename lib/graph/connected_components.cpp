vector<vector<int>> getConnectedComponents(vector<vector<int>> &adj) {
    const int n = adj.size();
    vector<vector<int>> ret;
    vector<bool> seen(n, false);
    for(int i = 0; i < n; i++) {
        if (!seen[i]) {
            ret.push_back({});
            queue<int> Q;
            Q.push(i);
            seen[i] = true;
            while(Q.size()) {
                int c = Q.front();
                Q.pop();
                seen[c] = true;
                for(auto e : adj[c]) {
                    if (!seen[e]) {
                        Q.push(e);
                        seen[e] = true;
                    }
                }
            }
        }
    }
    return ret;
}