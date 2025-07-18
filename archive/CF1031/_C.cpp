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
    vector<vector<char>> grid(n, vector<char>(m));
    int gc = 0;
    for(auto &e : grid) {
        string s; cin >> s;
        for(int q = 0; q < m; q++) {
            e[q] = s[q];
            gc += int(s[q] == 'g');
        }
    }
    vector<vector<int>> preDown(n + 1, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            preDown[i + 1][q] = preDown[i][q] + int(grid[i][q] == 'g');
        }
    }
    int ba = 0;
    for(int i = 0; i < n; i++) {
        int cg = 0;
        for(int q = 0; q <= min(k - 1, m - 1); q++) {
            cg += preDown[min(1 + i + k - 1, n)][q] - preDown[max(1 + i - k + 1 - 1, 0)][q];
        }
        for(int q = 0; q < m; q++) {
            bool isg = grid[i][q] == '.';
            if (isg) {
                ba = max(gc - cg, ba);
            }
            if (q - k + 1 >= 0)
                cg -= preDown[min(1 + i + k - 1, n)][q - k + 1] - preDown[max(1 + i - k + 1 - 1, 0)][q - k + 1];
            if (q + k < m)
                cg += preDown[min(1 + i + k - 1, n)][q + k] - preDown[max(1 + i - k + 1 - 1, 0)][q + k];
        }
    }
    cout << ba << endl;
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