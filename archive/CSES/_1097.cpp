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

ll dp[5001][5001];

void TC() {
    memset(dp, 0, sizeof(dp));
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    for(int sz = 1; sz <= n; sz++) {
        for(int l = 0; l + sz - 1 < n; l++) {
            int r = l + sz - 1;
            if (sz == 1) {
                dp[l][r] = a[l];
            }
            else {
                dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
            }
        }
    }
    cout << (accumulate(all(a), 0ll) + dp[0][n - 1]) / 2 << endl;

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