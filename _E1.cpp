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

ll fac(ll n) {
    if (n > 1) return n * fac(n - 1);
    return 1;
}

ll choose(ll n, ll k) {
    return fac(n) / fac(n - k) / fac(k);
}

ll freeops(ll k, ll i) {
    ll n = pow(2, i);
    return choose(k + n - 1, n);
}



void TC() {
    ll n, k, p;
    cin >> n >> k >> p;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));

    for(int i = 0; i <= k; i++) {
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++) {
        vector<ll> &low = dp[i - 1];
        for(ll ops = 0; ops <= k; ops++)  {
            for(ll nothing = 0; nothing <= 0; nothing++) {
                for(ll left = 0; left <= ops - nothing; left++) {
                    ll right = (ops - nothing) - left;
                    if (left == right) continue;
                    if (left > right) {
                        dp[i][ops] += low[left] * freeops(right, i - 1);
                    }
                    else {
                        dp[i][ops] += low[right] * freeops(left, i - 1);
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int q = 0; q <= k; q++) {
            cout <<  dp[i][q] << ' ';
        } cout << endl;
    }
    cout << dp[n][k] << endl;
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