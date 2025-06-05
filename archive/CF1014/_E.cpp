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

ll modpow(ll a, ll b, ll m) { a %= m; ll r = 1; while (b > 0) { if (b & 1) { r = r * a % m; }a = a * a % m; b >>= 1; }return r; }
ll modinv(ll val, ll mod) { return modpow(val, mod - 2, mod); }

void TC() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll midcount = (n - 2) * (m - 2);
    ll sideCount = (n - 2) * 2 + (m - 2) * 2;
    ll cornerCount = 4;
    vector<tuple<int, int, int>> pnts(k);
    int sideParity = 0;
    // Assume white on edge swaps parity.
    while(k--) {
        ll x, y, c;
        cin >> y >> x >> c;
        pnts[k] = {x, y, c};
        y--, x--;
        bool yedge = y == 0 || y == n - 1;
        bool xedge = x == 0 || x == m - 1;
        if (xedge && yedge) {
            cornerCount--;
        }
        else if (xedge || yedge) {
            sideCount--;
            if (c == 1) {
                // cout << x << ' ' << y << ' ' << c << endl;
                sideParity = !sideParity;
            }
        }
        else {
            midcount--;
        }
    }
    const ll mod = 1e9+7;

    // cout << sideCount << ' ' << sideParity << endl;
    if (sideCount == 0 && sideParity == 1) {
        cout << 0 << endl;
        return;
    }
    else {
        ll tm = midcount + cornerCount + max(sideCount - 1, 0ll);
        cout << modpow(2, tm, mod) << endl;

    }
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