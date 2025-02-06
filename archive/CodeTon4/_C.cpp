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
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> a(n);
    ll mael = 0;
    for(auto &e : a) {
        cin >> e;
    }
    sort(a.begin(), a.end());
    map<ll, ll> cnts;
    ll tc = n;
    for(auto &e : a) cnts[e]++;
    ll cc = c * n;
    ll m = cc + d;
    ll last = 0;
    for(auto e : a) {
        // Insert up to last, then process curr.
        if (e == last) continue;
        cc += d * (e - last - 1);
        last = e;
        cc -= c;
        m = min(cc, m);
    }
    cout << m << endl;
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