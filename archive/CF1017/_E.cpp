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
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    vector<ll> onecont(30);
    vector<ll> zerocont(30);
    for(int q = 0; q < 30; q++) {
        for(int i = 0; i < n; i++) {
            onecont[q] += (a[i] & (1 << q)) ^ (1 << q);
            zerocont[q] += (a[i] & (1 << q)) ^ (0 << q);
        }
    }
    ll b = 0;
    for(int i = 0; i < n; i++) {
        ll cc = 0;
        for(int q = 0; q < 30; q++) {
            if ((a[i] >> q) & 1) cc += onecont[q];
            else cc += zerocont[q];
        }
        b = max(b, cc);
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