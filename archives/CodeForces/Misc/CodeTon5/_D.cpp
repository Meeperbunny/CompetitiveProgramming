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

void TC() {
    int n, m;
    cin >> n >> m;
    vector<ll> limits(n + 1, LLONG_MAX);
    limits[n] = 0;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    queue<pair<ll, ll>> Q;
    Q.push({n, 0});
    while(!Q.empty()) {
        ll ind = Q.front().first, lim = Q.front().second;
        Q.pop();
        if (lim != limits[ind]) continue;
        // For each adj, set new limit. Check if lim is lower, and if it is update lim and push new el
        for(auto &e : adj[ind]) {
            ll el = e.first, va = e.second;
            if (lim + va < limits[el]) {
                limits[el] = lim + va;
                Q.push({el, lim + va});
            }
        }
    }
    if (limits[1] == LLONG_MAX) {
        cout << "inf" << endl;
    }
    else {
        vector<pair<string, ll>> ans;
        ll curr = 0;
        ll tt = limits[1];
        while(curr != tt) {
            string bstring(n, '0');
            ll mtg = LLONG_MAX;
            for(int i = 1; i <= n; i++) {
                if (limits[i] > curr) {
                    mtg = min(mtg, limits[i] - curr);
                    bstring[i - 1] = '1';
                }
            }
            ans.push_back({bstring, mtg});
            curr += mtg;
        }
        cout << tt << ' ' << ans.size() << endl;
        for(auto e : ans) {
            cout << e.first << ' ' << e.second << endl;
        }

    }
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