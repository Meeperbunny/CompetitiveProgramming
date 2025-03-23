// This returns true and returns a bipartite coloring if the graph is capable of being colored as such. Otherwise it returns false.
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