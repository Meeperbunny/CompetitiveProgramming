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
    ll n, Q;
    cin >> n >> Q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> apre(2 * n + 1, 0);
    for(int i = 1; i <= 2 * n; i++) {
        apre[i] = a[(i - 1) % n] + apre[i - 1];
    }
    ll tot = accumulate(all(a), 0ll);
    while(Q--) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        ll lshift = l / n;
        ll rshift = r / n;
        ll lind = l % n;
        ll rind = r % n;
        ll mids = max(0ll, rshift - lshift - 1);

        if (lshift != rshift) {
            ll ans = 0;
            ans += mids * tot;

            ll ls = 0;
            ls = tot - (apre[lshift + lind] - apre[lshift]);

            ll rs = 0;
            rs = apre[rshift + rind + 1] - apre[rshift];
            // dbg(ans, ls, rs);

            cout << ans + ls + rs << endl;
        }
        else {
            cout << apre[rshift + rind + 1] - apre[lshift + lind] << endl;

        }
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