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
    vector<vector<ll>> a(n, vector<ll>(2));
    for(int i = 0 ;i < 2; i++) {
        for(int q = 0; q < n; q++) cin >> a[q][i];
    }
    // Treat curr as mid
    ll masum = 0;
    for(int i = 0; i < n; i++) {
        masum += max(a[i][0], a[i][1]);
    }
    ll ma = LLONG_MIN;
    for(int i = 0; i < n; i++) {
        masum -= max(a[i][0], a[i][1]);
        masum += a[i][0] + a[i][1];
        ma = max(masum, ma);
        masum -= a[i][0] + a[i][1];
        masum += max(a[i][0], a[i][1]);
    }
    cout << ma << endl;
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