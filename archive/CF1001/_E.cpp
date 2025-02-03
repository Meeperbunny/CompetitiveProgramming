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
vector<int> a;
void dfs(int c, int l, vector<vector<int>> &adj, vector<map<int, int>> &cnts, map<int, int> &tcnts, vector<bool> &isc) {
    map<int, int> &mine = cnts[c];
    for(auto e : adj[c]) {
        if (e != l) {
            dfs(e, c, adj, cnts, tcnts, isc);
            map<int, int> &t = cnts[e];
            if (mine.size() < t.size())
                swap(mine, t);
            for(auto k : t) {
                mine[k.first] += k.second;
            }
        }
    }
    mine[a[c]]++;
    auto it = next(tcnts.find(a[c]));
    if (it == tcnts.end()) {
        // No greater, dont worry about this. It is self contained.
        isc[c] = 1;
    }
    else {
        int nxt = it->first;
        if (mine[nxt] == tcnts[nxt]) {
            isc[c] = 1;
        }
        else {
            isc[c] = 0;
        }
    }
}

void TC() {
    int n; cin >> n;
    a = vector<int>(n);
    vector<vector<int>> adj(n);
    for(auto &e : a) cin >> e;
    for(int i = 0; i < n - 1; ++i) {
        int a,b;cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    map<int, int> tcnts;
    for(auto e : a) tcnts[e]++;
    vector<map<int, int>> cnts(n);
    vector<bool> isc(n, 1);
    dfs(0, -1, adj, cnts, tcnts, isc);
    map<int, bool> fc;
    for(auto e : a) fc[e] = 1;
    for(int i = 0; i < n; i++) {
        int e = a[i];
        if (!isc[i]) fc[e] = 0;
    }
    // for(auto e : fc) {
    //     cout << e.first << ' ' << e.second << endl;
    // }
    int worksW = -1;
    for(auto it = next(fc.rbegin()); it != fc.rend(); it++) {
        int pt = prev(it)->first;
        if (fc[pt] && !fc[it->first]) {
            worksW = it->first;
            break;
        }
    }
    if (worksW != -1) {
        for(int i = 0; i < n; ++i) {
            if (a[i] == worksW && !isc[i]) {
                cout << i + 1 << '\n';
                return;
            }
        }
        return;
    }
    cout << 0 << '\n';
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