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
    ll n, l, r;
    cin >> n >> l >> r;
    l--,r--;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    multiset<ll> LS;
    for(int i = l; i <= r; ++i) LS.insert(a[i]);
    multiset<ll> RS(LS);
    ll sz = r - l + 1;
    for(int i = 0; i < l; ++i) {
        LS.insert(a[i]);
    }
    for(int i = r + 1; i < n; ++i) {
        RS.insert(a[i]);
    }
    ll mi = LLONG_MAX;
    ll s = 0;
    auto tt = next(LS.begin(), sz);
    auto te = next(RS.begin(), sz);
    for(auto it = LS.begin(); it != tt; ++it) {
        s += *it;
    }
    mi = min(mi, s);
    s = 0;
    for(auto it = RS.begin(); it != te; ++it) {
        s += *it;
    }
    mi = min(mi, s);
    cout << mi << endl;
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