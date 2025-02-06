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

void TC() {
    ll n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for(int i = 1; i <= n; i++) {
        char cc = s[i - 1];
        // Play each
        //R
        if (cc != 'P')
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + int(cc == 'S');
        //P
        if (cc != 'S')
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + int(cc == 'R');
        //S
        if (cc != 'R')
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + int(cc == 'P');
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
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