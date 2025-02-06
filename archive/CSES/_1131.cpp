#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

pair<ll, ll> treeMaxDist(ll c, ll l, vector<vector<ll>> &adj) {
    pair<ll, ll> maxDist = { c, 0ll };
    for(const auto &e : adj[c]) {
        if (e != l) {
            pair<ll, ll> dist = treeMaxDist(e, c, adj);
            dist.second++;
            if (dist.second > maxDist.second) {
                maxDist = dist;
            }
        }
    }
    return maxDist;
}
ll getTreeDiameter(vector<vector<ll>> &adj) {
    pair<ll, ll> res = treeMaxDist(0, -1, adj);
    return treeMaxDist(res.first, -1, adj).second;
}

void TC() {
    int n; cin >> n;
    vector<vector<ll>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << getTreeDiameter(adj) << endl;
}

int main() {
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}