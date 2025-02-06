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

typedef pair<ll, ll> pll;
typedef pair<pair<ll, ll>, bool> pllb;
pair<vector<ll>, vector<ll>> dijkstra_mod(int source, vector<vector<pll>>& adj, set<ll>& hasHorse) {
    int n = adj.size();
    vector<ll> dist(n, LLONG_MAX);
    vector<ll> distHorse(n, LLONG_MAX);
    priority_queue<pllb, vector<pllb>, greater<pllb>> pq;
    bool isg = hasHorse.count(source);
    if (!isg) {
        dist[source] = 0;
        pq.push({{0, source}, 0});
    }
    else {
        distHorse[source] = 0;
        pq.push({{0, source}, 1});
    }
    while (!pq.empty()) {
        ll d = pq.top().first.first;
        int u = pq.top().first.second;
        bool has = pq.top().second;
        pq.pop();
        if (hasHorse.count(u)) {
            has |= 1;
        }
        if (has && d > distHorse[u]) continue;
        else if (!has && d > dist[u]) continue;
        if (has) distHorse[u] = d;
        else dist[u] = d;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            ll weight = edge.second;
            if (has) {
                weight /= 2;
                if (distHorse[u] + weight < distHorse[v]) {
                    distHorse[v] = distHorse[u] + weight;
                    pq.push({{distHorse[v], v}, has});
                }
            }
            else {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({{dist[v], v}, has});
                }
            }
        }
    }
    return {dist, distHorse};
}

void TC() {
    int n,m,h; cin >> n>>m>>h;
    set<ll> hasHorse;
    vector<vector<pll>> adj(n);
    while(h--) {
        int q; cin >> q;
        hasHorse.insert(q-1);
    }
    while(m--) {
        int a, b,w;cin>>a>>b>>w;
        a--,b--;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    auto f = dijkstra_mod(0, adj, hasHorse);
    auto s = dijkstra_mod(n - 1, adj, hasHorse);
    ll mt = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        mt = min({mt, max(f.first[i], s.first[i]), max(f.second[i], s.first[i]), max(f.first[i], s.second[i]), max(f.second[i], s.second[i])});
    }
    cout << (mt == LLONG_MAX ? -1 : mt) << endl;
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