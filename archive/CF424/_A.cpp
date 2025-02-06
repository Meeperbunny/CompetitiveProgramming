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

bool isgood(vector<ll> &a, vector<ll> &b, ll time, ll p) {
    vector<bool> c(b.size(), false);
    for(int i = 0; i < a.size(); i++) {
        bool f = false;
        for(int q = 0; q < b.size(); q++) {
            if (c[q]) continue;
            if (abs(a[i] - b[q]) + abs(b[q] - p) <= time) {
                // cout << i << ' ' << q << ' ' << time << endl;
                f = true;
                c[q] = true;
                break;
            }
        }
        if (!f) {
            return false;
        }
    }
    return true;
}

void TC() {
    ll n, k, p;
    cin >> n >> k >> p;
    vector<ll> a(n), b(k);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < k; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll t = -1;
    for(ll j = 1e10; j >= 1; j >>= 1) {
        while(true) {
            if (!isgood(a, b, t + j, p)) {
                t += j;
            }
            else break;
        }
    }
    cout << t + 1 << endl;
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