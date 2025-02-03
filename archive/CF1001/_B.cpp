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
    int n; cin >> n;
    vector<ll> a(n), ls(n, 0);
    for(auto &e : a) cin >> e;
    ll elapsed = 0;
    for(int i = 1; i < n; ++i) {
        elapsed++;
        if (a[i] - (elapsed - ls[i]) <= 0) {
            cout << "NO" << endl;
            return;
        }
        ls[i] = elapsed;
    }
    for(int i = n - 2; i >= 0; --i) {
        elapsed++;
        if (a[i] - (elapsed - ls[i]) <= 0) {
            cout << "NO" << endl;
            return;
        }
        ls[i] = elapsed;
    }
    for(int i = 1; i < n; ++i) {
        elapsed++;
        if (a[i] - (elapsed - ls[i]) <= 0) {
            cout << "NO" << endl;
            return;
        }
        ls[i] = elapsed;
    }
    for(int i = n - 2; i >= 0; --i) {
        elapsed++;
        if (a[i] - (elapsed - ls[i]) <= 0) {
            cout << "NO" << endl;
            return;
        }
        ls[i] = elapsed;
    }
    cout << "YES" << endl;
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