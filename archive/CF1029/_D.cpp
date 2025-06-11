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
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    ll diff = a[1] - a[0];
    for(int i = 2; i < n; i++) {
        if (a[i] - a[i - 1] != diff) {
            cout << "NO" << endl;
            return;
        }
    }
    bool good;
    if (diff == 0) {
        good = a[0] >= 0 && a[0] % (n + 1ll) == 0;
    }
    else if (diff > 0) {
        ll dec = diff;
        good = a[0] - diff >= 0 && (a[0] - diff) % (n + 1ll) == 0;
    }
    else {
        ll dec = -diff;
        good = a[n - 1] - dec >= 0 && (a[n - 1] - dec) % (n + 1ll) == 0;
    }
    cout << (good ? "YES" : "NO") << endl;
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