#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    vector<ll> t(n);
    for(auto &e : v) cin >> e;
    for(auto &e : t) cin >> e;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll dsum = 0;
    for(int i = 0; i < n; i++) {
        dsum += abs(v[i] - t[i]);
    }
    if (dsum & 1) {
        cout << "NO" << endl;
        return;
    }
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
    bool isvalid = isValidColoring(isValidColoring, 0, -1, 0);
    // cout << "IS VALID: " << isvalid << endl;
    if (!isvalid) {
        cout << "YES" << endl;
        return;
    }
    else {
        vector<bool> seen(n);
        auto dfs = [&](auto dfs, int i, int j) -> ll {
            // bool isleaf = true;
            if (seen[i]) return 0;
            seen[i] = true;
            ll cv = v[i];
            for(auto e : adj[i]) if (e != j) {
                // isleaf = false;
                cv += dfs(dfs, e, i);
            }
            ll change = t[i] - cv;
            return change;
        };
        ll tc = dfs(dfs, 0, -1);
        if (tc == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
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