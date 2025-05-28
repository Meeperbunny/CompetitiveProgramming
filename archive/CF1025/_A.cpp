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
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n, 0);
    for(auto &e : a) cin >> e;
    for(int i = 0; i < n - 1; i++) {
        if (b[i] != a[i] && b[i] == 0) {
            b[i] = 1;
        }
        else if (b[i + 1] != a[i + 1] && b[i + 1] == 0) {
            b[i + 1] = 1;
        }
        if (a[i] == 0 && a[i + 1] == 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << (a == b ? "NO" : "YES") << endl;
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