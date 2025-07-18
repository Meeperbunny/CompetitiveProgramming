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
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    vector<ll> cost(103, LLONG_MAX / 2);
    cost[a] = 0;
    ll s = a ^ 1;
    cost[s] = y;
    for(ll i = min(s, a); i <= 101; i++) {
        ll nx = i + 1;
        cost[nx] = min(cost[nx], cost[i] + x);
        nx = i ^ 1;
        cost[nx] = min(cost[nx], cost[i] + y);
    }
    if (cost[b] == LLONG_MAX / 2) cost[b] = -1;
    cout << cost[b] << endl;
}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
}