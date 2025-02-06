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
    ll dec = 0;
    ll ops = 0;
    for(ll i = 1; i < n; i++) {
        a[i] -= dec;
        if (a[i - 1] < a[i]) {
            ll diff = a[i] - a[i - 1];
            dec += diff;
            ops += diff;
            a[i] -= diff;
        }
    }
    dec = 0;
    for(ll i = n - 2; i >= 0; i--) {
        a[i] -= dec;
        if (a[i] > a[i + 1]) {
            ll diff = a[i] - a[i + 1];
            dec += diff;
            ops += diff;
            a[i] -= diff;
        }
    }
    ops += abs(a[0]);
    cout << ops << endl;
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