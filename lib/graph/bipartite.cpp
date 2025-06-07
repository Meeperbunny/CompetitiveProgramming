#include <bits/stdc++.h>
using namespace std;

/// @brief Returns a valid bipartite coloring if one exists. Otherwise returns an empty vector.
vector<int> getValidColoring(vector<vector<int>> &adj) {
    const int n = adj.size();
    vector<int> colors(n, -1);
    auto isValidColoring = [&](auto isValidColoring, int i, int j, int color) -> bool {
        colors[i] = color;
        for(auto e : adj[i]) if (e != j) {
            if (colors[e] == -1) {
                if (!isValidColoring(isValidColoring, e, i, color ^ 1)) {
                    return false;
                }
            }
            else {
                int ec = color ^ 1;
                if (ec != colors[e]) {
                    return false;
                }
            }
        }
        return true;
    };
    bool hasValidColoring = isValidColoring(isValidColoring, 0, -1, 0);
    return hasValidColoring ? colors : vector<int>{};
}