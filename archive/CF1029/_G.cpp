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
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        size.assign(n, 1);
        components = n;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
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
    int n, m;
    cin >> n >> m;
    vector<tuple<ll, int, int>> e(m);
    for(auto &el : e) {
        ll a, b, c;
        cin >> a >> b>> c;
        a--, b--;
        el = {c, a, b};
    }
    sort(all(e));
    union_find dsu(n);
    vector<pair<ll, ll>> mins(n, {LLONG_MAX, 0});
    ll best = LLONG_MAX;
    for(auto &[w, a, b] : e) {
        // Join a and b. If is connected to end, then update with min edge in CC.
        // otherwise dont do
        int oa = dsu.find(a);
        int ob = dsu.find(b);
        dsu.unite(a, b);
        // Update the combined with the min of both.
        // Update the combined with the max of both.
        int comb = dsu.find(a);
        mins[comb].first = min({
            mins[comb].first, w, mins[oa].first, mins[ob].first
        });
        mins[comb].second = max({
            mins[comb].second, w, mins[oa].second, mins[ob].second
        });
        int cc = dsu.find(0);
        if (cc == dsu.find(n - 1)) {
            best = min(best, mins[cc].second + mins[cc].first);
        }
    }
    cout << best << endl;
    
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