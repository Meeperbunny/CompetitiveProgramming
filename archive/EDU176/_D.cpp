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
    ll x, y; cin >> x >> y;
    map<ll, ll> xt, yt;
    if (x == y) {
        cout << 0 << endl;
        return;
    }
    ll X = x;
    ll p = 0;
    xt[X] = p;
    while(X) {
        X /= 2;
        p += 1;
        xt[X] = p;
    }
    p = 0;
    ll Y = y;
    yt[Y] = p;
    ll mnum = -1;
    if (mnum == -1 && xt.count(Y)) {
        mnum = Y;
    }
    while(Y) {
        Y /= 2;
        p += 1;
        if (mnum == -1 && xt.count(Y)) {
            mnum = Y;
        }
        yt[Y] = p;
    }
    ll mt = yt[mnum] + xt[mnum];
    vector<int> k = {0, 1, 2, 3};
    ll bans = LLONG_MAX;
    for(int s = 0; s < pow(2, 4); s++) {
        vector<int> ss;
        for(int i = 0; i < 4; i++) {
            if ((s >> i) & 1) {
                ss.push_back(k[i]);
            }
        }
        for(int i = 0; i < pow(2, ss.size()); i++) {
            ll tot = 0;
            ll ldiv = 1;
            ll rdiv = 1;
            for(int q = 0; q < ss.size(); q++) {
                if ((i >> q) & 1) {
                    ldiv *= pow(2, ss[q] + 1);
                    tot += pow(2, ss[q] + 1);
                }
                else {
                    rdiv *= pow(2, ss[q] + 1);
                    tot += pow(2, ss[q] + 1);
                }
            }
            if (ll(x / ldiv) == ll(y / rdiv)) {
                bans = min(bans, tot);
            }
        }
    }
    if (bans != LLONG_MAX) {
        cout << bans << endl;
        return;
    }
    ll tt = 0;
    for(ll i = 1; i < 100; i++) {
        tt += i;
        if (mt <= tt) {
            ll mc = 0;
            ll d = tt - mt;
            vector<ll> ans;
            for(int q = i; q >= 1; q--) {
                if (d >= q) {
                    d -= q;
                }
                else {
                    ans.push_back(q);
                }
            }
            for(auto e : ans) {
                mc += pow(2, e);
            }
            cout << mc << endl;
            return;
        }
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