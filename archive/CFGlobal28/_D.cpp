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
    vector<ll> a(n);
    vector<ll> b(m);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    // We want to get the furthest one if we have the option to choose.
    ll K = a[0];
    sort(all(a));
    sort(all(b));
    ll lind = 0;
    for(ll i = 0; i < n; i++) {
        if (a[i] == K) lind = i;
    }
    ll lowerc = 0;
    vector<ll> ans;
    for(auto e : b) if (e <= K) lowerc++;
    for(ll k = 1; k <= m; k++) {
        // cout << "K " << k << endl;
        ll t = ll(m / k);
        ll probs = ll(m / k) * k;
        probs -= lowerc;
        if (probs <= 0) {
            ans.push_back(t);
        }
        else {
            // Otherwise, need to get diffs.
            ll lu = (probs + k - 1) / k;
            for(ll q = 1; q <= lu; q++) {
                ll lower = m - min(q * k, probs);
                // cout << "\tON " << q << " " << max(b[lower], K + 1) << ' ' << distance(lower_bound(all(a), max(b[lower], K + 1)), a.end()) << endl;
                ll above;
                if (b[lower] <= K) {
                    above = distance(lower_bound(all(a), K + 1), a.end());
                }
                else {
                    above = distance(lower_bound(all(a), b[lower]), a.end());
                }
                t += above;
            }
            ans.push_back(t);
        }
    }
    for(auto e : ans) cout << e << ' ';
    cout << '\n';
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