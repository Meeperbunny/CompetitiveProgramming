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

int arr[2001][2001];

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

bool dfs(int c, int l, vector<vector<int>> &adj, vector<bool> &seen) {
    // Look at last. For all that have been seen, dist[last, e] = dist[curr, e] + dist[curr, last]
    if (l != -1) {
        for(int i = 0; i < adj.size(); i++) {
            if (seen[i]) {
                // cout << c << ' ' << l << ' ' << i << "   " << arr[l][i] + arr[c][l] << ' ' << arr[c][i] << endl;
                if (arr[l][i] + arr[c][l] != arr[c][i]) {
                    return false;
                }
            }
        }
    }
    seen[c] = true;
    for(auto e : adj[c]) {
        if (e != l) {
            if (!dfs(e, c, adj, seen)) return false;
        }
    }
    return true;
}

void TC() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < n; q++) {
            cin >> arr[i][q];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int q = 0; q < n; q++) {
            if ((i == q && arr[i][q] != 0) || (arr[i][q] != arr[q][i]) || (i != q && arr[i][q] == 0)) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    if (n == 1) {
        cout << "YES" << endl;
        return;
    }

    union_find dsu(n);
    vector<vector<int>> adj(n);
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < n; q++) {
            edges.push_back({arr[i][q], {i, q}});
        }
    }
    sort(edges.begin(), edges.end());
    for(auto &e : edges) {
        int i = e.second.first, q = e.second.second;
        if (dsu.find(i) == dsu.find(q)) continue;
        else {
            dsu.unite(i, q);
            adj[i].push_back(q);
            adj[q].push_back(i);
        }
    }


    // Check that all distances are good
    int theind = -1;
    for(int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            theind = i;
            break;
        }    
    }
    
    vector<bool> seen(n, false);
    bool res = dfs(theind, -1, adj, seen);
    if (res) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
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