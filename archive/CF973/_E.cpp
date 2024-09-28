#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int nx[100001];

void TC() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto & e : a) cin >> e;
    int g = 0;
    for(auto e : a) g = gcd(g, e);
    for(auto &e : a) {
        e /= g;
    }
    int bg = 0;
    ll tot = 0;
    for(int i = 0; i < min(12, n); i++) {
        int mbg = INT_MAX;
        for(auto e : a) {
            int ng = gcd(bg, e);
            if (ng < mbg) {
                mbg = ng;
            }
        }
        bg = mbg;
        tot += bg;
    }
    tot += n - min(12, n);
    cout << tot * ll(g) << endl;
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