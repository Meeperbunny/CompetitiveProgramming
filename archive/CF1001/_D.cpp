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

ll ga = 0;
pair<ll, ll> dfs(int c, int l, vector<pair<ll, ll>> &r, vector<vector<int>> &adj) {
    dbg(c+1);
    vector<pair<ll, ll>> ps;
    for(auto e : adj[c]) {
        if (e != l) {
            ps.push_back(dfs(e, c, r, adj));
        }
    }
    pair<ll, ll> myp = r[c];
    ll la = 0;
    for(auto p : ps) {
        if (p.first > myp.second + la) {
            // Need to add to my pair, and add to others as a consequence.
            la += (p.first - (myp.second + la));
        }
        else if (p.second < myp.first + la) {
            // I can just add to the subtree as needed.
        }
        else {
            // We partially intersect, so become it.
            myp.first = max(myp.first, p.first - la);
            myp.second = min(myp.second, p.second - la);
        }
    }
    ga += la;
    dbg(c+1, myp.first, myp.second);
    return myp;
}

void TC() {
    ga = 0;
    int n; cin >> n;
    vector<pair<ll, ll>> ranges(n);
    for(auto &e : ranges) {
        cin >> e.first >> e.second;
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; ++i) {
        auto p = dfs(i, -1, ranges, adj);
        cout << p.first + ga << '\n';
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