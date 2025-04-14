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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ans(n, vector<int>(m));
    if (m % k == 0) {
        for(int i = 0; i < n; i++) {
            int cn = 1;
            if (i & 1) cn = 2;
            for(int q = 0; q < m; q++) {
                cout << cn << ' ';
                cn += 1;
                if (cn == k + 1) cn = 1;
            } cout << '\n';
        }
    }
    else {
        int cn = 1;
        for(int i = 0; i < n; i++) {
            for(int q = 0; q < m; q++) {
                cout << cn << ' ';
                cn += 1;
                if (cn == k + 1) cn = 1;
            } cout << '\n';
        }
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