#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

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

struct CInfo {
    bool hasma[2] = {0, 0};
    ll sz = 1;
    ll cont = 0;
    ll lind;
    void calc_cont() {
        cont = (sz + 1) / 2;
    }
};

void TC() {
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    ll ma = *max_element(all(a));
    vector<CInfo> cs(n);
    vector<ll> inds(n);
    iota(all(inds), 0);
    sort(all(inds), [&](ll i, ll j){
        return a[i] > a[j];
    });
    vector<bool> checked(n, false);
    union_find dsu(n);
    ll tot = 0;
    ll best = 0;
    ll minel = LLONG_MAX;
    ll maxelcnt = 0;
    ll oddatind1c = 0;
    for(ll q = 0; q < n; q++) {
        ll i = inds[q];
        checked[i] = true;
        // Update mins
        minel = min(minel, a[i]);
        int cg = dsu.find(i);
        if (a[i] == ma) {
            cs[cg].hasma[0] = true;
            maxelcnt += 1;
        }
        cs[cg].lind = i;
        // Unite my group with groups around me.
        set<ll> tounite;
        set<ll> touniteinds;
        if (i != 0 && checked[i - 1]) {
            tounite.insert(dsu.find(i - 1));
            touniteinds.insert(i - 1);
        }
        tounite.insert(dsu.find(i));
        if (i != n - 1 && checked[i + 1]) {
            tounite.insert(dsu.find(i + 1));
            touniteinds.insert(i + 1);
        }
        // Remove contributions from total, update counts.
        for(auto e : tounite) {
            tot -= cs[e].cont;
            maxelcnt -= ll(cs[e].hasma[0] || cs[e].hasma[1]);
            oddatind1c -= ll(!cs[e].hasma[0] && cs[e].hasma[1] && cs[e].sz % 2 == 1);
        }
        // Combine mine with other's
        CInfo newinfo;
        newinfo.lind = n + 1;
        for(auto e : tounite) newinfo.lind = min(cs[e].lind, newinfo.lind);
        newinfo.sz = 0;
        for(auto e : tounite) newinfo.sz += cs[e].sz;
        for(auto e : tounite) {
            CInfo &r = cs[e];
            newinfo.hasma[0] |= r.hasma[(r.lind - newinfo.lind) % 2];
            newinfo.hasma[1] |= r.hasma[1 - (r.lind - newinfo.lind) % 2];
        }
        newinfo.calc_cont();
        // Add contributions to total and update counts.
        tot += newinfo.cont;
        for(auto e : touniteinds) {
            dsu.unite(e, i);
        }
        ll nw = dsu.find(i);
        cs[nw] = newinfo;
        maxelcnt += ll(cs[nw].hasma[0] || cs[nw].hasma[1]);
        oddatind1c += ll(!cs[nw].hasma[0] && cs[nw].hasma[1] && cs[nw].sz % 2 == 1);
        best = max(best, tot + ma + minel - ll(maxelcnt == oddatind1c));
    }
    cout << best << endl;
}

int main() {
    HEADER;
    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++) {
        TC();
    }
    return 0;
}