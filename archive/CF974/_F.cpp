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

ll n, co;
void dfs(int c, int l, vector<vector<int>> &adj, vector<ll> &a, vector<ll> &N, vector<ll> &W) {
    // If I take without, then just sum of all before
    ll wosum = 0;
    ll wisum = a[c];
    for(auto e : adj[c]) {
        if (e == l) continue;
        dfs(e, c, adj, a, N, W);
        wosum += max(N[e], W[e]);
        wisum += max(N[e], W[e] - 2 * co);
    }
    N[c] = wosum;
    W[c] = wisum;
}

void TC() {
    cin >> n >> co;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int q, j;cin>>q>>j;
        q--,j--;
        adj[q].push_back(j);
        adj[j].push_back(q);
    }
    vector<ll> N(n, 0), W(n, 0);
    dfs(0, -1, adj, a, N, W);
    // for(int i = 0; i < n; i++) cout << N[i] << ' '; cout << endl;
    // for(int i = 0; i < n; i++) cout << W[i] << ' '; cout << endl;
    cout << max(N[0], W[0]) << endl;
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