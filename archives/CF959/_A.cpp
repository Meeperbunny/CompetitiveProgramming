#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            cin >> a[i][q];
        }
    }
    if (n * m == 1) {
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            b[i][q] = (a[i][q] % (n * m)) + 1;
            cout << b[i][q] << ' ';
        } cout << endl;
    }
    if (n * m == 1) {
        cout << -1 << endl;
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