#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// https://codeforces.com/blog/entry/57593
int OneCentroid(int root, const vector<vector<int>> &g, const vector<bool> &dead) {
    int k = g.size();
    vector<int> sz(k);
    function<void (int, int)> get_sz = [&](int u, int prev) {
            sz[u] = 1;
            for (auto v : g[u]) if (v != prev && !dead[v]) {
                    get_sz(v, u);
                    sz[u] += sz[v];
            }
    };
    get_sz(root, -1);
    int n = sz[root];
    function<int (int, int)> dfs = [&](int u, int prev) {
            for (auto v : g[u]) if (v != prev && !dead[v]) {
                    if (sz[v] > n / 2) {
                            return dfs(v, u);
                    }
            }
            return u;
    };
    return dfs(root, -1);
}

void TC() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // Find a leaf and get rid of the edge
    vector<int> dead(n, 0);
    for(int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            int other = adj[i][0];
            if (i > other) {
                swap(i, other);
                swap(adj[i], adj[other]);
            }
            adj[i] = vector<int>();
            auto it = find(adj[other].begin(), adj[other].end(), i);
            adj[other].erase(it);
            dead[i] = true;
            break;
        }
    }
    // Find the centroid and do a list of direction -> idx, sorted by size. How to make it equal?
}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}