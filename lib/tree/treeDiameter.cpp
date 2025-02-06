pair<LL, LL> treeMaxDist(LL c, LL l, vector<vector<LL>> &adj) {
    pair<LL, LL> maxDist = { c, 0ll };
    for(const auto &e : adj[c]) {
        if (e != l) {
            pair<LL, LL> dist = treeMaxDist(e, c, adj);
            dist.second++;
            if (dist.second > maxDist.second) {
                maxDist = dist;
            }
        }
    }
    return maxDist;
}
LL getTreeDiameter(vector<vector<LL>> &adj) {
    pair<LL, LL> res = treeMaxDist(0, -1, adj);
    return treeMaxDist(res.first, -1, adj).second;
}