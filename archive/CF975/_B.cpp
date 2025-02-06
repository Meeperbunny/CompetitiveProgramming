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
    ll n, q;
    cin >> n >> q;
    vector<ll> x(n);
    for(auto &e : x) cin >> e;
    ll c = 0;
    map<ll, ll> a;
    ll cm = LLONG_MAX, cma = 0;
    for(ll i = 0; i < n - 1; i++) {
        c -= i;
        c += (n - i - 1);
        cm = min(cm, c);
        cma = max(cma, c);
        a[c] += x[i + 1] - x[i] - 1;
    }
    if (n & 1) {
        a[cma] += 1;
    }
    for(auto e : a) {
        a[e.first] += 2;
    }
    dbg(cm, cma);
    while(q--) {
        ll j; cin >> j;
        cout << a[j] << ' ';
    }
    cout << endl;
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