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
    ll n, m;
    cin >> n >> m;
    vector<ll> C(m);
    for(auto &e : C) cin >> e;
    sort(all(C));
    vector<pair<ll, ll>> p;
    int b = 0, f = m - 1;
    for(int i = 0;; i++) {
        if (n) {
            n--;
            p.push_back({C[b], C[f]});
        }
        if (n) {
            n--;
            p.push_back({C[f], C[b]});
        }
        b++, f--;
        if (n <= 0) {
            break;
        }
    }
    ll t = 0;
    for(auto e : p) {
        cout << e.first << ' ' << e.second << ' ' << e.first << ' ' << e.second << ' ' << e.first << ' ' << e.second << '\n';
        // t += abs(ll(e.first / 100) - ll(e.second / 100)) * 5;
    }
    // cout << 
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