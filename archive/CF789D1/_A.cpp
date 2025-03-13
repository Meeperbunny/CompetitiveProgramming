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
    int n; cin >> n;
    vector<int> p(n);
    for(auto &e : p) cin >> e;
    vector<vector<int>> left(n, vector<int>(n)), right(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < i; q++) {
            if (q) {
                left[i][q] += left[i][q - 1];
            }
            left[i][q] += p[q] < p[i];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int q = n - 1; q > i; q--) {
            if (q != n - 1) {
                right[i][q] += right[i][q + 1];
            }
            right[i][q] += p[i] > p[q];
        }
    }
    ll tot = 0;
    for(int b = 1; b < n - 1; b++) {
        for(int c = b + 1; c < n - 1; c++) {
            int al = b - 1;
            int dr = c + 1;
            tot += ll(right[b][dr]) * ll(left[c][al]);
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