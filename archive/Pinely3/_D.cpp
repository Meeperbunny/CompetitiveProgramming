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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void TC() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    int side;
    if (a[0] > k) side = 1;
    if (a[0] == k) side = 0;
    if (a[0] < k) side = -1;
    for(int i = 0; i < n; i++) {
        if (side == 1 && a[i] <= k) {
            cout << -1 << endl;
            return;
        }
        if (side == 0 && a[i] != k) {
            cout << -1 << endl;
            return;
        }
        if (side == -1 && a[i] >= k) {
            cout << -1 << endl;
            return;
        }
    }
    ll g = 0;
    for(auto e : a) {
        g = gcd(g, e - k);
    }
    ll tot = 0;
    if (side != 0) {
        for(auto e : a) {
            tot += (e - k - g) / g;
        }
    }
    cout << tot << endl;
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