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

int len[10000];

void TC() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool hasoddlen = false;
    if (m == n - 1) {
        cout << "Bob" << endl;
        cout.flush();

        vector<int> colors(n, -1);
        int a, b;
        cin >> a >> b;
        cout << 1 << ' ' << a << endl;
        cout.flush();
        colors[0] = a;
        queue<pair<int, int>> Q;
        for(auto e : adj[0]) Q.push({e, a});
        for(int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            int cu = Q.front().first, ca = Q.front().second;
            Q.pop();

            int us = a;
            if (us == ca) us = b;

            colors[cu] = us;

            cout << cu + 1 << ' ' << us << endl;
            cout.flush();

            for(auto e : adj[cu]) if (colors[e] == -1) Q.push({e, us});
        }
    }
    else {
        cout << "Alice" << endl;
        cout.flush();
        for(int i = 0; i < n; i++) {
            cout << 1 << ' ' << 2 << endl;
            cout.flush();
            int q, c; cin >> q >> c;
        }
    }
}

int main() {
    // HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}