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
    ll n; cin >> n;
    n *= 2;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    sort(all(a), greater<ll>());
    ll X = 0;
    X += a[0];
    for(ll i = 1; i < n; i += 2) {
        X += a[i];
        if (i + 1 < n) 
            X -= a[i + 1];
    }
    cout << a[0] << ' ' << X << ' ';
    for(int i = 1; i < n; i++) {
        cout << a[i] << ' ';
    } cout << endl;
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