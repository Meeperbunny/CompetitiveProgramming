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
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int a,b;cin>>a>>b;a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int en = 2;
    int on = n * 2;
    vector<int> label(n);
    auto dfs = [&](auto dfs, int i, int j, int d) -> void {
        if (d % 2 == 0) {
            label[i] = en;
            en += 2;
        }
        else {
            label[i] = on;
            on -= 2;
        }
        for(auto e : adj[i]) {
            if (e == j) continue;
            dfs(dfs, e, i, d + 1);
        }
    };
    dfs(dfs, 0, -1, 0);
    for(int j = 0; j < n; j++) {
        for(auto i : adj[j]) {
            if (abs(label[i] - label[j]) == 2) {
                if (adj[i].size() == 1) {
                    label[i] = label[j] - 1;
                }
                else {
                    label[j] = label[i] - 1;
                }
            }
        }
    }
    for(auto e : label) cout << e << ' ';
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