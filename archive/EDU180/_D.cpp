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

#include <bits/stdc++.h>
using namespace std;

void TC() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // node with 0 out, node with 2. out -> N -> out
    for(int i = 0; i < n; i++) {
        if (adj[i].size() == 2) {
            cout << "YES" << '\n';
            int f = adj[i][0];
            int s = adj[i][1];
            // F should be out, S should be out.

            cout << s + 1 << ' ' << i + 1 << '\n';
            cout << i + 1 << ' ' << f + 1 << '\n';
            
            vector<bool> checked(n, 0);
            checked[i] = 1;
            auto dfs = [&](auto dfs, int cur, int j, int c) {
                if (checked[cur]) return;
                checked[cur] = 1;
                if (c == 1) {
                    for(auto e : adj[cur]) {
                        if (e == i) {
                            continue;
                        }
                        cout << cur + 1 << ' ' << e + 1 << '\n';
                    }
                }
                for(auto e : adj[cur]) if (cur != j) {
                    dfs(dfs, e, cur, c ^ 1);
                }
            };
            dfs(dfs, f, -1, 0); // 0 is in.
            dfs(dfs, s, -1, 1); // 1 is out.

            return;
        }
    }
    cout << "NO" << '\n';
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