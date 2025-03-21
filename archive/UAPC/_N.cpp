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
    vector<ll> c(n - 1);
    vector<ll> dp(n + 1, LLONG_MAX);
    for(auto &e : c) cin >> e;
    ll m; cin >> m;
    vector<pair<ll, ll>> R(m);
    for(int i = 0; i < m; i++) {
        cin >> R[i].first >> R[i].second;
    }
    // When adding ourselves, check what is in the set
    // if one that is past our right is in the set, get rid of it.
    // All that are in have a left further than ours.
    sort(all(R), [](pair<ll, ll> &a, pair<ll, ll> &b){if (a.first == b.first) return a.second > b.second; else return a.first < b.first;});
    vector<vector<ll>> toadd(n + 1);
    vector<vector<ll>> torm(n + 1);
    for(int i = 0; i < m; i++) {
        toadd[R[i].first].push_back(i);
        torm[R[i].second - 1].push_back(i);
    }
    ll lastrm = 0;
    dp[0] = 0;
    multiset<pair<int, int>> RM;
    vector<bool> forcedout(m);
    ll bdp = LLONG_MAX;
    for(int i = 1; i < n; i++) {
        // Add all current ones
        for(auto e : toadd[i]) {
            // If max rightmost is greater than us get right of all rightmost.
            while(RM.size() && RM.rbegin()->first >= R[e].second) {
                dp[RM.rbegin()->first] = LLONG_MAX;
                forcedout[RM.rbegin()->second] = 1;
                RM.erase({RM.rbegin()->first, RM.rbegin()->second});
            }
            RM.insert({R[e].second, e});
        }
        if (RM.size() == 0) {
            continue;
        }
        if (i == 0) continue;

        ll nextrm = RM.rbegin()->first; // next pos
        // cout << lastrm << ' ' << nextrm << ' ' << c[i - 1] << ' ' << RM.size() << endl;
        if (dp[lastrm] != LLONG_MAX) {
            dp[nextrm] = min(dp[nextrm], bdp + c[i - 1]);
        }
        bdp = min(bdp, dp[i]);

        for(auto e : torm[i]) {
            lastrm = max(lastrm, R[e].second);
            RM.clear();
        }
    }
    // for(auto e : dp) cout << e << ' '; cout << endl;
    cout << dp[n] << endl;
}

int main() {
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}