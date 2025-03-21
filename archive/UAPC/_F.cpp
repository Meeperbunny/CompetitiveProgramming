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
    int n, m; cin >> n >> m;
    vector<string> M(n);
    vector<vector<bool>> seen(n, vector<bool>(m));
    for(auto &e : M) cin >> e;
    queue<pair<int, int>> Q;
    int sz = 1;
    for(int i = 0; i < n; i++) for(int q = 0; q < m; q++) if (M[i][q] == 'S') Q.push({i, q});
    while(!Q.empty()) {
        auto [y, x] = Q.front();
        Q.pop();
        vector<pair<int, int>> t = {
            {y-1, x},
            {y+1, x},
            {y, x+1},
            {y, x-1}
        };
        for(auto T : t) {
            if (T.first >= 0 && T.first < n && T.second >= 0 && T.second < m) {
                if (M[T.first][T.second] == '#' && !seen[T.first][T.second]) {
                    seen[T.first][T.second] = 1;
                    sz++;
                    Q.push(T);
                }
            }
        }
    }
    cout << sz << endl;

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