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

void TC() {
    int n, k;
    cin >> n >> k;
    vector<int> lp(k, n + 1);
    vector<vector<int>> jump(n + 2, vector<int>(k, n + 1));
    // for(auto &e : jump[n + 1]) e = n + 1;
    string s; cin >> s;
    for(int i = n; i >= 0; i--) {
        char cc = s[i - 1];
        // Update last pos, and set my jump to last pos?
        jump[i] = lp;
        lp[cc - 'a'] = i;
    }
    // Get min dist to end
    vector<int> minDist(n + 2, INT_MAX);
    minDist[n + 1] = 0;
    for(int i = n; i >= 0; i--) {
        for(auto e : jump[i]) {
            minDist[i] = min(minDist[i], 1 + minDist[e]);
        }
    }
    int q; cin >> q;
    while(q--) {
        string t; cin >> t;
        int cp = 0;
        // cout << "ON " << t << endl;
        for(auto c : t) {
            cp = jump[cp][c - 'a'];
            // cout << c << ' ' << cp << endl;
        }
        cout << minDist[cp] << '\n';
    }
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