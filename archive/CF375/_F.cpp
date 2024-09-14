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
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        edges[i] = {a, b};
    }
    int s,t,ds, dt;
    cin >> s >> t >> ds >> dt;
    s--, t--;
    vector<pair<int, int>> ans;
    union_find dsu(n);
    for(auto &edge : edges) {
        if (edge.first != s && edge.first != t) {
            if (edge.second != s && edge.second != t) {
                if (dsu.find(edge.first) != dsu.find(edge.second)) {
                    dsu.unite(edge.first, edge.second);
                    ans.push_back({edge.first, edge.second});
                }
            }
        }
    }
    // Check which ones A must unite with
    // Check which ones B must unite with
    // They should do ones that only they can do
    // Leave rest up for picking
    // Have to unite to a combined one or to eachother
    map<int, pair<int, int>> ato, bto;
    set<int> acan, bcan;
    for(auto &edge : edges) {
        if (edge.first == s || edge.second == s) {
            int other = dsu.find(edge.first + edge.second - s);
            ato[other] = edge;
            acan.insert(other);
        }
        if (edge.first == t || edge.second == t) {
            int other = dsu.find(edge.first + edge.second - t);
            bto[other] = edge;
            bcan.insert(other);
        }
    }
    set<int> bothcan;
    for(auto e : acan) {
        if (bcan.count(e)) {
            bothcan.insert(e);
        }
    }
    for(auto e : bothcan) {
        acan.erase(e);
        bcan.erase(e);
    }
    // For each that a can, do it.
    for(auto e : acan) {
        // Do it
        if (e == dsu.find(t)) continue;
        ans.push_back(ato[e]);
        ds--;
    }
    for(auto e : bcan) {
        // Do it
        if (e == dsu.find(s)) continue;
        ans.push_back(bto[e]);
        dt--;
    }
    bool unitedThem = false;
    if (bothcan.size()) {
        // Assign them greedily, get one for both
        bool F = true;
        for(auto e : bothcan) {
            // if (ans.size() == n - 1) break;
            if (F) {
                if (ds <= 0 || dt <= 0) {
                    cout << "No" << endl;
                    return;
                }
                else {
                    ds--, dt--;
                    ans.push_back(ato[e]);
                    ans.push_back(bto[e]);
                    unitedThem = true;
                }
                F = false;
            }
            else if (ds > 0) {
                ans.push_back(ato[e]);
                ds--;
            }
            else if (dt > 0) {
                ans.push_back(bto[e]);
                dt--;
            }
            else {
                cout << "No" << endl;
                return;
            }
        }
    }
    else {
        // Need to have an edge between them
        if (ato.count(dsu.find(t))) {
            ans.push_back(ato[dsu.find(t)]);
            ds--, dt--;
            unitedThem = true;
        }
        else {
            cout << "No" << endl;
            return;
        }
    }
    if (!unitedThem || ds < 0 || dt < 0 || ans.size() != n - 1) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    for(auto e : ans) {
        cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }
}

int main() {
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}