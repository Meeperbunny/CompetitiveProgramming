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

ll tri(ll i) {
    return i * (i + 1) / 2;
}

ll ans(ll k, ll n, ll i) {
    ll ls = tri(i);
    ll rs = tri(n - 1) - tri(i);
    ls += k * (i + 1);
    rs += k * ((n - 1) - i);
    // cout << i << ' ' << rs << ' ' << ls << endl;
    // cout << endl;
    return abs(rs - ls);
}

void TC() {
    ll n, k;
    cin >> n >> k;
    // for(int i = 0; i < 6; i++) {
    //     cout << i << ' ' << ans(k, n, i) << endl;
    // }
    ll i = 0;
    for(ll q = n; q >= 1; q >>= 1)  {
        while(true) {
            ll nind = i + q;
            ll nnind = i + 2 * q;
            if (nnind >= n) {
                break;
            }
            ll a = ans(k, n, i);
            ll b = ans(k, n, nind);
            ll c = ans(k, n, nnind);
            if (a >= b && b >= c) {
                i += q;
            }
            else break;
        }
    }
    ll ma = LLONG_MAX;
    ll res = i;
    for(int z = max(0ll, i - 2); z <= min(n - 1, i + 2); z++) {
        // dbg(z, ans(k, n, z));
        if (ans(k, n, z) < ma) {
            ma = ans(k, n, z);
            res = z;
        }
    }
    cout << ma << endl;
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