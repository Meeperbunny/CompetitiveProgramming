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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n + 1);
    vector<vector<ll>> dp(x + 1, vector<ll>(n + 1, LLONG_MIN));
    vector<vector<bool>> checked(x + 1, vector<ll>(n + 1, false));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    multiset<ll, greater<ll>> tab;
    for(int q = 1; q <= x; q++) {
        tab.clear();
        for(int i = 1; i <= n; i++) {
            tab.insert(dp[q - 1][i - 1]);
            if (i > k) {
                tab.erase(tab.find(dp[q - 1][i - 1 - k]));
            }
            ll res = *tab.begin();
            if (res >= 0) dp[q][i] = res + a[i];
            else dp[q][i] = LLONG_MIN;
        }
    }
    ll ma = 0;
    for(int i = n - (k - 1); i <= n; i++) {
        ma = max(dp[x][i], ma);
    }
    if (ma <= 0) {
        ma = -1;
    }
    cout << ma << endl;
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