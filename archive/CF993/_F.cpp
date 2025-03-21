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

vector<vector<ll>> divs(200002);

void TC() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    vector<ll> b(m);
    for(auto &e : b) cin >> e;
    ll asum = accumulate(all(a), 0ll);
    ll bsum = accumulate(all(b), 0ll);
    vector<bool> A(2 * n + 1);
    for(auto e : a) A[e + n] = 1;
    vector<bool> B(2 * m + 1);
    for(auto e : b) B[e + m] = 1;
    unordered_set<ll> as(all(a)), bs(all(b));
    ll tsum = asum * bsum;
    while(q--) {
        ll x; cin >> x;
        bool neg = x < 0;
        vector<ll> &xdivs = divs[abs(x)];
        bool f = false;
        for(auto d : xdivs) {
            ll o = x / d;
            if (asum - d + n < A.size() && A[asum - d + n] && m + bsum - o < B.size() && B[m + bsum - o]) f = true;
            if (asum + d + n < A.size() && A[asum + d + n] && m + bsum + o < B.size() && B[m + bsum + o]) f = true;
        }
        if (f) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    for(ll i = 1; i < 200001; i++) {
        for(ll q = i; q < 200001; q += i) {
            divs[q].push_back(i);
        }
    }
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}