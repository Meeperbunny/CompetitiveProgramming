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

ll dp[300001][20];

void dfs(int c, int l, vector<vector<int>> &adj, vector<ll> &cost) {
    for(ll i = 0; i < 20; i++) {
        dp[c][i] = cost[c] * (i + 1);
    }
    for(auto e : adj[c]) {
        if (e != l) {
            dfs(e, c, adj, cost);
            // Childs is full, add min of ones not equal to i
            for(int i = 0; i < 20; i++) {
                ll mi = LLONG_MAX;
                for(int q = 0; q < 20; q++) {
                    if (q == i) continue;
                    mi = min(mi, dp[e][q]);
                }
                dp[c][i] += mi;
            }
        }
    }
}

void TC() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<ll> cost(n);
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < 20; q++) {
            dp[i][q] = LLONG_MAX;
        }
    }
    // Starting at 0, dfs down, and print min of all
    dfs(0, -1, adj, cost);
    ll mi = LLONG_MAX;
    for(int i = 0; i < 20; i++) mi = min(mi, dp[0][i]);
    cout << mi << endl;
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