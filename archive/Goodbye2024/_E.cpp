#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void dfs(int c, int l, vector<vector<int>> &adj, vector<ll> &down, vector<bool>&isleaf, vector<bool>&isnexttoleaf, vector<int> &par) {
    int mc = 0;
    down[c] = (!isleaf[c] && !isnexttoleaf[c]);
    for(auto e : adj[c]) {
        if (e != l) {
            par[e] = c;
            dfs(e, c, adj, down, isleaf, isnexttoleaf, par);
            down[c] += down[e];
        }
    }
}

void dfsup(int c, int l, vector<vector<int>> &adj, vector<ll> &up, vector<ll> &down, vector<int> &par, vector<bool>&isleaf, vector<bool>&isnexttoleaf) {
    // my up is up + down of parent - down of mine.
    if (par[c] == -1) {
        up[c] = (!isleaf[c] && !isnexttoleaf[c]);
    }
    else {
        up[c] = up[par[c]] + down[par[c]] - (!isleaf[par[c]] && !isnexttoleaf[par[c]]) - down[c] + (!isleaf[c] && !isnexttoleaf[c]);
    }
    for(auto e : adj[c]) {
        if (e != l) {
            dfsup(e, c, adj, up, down, par, isleaf, isnexttoleaf);
        }
    }
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
    vector<bool> isleaf(n);
    vector<bool> isnexttoleaf(n);
    for(int i = 0; i < n; i++) {
        isleaf[i] = adj[i].size() <= 1;
    }
    // for(auto e : isleaf) cout << e << ' ';
    // cout << endl;
    for(int i = 0; i < n; i++) {
        for(auto e : adj[i]) {
            if (isleaf[e]) isnexttoleaf[i] = true;
        }
    }
    // for(auto e : isnexttoleaf) cout << e << ' ';
    // cout << endl;
    // First all leaf times non leaf
    ll lc = accumulate(all(isleaf), 0ll);
    ll t = lc * ll(n - lc);
    // For each non leaf node, for all the nodes that are next to a leaf node, get all non next to leaf adjacent to that.
    // represent as a tree to find these counts.
    vector<ll> nonLeafOrNextToDown(n);
    vector<int> p(n, -1);
    dfs(0, -1, adj, nonLeafOrNextToDown, isleaf, isnexttoleaf, p);
    vector<ll> downsum(n);
    vector<ll> nonLeafOrNextToUp(n);
    dfsup(0, -1, adj, nonLeafOrNextToUp, nonLeafOrNextToDown, p, isleaf, isnexttoleaf);
    for(int i = 0; i < n; ++i) {
        for(auto e : adj[i]) {
            if (i == 1) {
                // cout << "SUB " << e << ' ' << isnexttoleaf[e] << ' ' << isleaf[i] << endl;
            }
            if (isnexttoleaf[e] && !isleaf[i]) {
                ll ta = 0;
                if (e == p[i]) {
                    if (e == 0) {
                        ta += nonLeafOrNextToDown[e];
                        ta -= nonLeafOrNextToDown[i];
                    }
                    else {
                        ta += nonLeafOrNextToUp[e];
                        ta += nonLeafOrNextToDown[e];
                        ta -= nonLeafOrNextToDown[i];
                        // cout << i << ' ' << e << ' ' << "UP " << nonLeafOrNextToUp[e] << endl;
                    }
                }
                else {
                    ta += nonLeafOrNextToDown[e];
                    // cout << i << ' ' << e << ' ' << nonLeafOrNextToDown[e] << endl;
                }
                t +=ta;
            }
        }
    }
    // for(int i = 0; i < n; i++) {
    //     cout << nonLeafOrNextToUp[i] << ' ';
    // } cout << endl;
    cout << t<< endl;
    
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