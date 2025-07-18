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
    int n, m;
    cin >> n >> m;
    if (n * 2 <= m) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << '\n';
    if (m <= n) {
        for(int i = 0; i < 2 * n; i++) {
            for(int q = 0; q < m; q++) cout << q + 1 << ' ';
            cout << '\n';
        }
        return;
    }
    vector<vector<int>> ans(2 * n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int q = 0; q < n; q++) {
            ans[2 * i][q] = (i + q) % n + 1;
            ans[2 * i + 1][q] = (i + q) % n + 1;
        }
    }
    for(int q = n; q < m; q++) {
        int snode = (1 + 2 * (q - n)) % (2 * n);
        int c = 1;
        for(int i = 0; i < n; i++) {
            ans[snode % (n * 2)][q] = c;
            ans[(snode + 1) % (n * 2)][q] = c;
            snode += 2;
            snode %= n * 2;
            c++;
        }
    }

    for(int i = 0; i < 2 * n; i++) {
        for(int q = 0; q < m; q++) cout << ans[i][q] << ' ';
        cout << '\n';
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