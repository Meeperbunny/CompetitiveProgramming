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
    vector<int> d(n);
    for(auto &e : d) cin >> e;
    vector<pair<int, int>> r(n);
    for(auto &e : r) {
        cin >> e.first >> e.second;
    }
    // Make unsure 0, backtrack to change
    vector<int> upper(n);
    upper[n - 1] = r[n - 1].second;
    for(int i = n - 2; i >= 0; i--) {
        upper[i] = min(upper[i + 1], r[i].second);
    }
    vector<int> lower(n);
    lower[0] = r[0].first;
    for(int i = 1; i < n; i++) {
        lower[i] = max(lower[i - 1], r[i].first);
    }
    int ce = 0;
    vector<int> dtt(n);
    for(int i = 0; i < n; i++) {
        if (d[i] == -1) {

        }
        else {
            ce += d[i];
        }
        dtt[i] = upper[i] - ce;
        if (dtt[i] < 0) {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> som(n);
    som[n - 1] = dtt[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        som[i] = min(som[i + 1], dtt[i]);
    }
    // for(auto e : som) cout << e << ' ';
    // cout << endl;
    int changed = 0;
    int cp = 0;
    for(int i = 0; i < n; i++) {
        if (som[i] > changed && d[i] == -1) {
            d[i] = 1;
            changed++;
            cp += 1;
        }
        else if (d[i] == -1) {
            d[i] = 0;
        }
        else {
            cp += d[i];
        }
        // cout << i << ' ' << cp << endl;
        if (cp < r[i].first) {
            cout << -1 << endl;
            return;
        }
    }
    for(auto e : d) cout << e << ' ';
    cout << endl;

    
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