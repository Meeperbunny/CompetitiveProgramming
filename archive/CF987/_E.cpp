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


void dfs(vector<vector<int>> &children, vector<int> &b, int i, int d) {
    int cc = children[i].size();
    if (cc == 0) {
        return;
    }
    int v = 0;
    vector<int> depths;
    for(auto e : children[i]) {
        dfs(children, b, e, d + 1);
        depths.push_back(b[e]);
        b[i] = max(b[i], b[e] + 1);
    }
    sort(depths.begin(), depths.end());
    int la = depths[0];
    int va = 0;
    for(auto e : depths) {
        if (e == la) {
            va++;
        }
        else {
            while(la < e && va != 1) {
                va = (va + 1) / 2;
                la++;
            }
            la = e;
            va++;
        }
    }
    while(va != 1) {
        va = (va + 1) / 2;
        la++;
    }
    b[i] = max(la, b[i]);
}

void TC() {
    int n; cin >> n;
    vector<vector<int>> children(n);
    for(int i = 1; i < n; i++) {
        int a; cin >> a; a--;
        children[a].push_back(i);
    }
    int ans = 0;
    vector<int> b(n, 0);
    dfs(children, b, 0, 0);
    cout << b[0] << '\n';
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