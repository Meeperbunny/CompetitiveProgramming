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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll r = n - 1;
    vector<ll> cnt(n + 1, 0);
    ll t = 0;
    ll tc = 0;
    for(ll l = n - 1; l >= 0; l--) {
        t += a[l];
        if (t < x) {
            continue;
        }
        while(t > x) {
            if (r == l) break;
            else if (t - a[r] > x) {
                t -= a[r--];
            }
            else break;
        }
        ll ta = r + 1;
        cnt[l] = cnt[r + 1] + ll(t > x);
    }
    for(ll i = 0; i < n + 1; i++) {
        tc += cnt[i];
    }
    cout << (((n + 1ll) * n) >> 1ll) - tc << endl;
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