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

void TC() {
    int n; cin >> n;
    // cout << n << endl;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    map<int, int> cnts;
    for(int i = 0; i < n; i++) {
        cnts[adj[i].size()]++;
    }
    int best = 0;
    // for(auto e : adj) {
    //     cout << e.size() << endl;
    // }
    for(int i = 0; i < n; i++) {
        // Assum,e removing curr.
        // Take all around out of consideration
        int base = 1;
        // cout << "ON i: " << i << endl;
        base += int(adj[i].size()) - 1;
        // cout << "A " << int(adj[i].size()) - 1 << endl;
        vector<int> toremove = {};
        cnts[int(adj[i].size())]--;
        if (cnts[int(adj[i].size())] == 0) {
            cnts.erase(int(adj[i].size()));
        }
        for(auto e : adj[i]) {
            toremove.push_back(adj[e].size());
        }
        for(auto e : toremove) {
            cnts[e]--;
            cnts[e-1]++;
            if (cnts[e] == 0) {
                cnts.erase(e);
            }
        }
        // After update
        base += cnts.rbegin()->first - 1;
        // cout << "A " << cnts.rbegin()->first - 1 << endl;
        best=max(best,base);
        
        for(auto e : toremove) {
            cnts[e-1]--;
            cnts[e]++;
            if (cnts[e-1] == 0) {
                cnts.erase(e-1);
            }
        }
        
        cnts[int(adj[i].size())]++;
    }
    cout << best << endl;
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