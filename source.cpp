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

void dfs(ll c, ll l, ll lc, vector<vector<pair<int, int>>> &adj, vector<int> &ans, int mac) {
    // Assign each one some arbitrary color, assuming you havent used the color in yours
    // If greater, then use any color
    int currColor = 1;
    for(auto e : adj[c]) {
        if (e.first != l) {
            // For each edge, assign new color, if curr col is lc, then increment.
            // adj size is greater than mac, then set all to lc.
            if (adj[c].size() > mac) {
                if (lc == 0) {
                    lc = 1;
                }
                ans[e.second] = lc;
                dfs(e.first, c, lc, adj, ans, mac);
            }
            else {
                if (currColor == lc) currColor++;
                if (currColor > mac) currColor = 1;
                if (currColor == lc) currColor++;
                if (currColor > mac) currColor = 1;
                ans[e.second] = currColor;
                dfs(e.first, c, currColor, adj, ans, mac);
                currColor++;
            }
        }
    }
}

void TC() {
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> ans(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    vector<int> degreeCount(n, 0);
    for(auto e : adj) degreeCount[e.size()]++;
    for(int q = n - 2; q >= 0; q--) {
        degreeCount[q] += degreeCount[q + 1];
    }
    int mac = -1;
    for(int i = 1; i < n; i++) {
        if (degreeCount[i + 1] <= k) {
            mac = i;
            break;
        }
    }
    
    dfs(0, -1, 0, adj, ans, mac);
    cout << mac << endl;
    for(int i = 0; i < n - 1; i++) {
        cout << ans[i] << ' ';
    } cout << endl;
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