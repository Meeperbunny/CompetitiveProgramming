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

void TC() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    ll base = 1;
    ll inc = 1;
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            a[i][q] ^= base;
        }
        base += inc;
    }
    base = (1ll << 20);
    inc = base;
    for(int i = 0; i < m; i++) {
        for(int q = 0; q < n; q++) {
            a[q][i] ^= base;
        }
        base += inc;
    }
    cout << n * m << endl;
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