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
    auto a = vector<vector<int>>(n, vector<int>(m));
    for(auto &r : a) for(auto &e : r) cin >> e;
    if (m == 1) {
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    auto srt(a);
    for(auto &r : srt) sort(all(r));
    // If is bad at some q, then should swap either q - 1, or q. Try swapping each with each. If greater than 4, is not possible.
    set<int> toSwap;
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            if (srt[i][q] != a[i][q]) {
                toSwap.insert(q);
            }
        }
    }
    if (toSwap.size() > 2) {
        cout << -1 << endl;
        return;
    }
    if (toSwap.size() == 0) {
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    for(auto F : toSwap) {
        for(auto S : toSwap) {
            // Swap rows
            for(int i = 0; i < n; i++) {
                swap(a[i][F], a[i][S]);
            }
            int bc = 0;
            for(int i = 0; i < n; i++) {
                for(int q = 1; bc == 0 && q < m; q++) {
                    if (a[i][q] < a[i][q - 1]) {
                        bc++;
                        break;
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                swap(a[i][F], a[i][S]);
            }
            if (!bc) {
                cout << F + 1 << ' ' << S + 1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
}