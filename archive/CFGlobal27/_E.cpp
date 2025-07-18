#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    ll ct = 0;
    ll lmo = 0;
    ll b = LLONG_MAX;
    for(ll fops = 1; fops <= 1e7; fops++) {
        ll CC = 0;
        ll mops = (fops - 1ll) / k;
        CC += fops * x + y * mops;
        if (mops > lmo) {
            ct += fops - 1ll;
            lmo = mops;
        }
        if (ct > z) break;
        ll h = z - ct;
        ll left = (h + fops - 1ll) / fops;
        b = min(b, CC + left * y);
    }
    cout << b << endl;
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