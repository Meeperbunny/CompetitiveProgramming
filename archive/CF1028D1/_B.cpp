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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    vector<tuple<ll, ll, ll>> ops(q);
    for(auto &[x, b, c] : ops) {
        cin >> x >> b >> c;
    }
    reverse(all(ops));
    vector<pair<int, int>> r(n); // {low, up}
    for(int i = 0; i < n; i++) {
        r[i] = {a[i],a[i]};
    }
    for(auto [x, y, z] : ops) {
        x--, y--, z--;
        // Check the types

        // cout << x << ' ' << y << ' ' << z << endl;

        if (x == z || y == z) {
            if (y == z) {
                swap(x, y);
                // swap(A
            }
            auto &A = r[x];
            auto &B = r[y];
            auto &C = r[z];
            if (A.first > B.second) {
                cout << -1 << endl;
                return;
            }
            else if (A.second < B.first) {
                //
            }
            else {
                A.second = 1e9;
                B.first = max(A.first, B.first);
            }
        }
        else {
            auto &A = r[x];
            auto &B = r[y];
            auto &C = r[z];
            // If one is dipped, impossible
            if (C.first > A.second || C.first > B.second) {
                cout << -1 << endl;
                return;
            }
            else {
                // Is lower than both
                A.first = C.first;
                B.first = C.first;
                C.second = 1e9;
            }
        }
        // for(int i = 0; i < n; i++) {
        //     cout << r[i].first << ' ' << r[i].second << "   ";
        // }
        // cout << endl;
    }
    for(auto e : r) {
        cout << e.first << ' '; 
    } cout << endl;
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