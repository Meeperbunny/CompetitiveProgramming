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

vector<int> topo_sort(int n, vector<vector<int>> &adj) {
    vector<int> in_degree(n, 0), order;
    for (auto &v : adj) for (int u : v) in_degree[u]++;
    queue<int> q;
    for (int i = 0; i < n; i++) if (in_degree[i] == 0) q.push(i);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        order.push_back(v);
        for (int u : adj[v]) if (--in_degree[u] == 0) q.push(u);
    }
    return (order.size() == n) ? order : vector<int>{};
}


void TC() {
    int n; cin >> n;
    vector<string> a(n);
    for(auto &e : a) {
        cin >> e;
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < n; q++) {
            if (i == q) continue;
            if (a[i][q] == '1') {
                if (i > q) {
                    adj[q].push_back(i);
                }
                else {
                    adj[i].push_back(q);
                }
            }
            else {
                if (i > q) {
                    adj[i].push_back(q);
                }
                else {
                    adj[q].push_back(i);
                }
            }
        }
    }
    auto v = topo_sort(n, adj);
    for(auto e : v) cout << e+1 << ' ';
    cout << endl;
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