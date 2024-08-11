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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(61, -1000000));
    int mav = 0;
    for(int i = 1; i <= n; i++) {
        int c = a[i - 1];
        dp[i][c + 30] = c;
        for(int q = 0; q <= 60; q++) {
            dp[i][max(c + 30, q)] = max(dp[i][max(c + 30, q)], dp[i - 1][q] + c);
        }
        for(int q = 0; q <= 60; q++) {
            mav = max(dp[i][q] - (q - 30), mav);
        }
    }
    cout << mav << endl;
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