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
    map<string, int> idmap;
    int id = 0;
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> b(m, vector<int>(n));
    for(int q = 0; q < n; q++) {
        string s; cin >> s;
        int i = 0;
        if (idmap.count(s)) {
        }
        else {
            idmap[s] = id++;
        }
        i = idmap[s];
        a[q] = i;
    }
    vector<bool> ff(n);
    for(int j = 0; j< m; j++) {
        for(int q = 0; q < n; q++) {
            string s; cin >> s;
            int i = 0;
            if (idmap.count(s)) {
            }
            else {
                idmap[s] = id++;
            }
            i = idmap[s];
            b[j][q] = i;
            if (b[j][q] == a[q]) {
                ff[q] = 1;
            }
        }
    }
    if (accumulate(all(ff), 0) != n) {
        cout << - 1 << endl;
        return;
    }
    ll tot = 0;
    vector<bool> curr(n);
    int t = 0;
    int T = 0;
    while (t != n) {
        int most = -1;
        int ind = -1;
        int cc = 0;
        for(int i = 0; i < m; i++) {
            int filled = 0;
            int cost = 0;
            for(int q = 0; q < n; q++) {
                if (b[i][q] == a[q] && !curr[q]) {
                    cost += 1;
                    filled += 1;
                }
                if (!curr[q] && b[i][q] != a[q]) {
                    cost += 2;
                }
            }
            if (filled > most) {
                most = filled;
                ind = i;
                cc = cost;
            }
        }
        t += most;
        T += cc;
        for(int i = 0; i < n; i++) {
            if (b[ind][i] == a[i]) {
                curr[i] = 1;
            }
        }
        cout << T + (1 * (n - most)) << endl;
        return;
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