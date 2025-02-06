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
    for(auto &e : a) cin >> e;
    if (n <= 2) {
        cout << -1 << endl;
        return;
    }
    ll mind = -1;
    ll mn = -1;
    for(int i = 0; i < n; i++) {
        if (a[i] > mn) {
            mn = a[i];
            mind = i;
        }
    }
    ll tot = accumulate(all(a), 0ll);
    ll mx = -1;
    for(ll j = 100000000000ll; j >= 1; j >>= 1) {
        while(true) {
            ll ta = mx + j;
            // dbg(ta);
            ll avg = (tot + ta + 2 * n - 1) / (2 * n);
            // dbg(ta, avg);
            ll uhc = 0;
            for(int i = 0; i < n; i++) {
                ll curr = a[i];
                if (i == mind) curr += ta;
                if (curr < avg) {
                    uhc++;
                }
            }
            if (uhc > n / 2) {
                break;
            }
            else {
                mx += j;
            }
        }
    }
    cout << mx + 1 << endl;

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