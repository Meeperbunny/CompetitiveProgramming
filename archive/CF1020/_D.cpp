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
    vector<int> a(n), b(m);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    vector<int> left(m, -1), right(m, -1);
    for(int i = 0, c = 0; i < n && c < m; i++) {
        if (a[i] >= b[c]) {
            left[c] = i;
            c++;
        }
    }
    for(int i = n - 1, c = m - 1; i >= 0 && c >= 0; i--) {
        if (a[i] >= b[c]) {
            right[c] = i;
            c--;
        }
    }
    // Check if can do norm
    if (left[m - 1] != -1) {
        cout << 0 << endl;
        return;
    }
    // Check for gap
    int mi = INT_MAX;
    for(int i = 0; i < m; i++) {
        int l = i - 1;
        int r = i + 1;
        int li = -1;
        int ri = n;
        if (l >= 0) {
            li = left[l];
            if (left[l] == -1) continue;
        }
        if (r < m) {
            ri = right[r];
            if (right[r] == -1) continue;
        }
        if (li < ri) {
            mi = min(mi, b[i]);
        }
    }
    if (mi != INT_MAX) {
        cout << mi << endl;
    }
    else {
        cout << -1 << endl;
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