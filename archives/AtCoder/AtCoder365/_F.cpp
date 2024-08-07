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
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll tot = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int q = 0; q < 31; q++) {
        vector<int> cnts(n), ec(n, 0), oc(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            bool c = (a[i] >> q) & 1;
            if (c) cnt++;
            cnts[i] = cnt;
            if (i) {
                oc[i] = oc[i - 1];
                ec[i] = ec[i - 1];
            }
            if (cnt & 1) oc[i]++;
            else if (cnt) ec[i]++;
        }
        // cout << "OC ";
        // for(int i = 0; i < n; i++) cout << oc[i] << ' ';
        // cout << endl;
        // cout << "EC ";
        // for(int i = 0; i < n; i++) cout << ec[i] << ' ';
        // cout << endl;

        for(int i = 0; i < n - 1; i++) {
            ll m = (1ll << q);
            ll b;
            if (!i || cnts[i - 1] % 2 == 0) {
                b = (oc[n - 1] - oc[i]);
            }
            else {
                b = (ec[n - 1] - ec[i]);
            }
            // cout << q << ' ' << i << ' ' << b << endl;
            tot += b * m;
        }
    }
    cout << tot << endl;
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