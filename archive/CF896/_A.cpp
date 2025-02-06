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
    vector<vector<int>> ans(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            if (int(0 + 1 + i + int(i == 0)) % m != 0) {
                ans[i][int(q + 1 + i) % m] = q;
            }
            else {
                ans[i][int(q + 1 + 0) % m] = q;
            }
        }
    }
    vector<bool> res(m + 2, 0);
    for(int q = 0; q < m; q++) {
        vector<bool> inc(m + 2, 0);
        for(int i = 0; i < n; i++) {
            inc[ans[i][q]] = 1;
        }
        for(int z = 0; z < inc.size(); z++) {
            if (!inc[z]) {
                res[z] = 1;
                break;
            }
        }
    }
    for(int q = 0; q < res.size(); q++) {
        if (!res[q]) {
            cout << q << endl;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            cout << ans[i][q] << ' ';
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