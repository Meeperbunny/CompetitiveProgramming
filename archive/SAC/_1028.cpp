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
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int q = 0; q < m; q++) arr[i][q] = s[q] == '1';
    }
    vector<vector<int>> mdl(n, vector<int>(m, 0));
    vector<vector<int>> mdr(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            for(int j = 0; j < max(n, m); j++) {
                if (i + j >= n || q + j >= m) break;
                if (arr[i + j][q + j]) mdr[i][q] = j + 1;
                else break;
            }
            for(int j = 0; j < max(n, m); j++) {
                if (i + j >= n || q - j < 0) break;
                if (arr[i + j][q - j]) mdl[i][q] = j + 1;
                else break;
            }
        }
    }
    int ms = 0;
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            for(int j = 0; j < min(mdr[i][q], mdl[i][q]); j++) {
                if (mdl[i + j][q + j] >= j + 1 && mdr[i + j][q - j] >= j + 1) {
                    ms = max(ms, j + 1);
                }
            }
        }
    }
    cout << ms << endl;
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