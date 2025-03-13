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
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    ll ans = 0;
    for(int sz = 2; sz < n; sz++) {
        for(int st = 0; st < n; st++) {
            for(int m = 1; m < sz; m++) {
                // Multiply these 3
                int sta = st;
                int enda = (st + sz) % n;
                int mida = (st + m) % n;
                ll va = a[sta] * a[enda] * a[mida];
                if (m >= 2) {
                    va += dp[(sta + 1) % n][m - 2];
                }
                if (sz - m >= 2) {
                    va += dp[(mida + 1) % n][sz - m - 2];
                }
                dp[st][sz] = max(dp[st][sz], va);
            }
            for(int rrb = 1; rrb <= sz; rrb++) {
                int rrba = (st + rrb) % n;
                int fsz = rrb - 1;
                int ssz = sz - fsz - 1;
                ll va = 0;
                if (fsz >= 2) {
                    va += dp[st][fsz];
                }
                if (ssz >= 2) {
                    va += dp[rrba][ssz];
                }
                dp[st][sz] = max(dp[st][sz], va);
            }
            ans = max(ans, dp[st][sz]);
        }
    }
    cout << ans << endl;
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