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
    vector<vector<int>> pcount(n + 1, vector<int>(2001));
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    // for(int i = 1; i <= n; i++) {
    //     for(int q = 0; q <= 2000; q++) {
    //         pcount[i][q] += pcount[i - 1][q];
    //         if (a[i - 1] == q) pcount[i][q]++;
    //     }
    // }
    int inversionCount = 0;
    for(int i = 0; i < n; i++) {
        for(int q = i + 1; q < n; q++) {
            inversionCount += int(a[i] > a[q]);
        }
    }
    // dbg(inversionCount);
    pair<int, int> range = {-1, -1};
    int best = INT_MAX;
    for(int l = 1; l <= n; l++) {
        int g = 0;
        int low = 0;
        for(int r = l; r <= n; r++) {
            if (r != l && a[r - 1] > a[l - 1]) {
                g++;
            }
            if (r != l && a[r - 1] < a[l - 1]) {
                low++;
            }
            if (inversionCount + g - low < best) {
                range = {l, r};
                best = min(inversionCount + g - low, best);
            }
        }
    }
    cout << range.first << ' ' << range.second << endl;
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