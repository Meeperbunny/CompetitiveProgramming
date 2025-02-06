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


ll least[200001];
void setLeast(int c, int l, vector<vector<int>> &adj) {
    least[c] = c;
    for(auto e : adj[c]) if (e != l) {
        setLeast(e, c, adj);
        least[c] = max(least[e], least[c]);
    }
}


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

void TC() {
    ll n, w; cin >> n >> w;
    vector<vector<int>> adj(n);
    for(ll i = 0; i < n - 1; i++) {
        ll j; cin >> j;
        j--;
        adj[i + 1].push_back(j);
        adj[j].push_back(i + 1);
    }
    memset(least, 0, sizeof(least));
    setLeast(0, -1, adj);
    vector<ll> unknown(n, 0);
    initLca(adj);
    for(ll i = 0; i < n; i++) {
        unknown[i] = depth[i] + depth[(i + 1) % n] - 2 * depth[lca(i, (i + 1) % n)];
    }
    ll M = w;
    vector<ll> mf(n, 0);
    vector<ll> cont(n, M);
    ll TS = 0;
    ll FC = 0;
    ll tot = M * n;
    for(int i = 0; i < n - 1; i++) {
        ll j, we;
        cin >> j >> we;
        TS += we;
        ll up = j - 2;
        ll low = least[j - 1];
        for(auto e : {low, up}) {
            tot -= cont[e];
            unknown[e]--;
            mf[e] += we;
            tot += we;
            if (unknown[e] == 0) {
                FC++;
                cont[e] = mf[e];
                tot -= mf[e];
            }
            tot += cont[e];
        }
        cout << tot - (TS * (n - FC)) << ' ';
    }
    cout << endl;
}

int main() {
    HEADER;
    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++) {
        TC();
    }
    return 0;
}