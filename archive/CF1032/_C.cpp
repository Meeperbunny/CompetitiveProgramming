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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(auto &v : a) for(auto &e : v) cin >> e;
    int mav = 0;
    for(auto &v : a) {
        mav = max(mav, *max_element(all(v)));
    }
    // If any has more than 1, then is the center.
    // Try decreasing, if all satisfy, then is good.
    map<int, int> xcoord;
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            if (a[i][q] == mav) {
                xcoord[q]++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            if (a[i][q] == mav) {
                xcoord[q]--;
                if (xcoord[q] == 0) xcoord.erase(q);
            }
        }

        if (xcoord.size() <= 1) {
            cout << mav - 1 << endl;
            return;
        }
        
        for(int q = 0; q < m; q++) {
            if (a[i][q] == mav) {
                xcoord[q]++;
            }
        }
    }
    cout << mav << endl;
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