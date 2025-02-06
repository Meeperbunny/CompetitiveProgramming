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

void TC() {
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll tot = accumulate(all(a), 0ll);
    vector<ll> ptot(n + 1, 0);
    ll s = 0;
    ll holdup = 0;
    for(ll i = 0, t = 1; i < n; i++, t++) {
        ll timeCurrFilled = holdup + (a[i] - ((holdup * i) - s + holdup) + i) / (i + 1);
        if (holdup < timeCurrFilled) holdup = timeCurrFilled;
        s += a[i];
        ll rest = tot - s;
        dbg(i);
        ptot[t] = max(holdup, (tot + t - 1) / t);
    }
    ll q; cin >> q;
    while(q--) {
        ll j; cin >> j;
        ll k = 0;
        for(ll m = n + 1; m >= 1; m >>= 1) {
            while(true) {
                if (k + m >= ptot.size()) break;
                else {
                    if (ptot[k + m] > j) k += m;
                    else break;
                }
            }
        }
        if (k == n) {
            cout << -1 << endl;
        }
        else {
            cout << k + 1 << endl;
        }
    }
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