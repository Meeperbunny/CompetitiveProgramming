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
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    vector<vector<ll>> a(n, vector<ll>(m));
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) cin >> a[i][q];
    }
    int x = m - 1, y = n - 1;
    int si = s.size();
    while(si--) {
        char c = s[si];
        if (c == 'R') {
            // Make sure up is good
            ll tot = 0;
            for(int i = 0; i < n; i++) {
                tot += a[i][x];
            }
            a[y][x] = -tot;
            x--;
        }
        else {
            // Make sure left is good
            ll tot = 0;
            for(int i = 0; i < m; i++) {
                tot += a[y][i];
            }
            a[y][x] = -tot;
            y--;
        }
    }
    ll rt = 0;
    for(int i = 0; i < m; i++) {
        rt += a[0][i];
    }
    a[0][0] = -rt;
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) cout << a[i][q] << ' ';
        cout << endl;
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