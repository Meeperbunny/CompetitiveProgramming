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
    vector<ll> a(n);
    vector<ll> b(n);
    for(auto &e : a) {cin >> e; e--;}
    for(auto &e : b) {cin >> e; e--;}
    map<ll, ll> ptoi;
    for(ll i = 0; i < n; i++) {
        ptoi[a[i]] = i;
    }
    ll evenCycleCount = 0;
    vector<bool> checked(n, false);
    ll col = 0;
    for(ll i = 0; i < n; i++) {
        if (!checked[i]) {
            col++;
            ll len = 0;
            ll curr = i;
            while(!checked[curr]) {
                len++;
                checked[curr] = col;
                curr = ptoi[b[curr]];
            }
            evenCycleCount += ll(len / 2);
        }
    }
    ll ans = 0;
    for(ll i = 0; i < evenCycleCount; i++) {
        ans += 2 * n - 2 - i * 4;
    }
    cout << ans << endl;
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