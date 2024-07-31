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
    int n, k; cin >> n >> k;
    dbg(n, k);
    vector<vector<int>> res(n / k, vector<int>(n / k));
    vector<vector<int>> grid(n, vector<int>(n));
    for(auto &e : grid) {
        string s; cin >> s;
        for(int i = 0; i < n; i++) e[i] = s[i] == '1';
    }
    for(int i = 0; i < n / k; i += 1) {
        for(int q = 0; q < n / k; q += 1) {
            res[i][q] = grid[i * k][q * k];
            cout << res[i][q];
        } cout << endl;
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