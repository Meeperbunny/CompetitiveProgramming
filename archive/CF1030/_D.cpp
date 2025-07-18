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

vector<vector<vector<int>>> memo;
map<ll, ll> lpos;
vector<ll> p, d;
ll n, k;
vector<bool> qcol;

bool canLeave(ll pind, ll dir, ll rem, ll cc) { // 1 is right, 0 is left
    // cout << "ON Pind: " << pind << ' ' << "Dir: " << dir << " Rem: " << rem << ' ' << cc << endl;
    // Go in the dir, then check.
    if (memo[pind][rem][dir] >= 2) {
        ll c = memo[pind][rem][dir];
        if (cc == c) {
            // Is in a loop.
            memo[pind][rem][dir] = false;
        }
        else {
            // Get the other's result.
            bool ores = qcol[c];
            memo[pind][rem][dir] = ores;
        }
    }
    else if (memo[pind][rem][dir] == -1) {
        if (rem != d[pind] && ((pind == n - 1 && dir == 1) || (pind == 0 && dir == 0))) {
            // Can leave.
            memo[pind][rem][dir] = 1;
        }
        else {
            // Otherwise find the next and then check its status.
            memo[pind][rem][dir] = cc;

            ll np{pind}, nr{rem}, nd{dir};

            // If we are on while light is on, swap, then go as far left as we can.
            if (d[pind] == rem) {
                // Swap dir.
                nd = (nd == 1) ? 0 : 1;
            }
            if (((pind == n - 1 && nd == 1) || (pind == 0 && nd == 0))) {
                // Can leave.
                memo[pind][rem][dir] = 1;
            }
            else {
                // Move
                // cout << "MOVED " << endl;
                ll change = (nd == 1) ? 1 : -1;
                int npind = pind + change;
                ll delta = abs(p[npind] - p[pind]);
                // cout << "MOVING " << delta << endl;
                bool res = canLeave(npind, nd, (rem + delta) % k, cc);
                memo[pind][rem][dir] = res;
                // Go in our current dir as far as we can.
            }
        }

    }
    bool r = memo[pind][rem][dir];
    return r;
}

void TC() {
    cin >> n >> k;
    memo = vector<vector<vector<int>>>(n, vector<vector<int>>(k, vector<int>(2, -1)));

    lpos = map<ll, ll>();
    p = vector<ll>(n);
    d = vector<ll>(n);
    for(auto &e : p) cin >> e;
    for(auto &e : d) cin >> e;
    map<ll, set<ll>> r, l;
    for(int i = 0; i < n; i++) {
        r[((d[i] - p[i]) % k + k) % k].insert(i);
        l[((d[i] + p[i]) % k + k) % k].insert(i);
    }
    // For some i, what does it hit when going a dir?
    vector<int> rh(n, -1), lh(n, -1);
    for(int i = 0; i < n; i++) {
        {
            int mr = ((d[i] - p[i]) % k + k) % k;
            auto &s = r[mr];
            auto it = s.upper_bound(i);
            if (it != s.end()) {
                rh[i] = *it;
            }
        }
        {
            int ml = ((d[i] + p[i]) % k + k) % k;
            auto &s = l[ml];
            auto it = s.lower_bound(i);
            if (it != s.begin()) {
                it = prev(it);
                lh[i] = *it;
            }
        }
    }
    vector<vector<int>> res(n, vector<int>(2, -1));
     // 0 I SRIGHT
    vector<int> cr(n, -1);
    int cc = 0;
    auto dfs = [&](auto dfs, int i, int d) -> bool {
        // Get the next that we hit. If -1 is good. If is cc, then is loop.
        int nx = 0;
        if (d == 0) {
            nx = rh[i];
        }
        else {
            nx = lh[i];
        }
        if (nx == -1) {
            res[i][d] = true;
            return true;
        }
        else {
            int nd = (d == 1) ? 0 : 1;
            int rs = res[nx][nd];
            if (rs == -1) {
                res[i][d] = cc;
                bool r = dfs(dfs, nx, nd);
                res[i][d] = r;
            }
            else if (rs <= 1) {

            }
            else if (rs == cc) {
                return false;
            }
            else {
                res[i][d] = cr[rs];
            }
            return res[i][d];
        }

    };
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < 2; q++) {
            if (res[i][q] == -1) {
                dfs(dfs, i, q);
            }
        }
    }
    int q; cin >> q;
    while(q--) {
        ll pos; cin >> pos;
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