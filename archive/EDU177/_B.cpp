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
    ll n, x, k;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    ll ts = accumulate(all(a), 0ll);
    ll rightFull = x / ts;
    ll used = rightFull * ts;
    ll left = x - used;
    ll tind = n;
    if (x > k * ts) {
        cout << 0 << endl;
        return;
    }
    if (left) {
        for(int i = n - 1; i >= 0; i--) {
            left -= a[i];
            if (left <= 0) {
                tind = i;
                break;
            }
        }
    }
    cout << n * k + tind - rightFull * n - n + 1ll << endl;
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