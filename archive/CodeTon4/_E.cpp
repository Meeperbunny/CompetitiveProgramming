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
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin>> a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> order(n);
    vector<int> sz(n, -1);
    vector<int> hsize(n, -1);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j){
        return a[i] < a[j];
    });
    union_find dsu(n);
    for(auto ind : order) {
        int i = dsu.find(ind);
        hsize[i] = 1;
        set<int> seen;
        bool good = (a[ind] == 0);
        for(auto e : adj[ind]) {
            int clu = dsu.find(e);
            if (seen.count(clu)) continue;
            seen.insert(clu);
            if (hsize[clu] != -1) {
                if (sz[clu] >= a[ind]) {
                    good = true;
                }
                hsize[i] += hsize[clu];
            }
        }


        seen.clear();
        for(auto e : adj[ind]) {
            int clu = dsu.find(e);
            if (clu == dsu.find(ind) || seen.count(clu)) continue;
            seen.insert(clu);
            if (hsize[clu] != -1) {
                dsu.unite(ind, e);
            }
        }
        int res = dsu.find(ind);
        int newsz = hsize[i];
        hsize[res] = newsz;


        if (good) {
            sz[res] = newsz;
            if (sz[res] == n) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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