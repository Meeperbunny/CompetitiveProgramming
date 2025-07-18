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
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    vector<pair<int, int>> ops;
    
    int ltar = 1;
    int utar = n + 1;
    for(int i = 0; i < n; i++) {
        // cout << '\t'; for(auto e : a) cout << e << ' '; cout << endl;
        // cout << '\t'; for(auto e : b) cout << e << ' '; cout << endl;
        bool la = 0;
        bool ua = 0;
        int uind, lind;
        for(int q = 0; q < n; q++) {
            if (a[q] == ltar) {
                la = 0;
                lind = q;
            }
            if (b[q] == ltar) {
                la = 1;
                lind = q;
            }
            if (a[q] == utar) {
                ua = 0;
                uind = q;
            }
            if (b[q] == utar) {
                ua = 1;
                uind = q;
            }
        }
        // cout << lind << ' ' << uind << endl;
        if (ua == la) {
            ops.push_back({3, lind});
            swap(a[lind], b[lind]);
            la = !la;
        }
        // Move both to i.
        for(int q = lind - 1; q >= i; q--) {
            ops.push_back({(la == 0 ? 1 : 2), q});
            if (la == 0) swap(a[q], a[q + 1]);
            else swap(b[q], b[q + 1]);
        }
        for(int q = uind - 1; q >= i; q--) {
            ops.push_back({(ua == 0 ? 1 : 2), q});
            if (ua == 0) swap(a[q], a[q + 1]);
            else swap(b[q], b[q + 1]);
        }
        ltar++, utar++;
    }
    // cout << '\t'; for(auto e : a) cout << e << ' '; cout << endl;
    // cout << '\t'; for(auto e : b) cout << e << ' '; cout << endl;
    for(int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            swap(a[i], b[i]);
            ops.push_back({3, i});
        }
    }
    cout << ops.size() << endl;
    for(auto e : ops) {
        cout << e.first << ' ' << e.second + 1 << '\n';
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