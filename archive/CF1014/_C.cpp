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
    sort(all(a));
    ll mi = -1;
    ll oddCount = 0;
    ll s = 0;


    for(ll i = 0; i < n; i++) {
        s += a[i];
        if (a[i] & 1) {
            oddCount++;
        }
        if (a[i] & 1 && (mi == -1 || a[i] > a[mi])) {
            mi = i;
        }
    }
    if (mi == -1 || oddCount == n) {
        // No mix, can't do anyhting
        cout<< *max_element(all(a)) << endl;
    }
    else {
        cout << s - ll(oddCount - 1) << endl;
    }

}

int main() {
    HEADER;
    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++) {
        TC();
    }
    return 0;
}