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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    if (n == k) {
        for(int i = 0; 2 * i + 1 < n; i++) {
            int tn = 2 * i + 1;
            if (a[tn] != i + 1) {
                cout << i + 1 << endl;
                return;
            }
            if (2 * (i + 1) + 1 >= n) {
                cout << i + 2 << endl;
                return;
            }
        }
        assert(false);
    }
    else {
        bool isone = true;
        for(int i = 1; i <= min(n - 1, 1 + (n - k)); ++i) {
            if (a[i] != 1) isone = false;
        }
        cout << 1 + int(isone) << endl;
    }
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