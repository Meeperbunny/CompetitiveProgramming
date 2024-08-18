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


void dfs(int c, vector<map<int, int>> &adj) {
    cout << c + 1 << ' ';
    if (adj[c].size() == 0) return;
    int n = adj[c].begin()->first;
    adj[c].erase(adj[c].find(n));
    adj[n].erase(adj[n].find(c));
    dfs(n, adj);
}

void TC() {
    int n, m;
    cin >> n >> m;
    vector<map<int, int>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].insert({b, c});
        adj[b].insert({a, c});
    }
    for(int i = 0; i < n; i++) {
        if (adj[i].size() & 1) {
            int tr = -1;
            for(auto e : adj[i]) {
                if (e.second == 1) continue;
                if (e.second == 0 && adj[e.first].size() & 1) {
                    tr = e.first;
                    break;
                }
            }
            if (tr == -1) {
                cout << "NO" << endl;
                return;
            }
            adj[i].erase(adj[i].find(tr));
            adj[tr].erase(adj[tr].find(i));
        }
    }
    int cnt = 0;
    for(auto e : adj) {
        cnt += e.size();
    }
    cnt = cnt / 2 + 1;
    cout << "YES" << endl;
    cout << cnt << endl;
    dfs(0, adj);
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