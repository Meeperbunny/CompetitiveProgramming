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

int a[500001], b[500001];
bool isgood(int n, int m, int k) {
    int oc = 0, zc = 0;
    for(int i = 0; i < n; i++) {
        oc += int(a[i] >= m);
        zc += int(a[i] < m);
    }
    vector<int> dp(n, INT_MIN);
    dp[0] = int(a[0] >= m) * 2 - 1;
    for(int i = 1; i < n; i++) {
        int bb = int(a[i] >= m) * 2 - 1;
        if (i % k == 0) {
            dp[i] = max(dp[i - k], bb);
        }
        else {
            dp[i] = dp[i - 1] + bb;
            if (i >= k)
                dp[i] = max(dp[i - k], dp[i]);
        }
    }
    // for(auto e : dp) cout << e << ' ';
    // cout << endl;
    // dbg(m, oc, dp[n], zc);
    return dp[n - 1] > 0;
}

void TC() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    if (k >= n) {
        cout << b[int((n - 1) / 2)] << endl;
        return;
    }
    int z = -1;
    for(int j = n; j >= 1; j /= 2) {
        while(z + j < n) {
            if (isgood(n, b[z + j], k)) {
                z += j;
            } else break;
        }
    }
    cout << b[z] << endl;
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