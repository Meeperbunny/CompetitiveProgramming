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
    int n; cin >> n;
    vector<vector<bool>> grid(n, vector<bool>(n));
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int q = 0; q < n; q++) {
            grid[i][q] = s[q] == '*';
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = grid[0][0] ? 0 : 1;
    const int mod = 1e9 + 7;
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < n; q++) {
            if (grid[i][q]) continue;
            if (i != 0) {
                dp[i][q] = (dp[i][q] + dp[i - 1][q]) % mod;
            }
            if (q != 0) {
                dp[i][q] = (dp[i][q] + dp[i][q - 1]) % mod;
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
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