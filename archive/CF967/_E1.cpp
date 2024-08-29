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

ll modpow(ll a, ll b, ll p){
    a %= p;
    if (a == 0) return 0;
    ll product = 1;
    while(b > 0){
        if (b&1){    // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    // you can also use b >> 1
    }
    return product;
}

ll inv(ll a, ll p){
    return modpow(a, p-2, p);
}

ll fac[1005];
ll ifac[1005];
ll inver[1005];

ll choose(ll i, ll k, ll p) {
    ll j = pow(2, i) - 1;
    return ((fac[j + k - 1] * ifac[j - 1]) % p * ifac[k]) % p;
};

void TC() {
    ll n, k, p;
    cin >> n >> k >> p;
    vector<vector<ll>> dp(n, vector<ll>(k + 1, 0));
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 1; i < 1005; i++) {
        fac[i] = (fac[i - 1] * i) % p;
        ifac[i] = inv(fac[i], p);
        inver[i] = inv(i, p);
    }

    for(int i = 0; i <= k; i++) {
        dp[0][i] = 1;
    }
    for(int i = 1; i < n; i++) {
        ll qpre = 0;
        for(int q = 0; q <= k; q++) {
            // Try spending X on a side. Multiply by 2 because we can do both sides.
            ll binom = 1;
            ll base = modpow(2, i, p);
            for(ll l = 0; l * 2 < q; l++) {
                int r = q - l;
                // l is on subtree
                // r is on dp
                ll rs = dp[i - 1][r];
                // dbg(q, i, l, choose(i, l, p), binom);
                ll ls = binom;
                // ll ls = choose(i, l, p);
                dp[i][q] += rs * ls * 2;
                dp[i][q] %= p;

                // cout << base + l << ' ' << l << endl;
                binom = (binom * (base + l - 1)) % p;
                binom = (binom * inver[l + 1]) % p;
                
            }
            if (q) {
                dp[i][q] += dp[i][q - 1];
                dp[i][q] %= p;
            }
        }
    }
    cout << dp[n - 1][k] << endl;
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