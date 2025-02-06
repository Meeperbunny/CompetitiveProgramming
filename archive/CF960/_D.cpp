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

int dp[200001][3];

void TC() {
    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i <= n; i++) {
        dp[i][0] = n;
        dp[i][1] = n;
        dp[i][2] = n;
    }
    dp[0][0] = 0;
    dp[0][1] = n;
    dp[0][2] = n;
    for(int i = 0; i < n; i++) {
        int a = A[i];
        
        if (a == 0) {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][2]);
        }
        else {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 1);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 1);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][2] + 1);
            if (a <= 2) {
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 1);
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
            }
            if (a <= 4) {
                dp[i + 1][2] = min(dp[i + 1][2], dp[i][1] + 1);
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + 1);
            }
        }

        // cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
    }
    int i = n;
    // cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;
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