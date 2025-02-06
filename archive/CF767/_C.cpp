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
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(auto &e : arr[i]) cin >> e;
    }
    int tot = 0;
    vector<vector<bool>> chk(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < n; q++) {
            if (!((i + q) & 1)) {
                if (i == 0 && q % 4 == 0) {
                    if (q + 1 < n)
                        chk[i][q + 1] = 1;
                    if (q - 1 >= 0)
                        chk[i][q - 1] = 1;
                    if (i - 1 >= 0)
                        chk[i - 1][q] = 1;
                    if (i + 1 < n)
                        chk[i + 1][q] = 1;
                    tot ^= arr[i][q];
                }
                else if (i && !chk[i - 1][q]) {
                    if (q + 1 < n)
                        chk[i][q + 1] = 1;
                    if (q - 1 >= 0)
                        chk[i][q - 1] = 1;
                    if (i - 1 >= 0)
                        chk[i - 1][q] = 1;
                    if (i + 1 < n)
                        chk[i + 1][q] = 1;
                    tot ^= arr[i][q];

                }
            }
            else {
                if (i == 0 && q % 4 == 1) {
                    if (q + 1 < n)
                        chk[i][q + 1] = 1;
                    if (q - 1 >= 0)
                        chk[i][q - 1] = 1;
                    if (i - 1 >= 0)
                        chk[i - 1][q] = 1;
                    if (i + 1 < n)
                        chk[i + 1][q] = 1;
                    tot ^= arr[i][q];
                }
                else if (i && !chk[i - 1][q]) {
                    if (q + 1 < n)
                        chk[i][q + 1] = 1;
                    if (q - 1 >= 0)
                        chk[i][q - 1] = 1;
                    if (i - 1 >= 0)
                        chk[i - 1][q] = 1;
                    if (i + 1 < n)
                        chk[i + 1][q] = 1;
                    tot ^= arr[i][q];
                }
            }
        }
    }
    cout << tot << endl;
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