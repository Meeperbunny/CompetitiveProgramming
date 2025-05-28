#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

vector<ll> djikstra(vector<vector<pair<ll, ll>>> &adj, int src) {
    int n = adj.size();
    vector<ll> result(n, LLONG_MAX);
    result[src] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        ll d = pq.top().first, node = pq.top().second;
        pq.pop();
        if (d != result[node])
            continue;
        for (auto &edge : adj[node]) {
            ll new_node = edge.first;
            ll weight = edge.second;
            if (result[new_node] > d + weight) {
                result[new_node] = d + weight;
                pq.push({result[new_node], new_node});
            }
        }
    }
    return result;
}

vector<ll> pchange(vector<vector<pair<ll, ll>>> &adj, int src) {
    int n = adj.size();
    vector<ll> firstSeen(n, -1);
    vector<ll> parityChange(n, LLONG_MAX);
    firstSeen[src] = 0;
    queue<pair<ll, ll>> Q;
    Q.push({src, 0});
    while (!Q.empty()) {
        auto [node, d] = Q.front();
        Q.pop();
        for(auto &[no, we] : adj[node]) {
            if (-1 == firstSeen[no]) {
                firstSeen[no] = d + 1;
                Q.push({no, d + 1});
            }
            else {
                if ((firstSeen[no] + (d + 1)) & 1) {
                    // Is parity change at d.
                    // cout << "PARITY CHANGE AT " << no << ' ' << d << endl;
                    parityChange[no] = d + 1;
                    continue;
                }
            }
        }
    }
    return parityChange;
}

vector<ll> Adjikstra(vector<vector<pair<ll, ll>>> &adj, vector<ll> &pc, int src) {
    int n = adj.size();
    vector<ll> result(n, LLONG_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for(int i = 0; i < pc.size(); i++) {
        if (pc[i] != LLONG_MAX) {
            result[i] = pc[i];
            pq.push({pc[i], i});
        }
    }
    while (!pq.empty()) {
        ll d = pq.top().first, node = pq.top().second;
        pq.pop();
        if (d != result[node])
            continue;
        for (auto &edge : adj[node]) {
            ll new_node = edge.first;
            ll weight = edge.second;
            if (result[new_node] > d + weight) {
                result[new_node] = d + weight;
                pq.push({result[new_node], new_node});
            }
        }
    }
    return result;
}

void TC() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<pair<ll, ll>>> adj(n);
    vector<ll> A(l);
    for(auto &e : A) cin >> e;
    while(m--) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back({b, 1});
        adj[b].push_back({a, 1});
    }
    auto distances = djikstra(adj, 0);
    auto pc = pchange(adj, 0);
    auto AD = Adjikstra(adj, pc, 0);
    ll ts = accumulate(all(A), 0ll);
    ll maxEven = 0;
    ll maxOdd = -1;
    ll minOdd = LLONG_MAX;
    for(auto e : A) {
        if ((e & 1) && e < minOdd) minOdd = e;
    }
    if (ts & 1) {
        maxOdd = ts;
        maxEven = maxOdd - minOdd;
    }
    else {
        maxEven = ts;
        if (minOdd != LLONG_MAX) maxOdd = maxEven - minOdd;
    }
    string s{};
    // cout << maxOdd << ' ' << maxEven << endl;
    // for(int i = 0; i < n; i++) cout << distances[i] << ' '; cout << endl;
    // for(int i = 0; i < n; i++) cout << AD[i] << ' '; cout << endl;
    for(int i = 0; i < n; i++) {
        auto &e = distances[i];
        char cc = '0';
        if (e & 1) {
            if (e <= maxOdd) cc = '1';
        }
        else {
            if (e <= maxEven) cc = '1';
        }
        auto E = AD[i];
        if (E != LLONG_MAX) {
            if (E & 1) {
                if (E <= maxOdd) cc = '1';
            }
            else {
                if (E <= maxEven) cc = '1';
            }
        }
        s += cc;
    }
    cout << s << endl;
    
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