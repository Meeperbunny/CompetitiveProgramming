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

class LazySegmentTree {
    int n;
    vector<int> tree, lazy;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int value) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * value;
            if (start != end) {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, l, r, value);
        updateRange(2 * node + 2, mid + 1, end, l, r, value);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int queryRange(int node, int start, int end, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > end || start > r || end < l) return 0;
        if (start >= l && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int leftSum = queryRange(2 * node + 1, start, mid, l, r);
        int rightSum = queryRange(2 * node + 2, mid + 1, end, l, r);
        return leftSum + rightSum;
    }

public:
    LazySegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    void updateRange(int l, int r, int value) {
        updateRange(0, 0, n - 1, l, r, value);
    }

    int queryRange(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }
};

int dfs(int c, int l, vector<vector<int>> &adj, int d, LazySegmentTree& tree) {
    int minlayer = d;
    int upperlayer = d;
    for(auto e : adj[c]) if (l != e) {
        upperlayer = max(upperlayer, dfs(e, c, adj, d + 1, tree));
    }
    tree.updateRange(minlayer, upperlayer, -1);
    return upperlayer;
}

void TC() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> parent(n, -1);
    int mld = INT_MAX;
    for(int i = 0; i < n - 1; i++) {
        int a,b;cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> treeinit(n, n);
    LazySegmentTree tree(treeinit);
    dfs(0, -1, adj, 0, tree);
    int mi = n;
    for(int i = 0; i < n; i++) {
        mi = min(mi, tree.queryRange(i, i));
    }
    cout << mi << endl;
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