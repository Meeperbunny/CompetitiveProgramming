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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    ll m = -1;
    for(ll j = 1ll << 20; j >= 1; j >>= 1) {
        ll tm = m + j;
        ll used = 0;
        vector<bool> C(n + 5);
        vector<int> u;
        ll mex = 0;
        for(int i = 0; i < n; i++) {
            if (a[i] <= n + 2) {
                C[a[i]] = 1;
                u.push_back(a[i]);
            }
            while(C[mex]) {
                mex += 1;
            }
            if (mex >= tm) {
                for(auto e : u) {
                    C[e] = 0;
                }
                u.clear();
                mex = 0;
                used += 1;
            }
        }
        if (used >= k) {
            m = tm;
        }
        else {
        }
    }
    cout << m << endl;
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