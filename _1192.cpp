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

void dfs(int y, int x, int cv, vector<vector<bool>> &r, vector<vector<bool>> &c) {
    if (x < 0 || x >= r[0].size()) return;
    if (y < 0 || y >= r.size()) return;
    if (!r[y][x]) return;
    if (c[y][x]) return;
    c[y][x] = true;
    dfs(y - 1, x, cv, r, c);
    dfs(y, x - 1, cv, r, c);
    dfs(y + 1, x, cv, r, c);
    dfs(y, x + 1, cv, r, c);
}

void TC() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> r(n, vector<bool>(m)), c(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int q = 0; q < m; q++) {
            r[i][q] = s[q] == '.';
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int q = 0; q < m; q++) {
            if (!c[i][q] && r[i][q]) {
                dfs(i, q, ++cnt, r, c);
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}