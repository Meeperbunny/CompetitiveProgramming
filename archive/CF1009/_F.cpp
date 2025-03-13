#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    ll x1, y1, x2, y2;
    // cin >> x1 >> y2 >> y1 >> x2;
    cin >> x1 >> x2 >> y1 >> y2;
    ll sz = 1 << 20;
    ll b = 20;
    vector<ll> num(22);
    ll tot = 0;
    while(sz) {
        // Find first one that is ez or greater to x1
        ll fx = (x1 + sz - 1) / sz;
        ll sx = (x2) / sz;
        ll fy = (y1 + sz - 1) / sz;
        ll sy = (y2) / sz;
        num[b] = max(0ll, sx - fx) * max(0ll, sy - fy);

        // cout << sz << ' ' << fx << ' ' << sx << ' ' << fy << ' ' << sy << endl;
        
        tot += num[b] - 4ll * num[b + 1];
        sz >>= 1;
        b--;
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