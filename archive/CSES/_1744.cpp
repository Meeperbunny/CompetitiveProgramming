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

int dp[501][501];

void TC() {
    for(int i = 1; i <= 500; i++) {
        for(int q = 1; q <= 500; q++) {
            dp[i][q] = INT_MAX;
            if (i == q) {
                dp[i][q] = 0;
                continue;
            }
            for(int j = 1; j < i; j++) {
                dp[i][q] = min(dp[i][q], dp[i - j][q] + dp[j][q] + 1);
            }
            for(int j = 1; j < q; j++) {
                dp[i][q] = min(dp[i][q], dp[i][q - j] + dp[i][j] +  1);
            }
        }
    }
    int a, b;
    cin >> a >> b;
    cout << dp[a][b] << endl;
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