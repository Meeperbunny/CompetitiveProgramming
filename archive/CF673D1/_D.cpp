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

vector<vector<int>> getConnectedComponents(vector<set<int>> &adj) {
    const int n = adj.size();
    vector<vector<int>> ret;
    vector<bool> seen(n, false);
    for(int i = 0; i < n; i++) {
        if (!seen[i]) {
            ret.push_back({});
            queue<int> Q;
            Q.push(i);
            seen[i] = true;
            while(Q.size()) {
                int c = Q.front();
                Q.pop();
                seen[c] = true;
                ret.back().push_back(c);
                for(auto e : adj[c]) {
                    if (!seen[e]) {
                        Q.push(e);
                        seen[e] = true;
                    }
                }
            }
        }
    }
    return ret;
}

class SegmentTree {
    private:
        vector<pair<int, int>> tree;
        vector<int> lazy;
        int n;
    
        void build(const vector<int>& a, int v, int tl, int tr) {
            if (tl == tr) {
                tree[v] = {a[tl], tl};
            } else {
                int tm = (tl + tr) / 2;
                build(a, v*2, tl, tm);
                build(a, v*2+1, tm+1, tr);
                tree[v] = max(tree[v*2], tree[v*2+1]);
            }
        }
    
        void push(int v) {
            if (lazy[v] != 0) {
                for (int u : {v*2, v*2+1}) {
                    tree[u].first += lazy[v];
                    lazy[u] += lazy[v];
                }
                lazy[v] = 0;
            }
        }
    
        pair<int, int> query(int v, int tl, int tr, int l, int r) {
            if (l > r)
                return {INT_MIN, -1};
            if (l <= tl && tr <= r)
                return tree[v];
            push(v);
            int tm = (tl + tr) / 2;
            auto left = query(v*2, tl, tm, l, min(r, tm));
            auto right = query(v*2+1, tm+1, tr, max(l, tm+1), r);
            return max(left, right);
        }
    
        void update(int v, int tl, int tr, int l, int r, int addend) {
            if (l > r)
                return;
            if (l <= tl && tr <= r) {
                tree[v].first += addend;
                lazy[v] += addend;
            } else {
                push(v);
                int tm = (tl + tr) / 2;
                update(v*2, tl, tm, l, min(r, tm), addend);
                update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
                tree[v] = max(tree[v*2], tree[v*2+1]);
            }
        }
    
    public:
        SegmentTree(int size) {
            n = size;
            tree.resize(4 * n);
            lazy.resize(4 * n, 0);
            vector<int> a(n, 0);
            build(a, 1, 0, n - 1);
        }
    
        SegmentTree(const vector<int>& a) {
            n = a.size();
            tree.resize(4 * n);
            lazy.resize(4 * n, 0);
            build(a, 1, 0, n - 1);
        }
    
        pair<int, int> query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
    
        void update(int l, int r, int addend) {
            update(1, 0, n - 1, l, r, addend);
        }
    };
    

void TC() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n);
    for(auto &e : p) {
        cin >> e;
    }
    vector<pair<int, int>> edges(m);
    vector<set<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        edges[i] = {a, b};
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vector<pair<int, int>> ops(q);
    for(auto &e : ops) {
        cin >> e.first >> e.second;
        e.second -= 1;
    }
    // Idea is as follows
    // Add seperation and joining operatinons to the original graph to be used.
    vector<pair<int, int>> newops;
    vector<vector<int>> ccs = getConnectedComponents(adj);
    for(int i = 1; i < ccs.size(); i++) {
        int a = ccs[0][0];
        int b = ccs[i][0];
        newops.push_back({2, edges.size()});
        edges.push_back({a, b});
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for(auto e : ops) {
        newops.push_back(e);
    }
    swap(newops, ops);
    // Seperate the graph given the operations in order.
    auto radj(adj);
    for(auto e : ops) {
        if (e.first == 2) {
            assert(radj[edges[e.second].first].count(edges[e.second].second));
            assert(radj[edges[e.second].second].count(edges[e.second].first));
            radj[edges[e.second].first].erase(edges[e.second].second);
            radj[edges[e.second].second].erase(edges[e.second].first);
        }
    }
    // For each group, assign some ascending offset (0, 1, 2... n - 1)
    vector<int> offsets(n);
    ccs = getConnectedComponents(radj);
    for(auto e : ccs) {
        for(int i = 0; i < e.size(); i++) {
            assert(e[i] < offsets.size());
            offsets[e[i]] = i;
        }
    }
    struct Node {
        int left = -1;
        int right = -1;
        int ccind = -1;
        int size = 0;
        int loff = -1;
        int lsz = -1;
    };
    vector<Node> nodes;
    vector<int> dsuToInd(n);
    union_find dsu(n);
    for(int i = 0; i < ccs.size(); i++) {
        Node node;
        node.ccind = i;
        for(auto e : ccs[i]) {
            dsu.unite(e, ccs[i][0]);
        }
        int cind = dsu.find(ccs[i][0]);
        node.size = dsu.size[cind];
        dsuToInd[cind] = nodes.size();
        nodes.push_back(node);
    }
    // Iterate reverse, create a tree on each join

    vector<int> optonode(ops.size(), -1);
    for(int i = ops.size() - 1; i >= 0; i--) {
        auto &cop = ops[i];
        if (cop.first == 2) {
            // Join the two ccs
            assert(cop.second < edges.size());
            auto edge = edges[cop.second];
            int a = edge.first, b = edge.second;
            int A = dsuToInd[dsu.find(a)], B = dsuToInd[dsu.find(b)];
            Node newNode;
            newNode.left = A, newNode.right = B;
            if (A == B) continue;
            dsu.unite(a, b);
            newNode.size = nodes[A].size + nodes[B].size;
            int newcc = dsu.find(a);
            optonode[i] = nodes.size();
            dsuToInd[newcc] = nodes.size();
            nodes.push_back(newNode);
        }
    }
    // DFS down the tree, add left size to right offset, return the size of the subtree (the offset).
    vector<int> order(n);
    auto dfs = [&](auto &dfs, int i, int offset) -> int {
        Node &curr = nodes[i];
        if (curr.ccind != -1) {
            // Set each at the offset
            for(int q = 0; q < ccs[curr.ccind].size(); q++) {
               order[ccs[curr.ccind][q]] = offset + q;
            }
            return ccs[curr.ccind].size();
        }
        else {
            int l = curr.left;
            int r = curr.right;
            int lsz = dfs(dfs, l, offset);
            int rsz = dfs(dfs, r, offset + lsz);
            curr.loff = offset;
            curr.lsz = lsz;
            return lsz + rsz;
        }
    };
    dfs(dfs, nodes.size() - 1, 0);
    vector<int> themax(n);
    for(int i = 0; i < order.size(); i++) {
        themax[order[i]] = p[i];
    }
    // The tree will mark a mapping of query index -> left subtree size
    // Now rejoin everything and iterate through the queries. Keep a set of the intervals and their lengths
    //     splitting at each query
    SegmentTree st(themax);
    map<int, int> incintervals;
    incintervals.insert({0, n});
    for(int i = 0; i < ops.size(); i++) {
        auto [op, el] = ops[i];
        if (op == 1) {
            int ind = order[el];
            // cout << "INCINTEVA" << endl;
            // for(auto e : incintervals) cout << e.first << ',' << e.second << "  " << endl;
            // cout << "IND " << ind << endl;
            auto it = prev(incintervals.upper_bound(ind));
            int L = it->first, R = it->first + it->second - 1;
            assert(0 <= L && L <= R && R <= n - 1);
            auto [ma, mind] = st.query(L, R);
            // cout << "TESTING " << el << ' ' << L << ' ' << R << endl;
            // for(int i = 0; i < n; i++) cout << st.query(i, i).first << ' ';
            // cout << endl;
            cout << ma << '\n';
            assert(mind >= 0);
            assert(ma >= 0);
            st.update(mind, mind, -ma);
        }
        else {
            if (optonode[i] == -1) {
                continue;
            }
            Node &node = nodes[optonode[i]];
            int rbp = node.lsz + node.loff;
            assert(incintervals.upper_bound(rbp) != incintervals.begin());
            auto it = prev(incintervals.upper_bound(rbp));
            int pos = it->first, size = it->second;
            incintervals.erase(it);
            int ls = pos, lsz = node.lsz;
            int rs = pos + lsz, rsz = size - lsz;
            // cout << "SPLITTING " << ls << ' ' << lsz << "   " << rs << ' ' << rsz << endl;
            incintervals[ls] = lsz;
            incintervals[rs] = rsz;
        }
    }
    // On query for some node, do a search for interval given node->index mapping from the dfs
    // Query this in the segment tree
    // Update this in the segment tree
    // Return


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