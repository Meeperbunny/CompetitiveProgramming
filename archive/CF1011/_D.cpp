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
    ll n, k; cin >> n >> k;
    vector<ll> d(n);
    for(auto &e : d) cin >> e;
    multiset<ll> c;
    for(int i = n - 1; i >= 0; i--) {
        ll ck = n - i - (c.size() * (k + 1));
        if (ck >= k + 1) {
            // Get current
            c.insert(d[i]);
        }
        else {
            // Can swap
            if (c.size() && *c.begin() < d[i]) {
                c.erase(c.find(*c.begin()));
                c.insert(d[i]);
            }
        }
    }
    cout << accumulate(all(c), 0ll) << endl;
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