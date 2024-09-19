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

int grid[301][301];
// bool contains[301][301][8];
bool anyarewins[301][301][301];
bool winning[301][301][301];

void TC() {
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> a(l);
    for(auto &e : a) cin >> e;
    for(int i = 0; i < n; i++) {
        for(int q = 0 ; q < m; q++) {
            cin >> grid[i][q];
        }
    }
    for(int i = 0; i <= l; i++) for(int q = 0; q < n; q++) for(int j = 0; j < m; j++) {
        anyarewins[q][j][i] = 0;
        winning[q][j][i] = 0;
    }

    for(int j = l - 1; j >= 0; j--) {
        for(int i = 0; i < n; i++) {
            for(int q = 0; q < m; q++) {
                // Can only move here if is eq
                if (grid[i][q] == a[j]) {
                    if (i == n - 1 || q == m - 1 || !anyarewins[i + 1][q + 1][j + 1]) {
                        winning[i][q][j] = 1;
                    }
                    else {
                        winning[i][q][j] = 0;
                    }
                }
            }
        }
        // Set wins
        for(int i = n - 1; i >= 0; i--) {
            for(int q = m - 1; q >= 0; q--) {
                if (winning[i][q][j]) {
                    anyarewins[i][q][j] = 1;
                }
                if (i != n - 1) {
                    anyarewins[i][q][j] |= anyarewins[i + 1][q][j];
                }
                if (q != m - 1) {
                    anyarewins[i][q][j] |= anyarewins[i][q + 1][j];
                }
            }
        }
    }
    // for(int j = 0; j < l; j++) {
    //     for(int i = 0; i < n; i++) {
    //         for(int q = 0; q < m; q++) {
    //             cout << winning[i][q][j];
    //         } cout << '\n';
    //     } cout << '\n';
    // }
    if (anyarewins[0][0][0]) {
        cout << "T" << endl;
    }
    else {
        cout << "N" << endl;
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