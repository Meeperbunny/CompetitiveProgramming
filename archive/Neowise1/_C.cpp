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
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(auto &e : a) for(auto &v : e) cin >> v;
    vector<int> h(n), v(n);
    for(auto &e : h) cin >> e;
    for(auto &e : v) cin >> e;
    vector<vector<ll>> dp(n, vector<ll>(2, LLONG_MAX));
    dp[0][0] = 0;
    dp[0][1] = h[0];
    for(int i = 1; i < n; i++) {
        ll cc = h[i];
        // Without doing antything
        bool isgNorm = true;
        bool isgSelfIncrease = true;
        bool isgNormLast = true;
        bool isgSelfIncreaseLast = true;
        for(int q = 0; q < n; q++) {
            if (a[i][q] == a[i - 1][q]) isgNorm = false;
            if (a[i][q] + 1 == a[i - 1][q]) isgSelfIncrease = false;
            if (a[i][q] == a[i - 1][q] + 1) isgNormLast = false;
            if (a[i][q] + 1 == a[i - 1][q] + 1) isgSelfIncreaseLast = false;
        }
        // cout << i << ' ' << isgNorm << ' ' << isgSelfIncrease << ' ' << isgNormLast << ' ' << isgSelfIncreaseLast << endl;
        if (dp[i - 1][0] != LLONG_MAX && isgNorm) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (dp[i - 1][0] != LLONG_MAX && isgSelfIncrease) dp[i][1] = min(dp[i][1], dp[i - 1][0] + h[i]);
        if (dp[i - 1][1] != LLONG_MAX && isgNormLast) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (dp[i - 1][1] != LLONG_MAX && isgSelfIncreaseLast) dp[i][1] = min(dp[i][1], dp[i - 1][1] + h[i]);
    }
    // for(auto e : dp) {
    //     for(auto v : e) cout << v << ' '; cout << endl;
    // }
    // cout << endl;
    if (dp[n - 1][0] == LLONG_MAX && dp[n - 1][1] == LLONG_MAX) {
        cout << -1 << endl;
        return;
    }
    ll ta = LLONG_MAX;
    for(auto e : dp[n - 1]) {
        if (e != LLONG_MAX) {
            // cout << "MI " << e << endl;
            ta = min(ta, e);
        }
    }
    dp = vector<vector<ll>>(n, vector<ll>(2, LLONG_MAX));
    dp[0][0] = 0;
    dp[0][1] = v[0];
    for(int i = 1; i < n; i++) {
        ll cc = v[i];
        // Without doing antything
        bool isgNorm = true;
        bool isgSelfIncrease = true;
        bool isgNormLast = true;
        bool isgSelfIncreaseLast = true;
        for(int q = 0; q < n; q++) {
            if (a[q][i] == a[q][i - 1]) isgNorm = false;
            if (a[q][i] + 1 == a[q][i - 1]) isgSelfIncrease = false;
            if (a[q][i] == a[q][i - 1] + 1) isgNormLast = false;
            if (a[q][i] + 1 == a[q][i - 1] + 1) isgSelfIncreaseLast = false;
        }
        if (dp[i - 1][0] != LLONG_MAX && isgNorm) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (dp[i - 1][0] != LLONG_MAX && isgSelfIncrease) dp[i][1] = min(dp[i][1], dp[i - 1][0] + v[i]);
        if (dp[i - 1][1] != LLONG_MAX && isgNormLast) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (dp[i - 1][1] != LLONG_MAX && isgSelfIncreaseLast) dp[i][1] = min(dp[i][1], dp[i - 1][1] + v[i]);
    }
    // for(auto e : dp) {
    //     for(auto v : e) cout << v << ' '; cout << endl;
    // }
    // cout << endl;
    if (dp[n - 1][0] == LLONG_MAX && dp[n - 1][1] == LLONG_MAX) {
        cout << -1 << endl;
        return;
    }
    ll tb = LLONG_MAX;
    for(auto e : dp[n - 1]) {
        if (e != LLONG_MAX) {
            // cout << "MIV " << e << endl;
            tb = min(tb, e);
        }
    }
    // cout << ta << ' ' << tb << endl;
    cout << ta + tb << endl;
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