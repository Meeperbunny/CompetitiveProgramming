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
    int n, f, g; cin >> n>>f>>g;
    vector<set<int>> F(n), G(n);
    while(f--) {
        int a, b;cin>>a>>b;
        a--;b--;
        F[a].insert(b);
        F[b].insert(a);
    }
    while(g--) {
        int a, b;cin>>a>>b;
        a--;b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    // Dsu
    union_find dsu(n);
    for(int i = 0; i < n; i++) for(auto e : G[i]) {
        dsu.unite(i, e);
    }
    int dt = 0;
    for(int i = 0; i < n; i++) {
        vector<int> trm;
        for(auto e : F[i]) {
            if (dsu.find(i) == dsu.find(e)) {
                // Edge is fine.
            }
            else {
                // Should remove.
                // cout << "Removing " << i << ' ' << e << endl;
                dt++;
                trm.push_back(e);
            }
        }
        for(auto e : trm) F[i].erase(e);
    }
    // Need to add where not the same
    union_find fgroups(n);
    for(int i = 0; i < n; i++) for(auto e : F[i]) {
        fgroups.unite(i, e);
    }
    vector<set<int>> groups(n);
    for(int i = 0; i < n; i++) {
        groups[dsu.find(i)].insert(fgroups.find(i));
    }
    for(int i = 0; i < n; i++) {
        dt += 2 * (groups[i].size() ? groups[i].size() - 1 : 0);
    }
    cout << dt / 2 << endl;
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