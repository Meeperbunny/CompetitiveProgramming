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
    vector<ll> b(n);
    for(auto &e : b) cin >> e;
    vector<vector<pair<ll, ll>>> adj(n);
    while(m--) {
        ll s, v, w;
        cin >> s >> v >> w;
        s--, v--;
        adj[s].push_back({v, w});
    }
    auto canMakeIt = [&](ll limit) -> bool {
        vector<ll> mb(n, -1); // Can ARRIVE at i with anywhere from L, U
        mb[0] = 0;
        for(ll i = 0; i < n; i++) {
            if (mb[i] == -1) continue;
            mb[i] = min(mb[i] + b[i], limit);
            for(auto [e, w] : adj[i]) {
                if (w <= mb[i]) {
                    mb[e] = max(mb[e], mb[i]);
                }
            }
        }
        return mb[n - 1] != -1;
    };
    ll k = -1;
    for(ll j = 1ll << 32; j >= 1; j >>= 1) {
        ll hyp = k + j;
        if (!canMakeIt(hyp)) {
            k = hyp;
            j *= 2;
        }
        if (k > 1ll << 34) break;
    }
    if (k > 1ll << 34) {
        k = -2;
    }
    cout << k + 1 << endl;
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