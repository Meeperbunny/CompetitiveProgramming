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

// Number of ops, number at the tar
pair<ll, ll> opsToGetTo(ll tar, vector<ll> &a, vector<ll> &b) {
    ll numat = 0;
    ll numops = 0;
    for(int i = 0; i < a.size(); i++) {
        if (tar <= a[i]) {
            numops += (a[i] + b[i] - 1 - tar) / b[i];
            if (tar <= a[i])
                if ((a[i] - tar) % b[i] == 0) numat++;
        }
    }
    return { numops, numat };
}

void TC() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    ll me = 0;
    for(auto &e : a) {
        cin >> e;
        me = max(me, e + 1);
    }
    for(auto &e : b) cin >> e;
    // ll ans; cin >> ans;
    ll men = 0;

    // for(auto e : a) cout << e << '_';
    // cout << endl;
    // for(auto e : b) cout << e << '-';
    // cout << endl;

    for(ll ta = me; ta >= 1; ta >>= 1) {
        // cout << ta << endl;
        while(true) {
            pair<ll, ll> res = opsToGetTo(men + ta, a, b);
            ll oc = res.first;
            ll at = res.second;
            // cout << men + ta << ' ' << oc << ' ' << at << endl;
            if (oc > k) {
                men += ta;
            }
            else if (oc + at < k) break;
            else {
                ll tot = 0;
                ll TN = men + ta;
                // cout << "FOUND AT " << TN << endl;
                // This is answer
                ll tind = k - oc;
                tot += tind * TN;
                for(int i = 0; i < n; i++) {
                        if (TN < a[i]) {
                        ll OC = (a[i] + b[i] - 1 - TN) / b[i];
                        ll tadd = a[i] * OC - (OC * (OC - 1)) / 2 * b[i];
                        tot += tadd;
                    }
                    // dbg(i, tadd);
                }
                cout << tot << endl;
                // if (tot != ans) cout << "ZA" << ans << endl;
                return;
            }
        }
    }
    // Use all we can
    ll tot = 0;
    ll TN = 0;
    for(int i = 0; i < n; i++) {
        ll OC = (a[i] + b[i] - 1 - TN) / b[i];
        ll tadd = a[i] * OC - (OC * (OC - 1)) / 2 * b[i];
        tot += tadd;
        // dbg(i, tadd);
    }
    cout << tot << endl;
    // cout << "NOT FOUND" << endl;
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