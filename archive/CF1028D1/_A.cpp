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

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    else return gcd(b, a % b);
}

void TC() {
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    ll g = 0;
    for(auto e : a) g = gcd(g, e);
    for(auto &e : a) e /= g;
    int oc = count(all(a), 1ll);
    int noc = n - oc;
    int t = 0;
    if (oc) {
        for(auto e : a) if (e != 1) t++;
    }
    else {
        vector<int> steps(5001, INT_MAX);
        for(auto e : a) {
            steps[e] = 0;
        }
        for(int e = 5000; e >= 1; e--) {
            if (steps[e] != INT_MAX) {
                for(auto el : a) {
                    int g = gcd(el, e);
                    steps[g] = min(steps[g], steps[e] + 1);
                }
            }
        }
        t += steps[1] - 1;
        for(auto e : a) {
            if (e != 1) t++;
        }
    }
    // Greedy ish?
    cout << t << endl;
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