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
    vector<pair<int, int>> p(n);
    for(auto &e : p) cin >> e.first;
    for(auto &e : p) cin >> e.second;
    for(int i = 0; i < n; i++) {
        if (i & 1) swap(p[i].first, p[i].second);
    }
    set<int> upper, lower;
    int tt = 0;
    // for(auto e : p) cout << e.first << ' ' << e.second << endl;
    // cout << endl;
    for(int i = n - 1; i >= 0; i--) {
        // For current, check if lower el is in upper or lower.
        // Then add n + 1 in, and check if it is in opposite.
        auto [l, u] = p[i];
        // cout << "ON " << l << ' ' << u << endl;
        if (l == u || lower.count(l) || upper.count(u)) {
            // cout << "PRE" << endl;
            tt = i + 1;
            break;
        }
        if (i < n - 1) {
            // Add n + 1 in.
            lower.insert(p[i + 1].first);
            upper.insert(p[i + 1].second);
            // cout << "I " << p[i].first << ' ' << p[i].second << endl;
        }
        if (lower.count(u) || upper.count(l)) {
            // cout << "SEC" << endl;
            tt = i + 1;
            break;
        }
    }
    cout <<tt<<endl;

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