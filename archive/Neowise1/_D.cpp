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
    // x, y
    // x, y + 1
    // x + 1, y - 1
    // x + 1, y
    ll n; cin >> n;
    vector<pair<ll, ll>> a(n);
    map<ll, ll> cnts, c2;
    for(auto &e : a) cin >> e.first >> e.second;
    for(auto &e : a) {
        cnts[e.first] += 1;
        e.second += e.first;
        c2[e.second] += 1;
    }
    ll x, y;
    for(auto &e : cnts) {
        if (e.second & 1) x = e.first;
    }
    for(auto &e : c2) {
        if (e.second & 1) y = e.first;
    }
    cout << x << ' ' << y - x << endl;
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