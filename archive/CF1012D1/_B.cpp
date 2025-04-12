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

struct union_find {
    vector<ll> parent;
    vector<ll> size;
    ll components = 0;

    union_find(ll n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(ll n) {
        parent.resize(n);
        for(ll i = 0; i < n; i++) {
            parent[i] = i;
        }
        size.assign(n, 1);
        components = n;
    }

    ll find(ll x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(ll x, ll y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        size[x] += size[y];
        parent[y] = x;
        components--;
        return true;
    }
};

void TC() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;

    ll cs = 0;
    using piii = tuple<ll, ll, ll>;
    priority_queue<piii, vector<piii>, greater<piii>> Q;
    set<ll> neb;
    for(ll i = 0; i < n; i++) {
        neb.insert(i);
        cs += a[i];
        if (a[i])
            Q.push({0, a[i], i});
    }
    ll rnds = 0;
    if (cs <= k) {
        cout << 0 << endl;
        return;
    }
    while(Q.size()) {
        auto [pri, val, ind] = Q.top();
        Q.pop();
        ll m = min(b[ind], val);
        b[ind] -= m;
        val -= m;
        cs -= m;
        if (cs <= k) {
            cout << pri + 1 << endl;
            return;
        }
        if (b[ind] == 0) {
            if (neb.count(ind))
                neb.erase(ind);
        }
        auto it = neb.upper_bound(ind);
        if (it == neb.end()) {
            it = neb.lower_bound(0);
        }
        ll cnx = *it;
        // cout << "## B #" << endl;
        // for(auto e : b) cout << e << ' '; cout << endl;
        // cout << ind << ' ' << cnx << endl;
        if (val) {
            ll inc = (cnx + n - ind) % n;
            if (cnx == ind) {
                inc = n;
            }
            Q.push({pri + inc, val, cnx});
        }
    }
}

/*
1 2 3 4
4 3 2 1
#
3 0 0 1
3 1 0 0
#
1 2 3 4
4 3 2 1

*/

int main() {
    HEADER;
    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++) {
        TC();
    }
    return 0;
}