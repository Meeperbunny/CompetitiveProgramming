#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    set<ll> dist;
    for(auto e : a) dist.insert(e);
    vector<ll> ops;
    for(ll i = 0; i < 40; i++) {
        ll ma = 0, mi = INT_MAX * 3ll;
        for(auto e : dist) ma = max(ma, e), mi = min(mi, e);
        set<ll> ne;
        ll top = (ma + mi) / 2;
        ops.push_back(top);
        for(auto e : dist) {
            ll r = abs(e - top);
            ne.insert(r);
        }
        // cout << '\t' << top << endl;
        if (ne.size() == 1 && *ne.begin() == 0) {
            cout << ops.size() << endl;
            for(auto e : ops) cout << e << ' ';
            cout << endl;
            return;
        }
        swap(ne, dist);
    }
    cout << -1 << endl;
    return;
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