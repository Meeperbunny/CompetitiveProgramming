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

ll dfs(int c, vector<vector<ll>> &adj, vector<ll> &va) {
    vector<ll> &madj = adj[c];
    if (c == 0) {
        ll mc = INT_MAX;
        for(auto e : madj) {
            mc = min(mc, dfs(e, adj, va));
        }
        return va[c] + mc;
    }
    else {
        if (madj.size() == 0) {
            return va[c];
        }
        else {
            ll mc = INT_MAX;
            for(auto e : madj) {
                mc = min(mc, dfs(e, adj, va));
            }
            assert(mc < INT_MAX && mc >= 0);
            if (va[c] > mc) {
                return mc;
            }
            else {
                return va[c] + ll((mc - va[c]) / 2);
            }
        }
    }
}

void TC() {
    int n; cin >> n;
    vector<ll> vas(n);
    for(auto &e : vas) cin >> e;
    vector<vector<ll>> adj(n);
    for(int b = 1; b < n; b++) {
        ll a;
        cin >> a;
        a--;
        adj[a].push_back(b);
        // adj[b].push_back(a);
    }
    cout << dfs(0, adj, vas) << endl;
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