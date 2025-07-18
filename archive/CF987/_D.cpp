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

class MaxSegmentTree {
    private:
        vector<int> tree, lazy;
        int n;
    
        // Helper function to build the Segment Tree
        void build(const vector<int>& a, int v, int tl, int tr) {
            if (tl == tr) {
                tree[v] = a[tl];
            } else {
                int tm = (tl + tr) / 2;
                build(a, v*2, tl, tm);
                build(a, v*2+1, tm+1, tr);
                tree[v] = max(tree[v*2], tree[v*2+1]);
            }
        }
    
        // Helper function to propagate the lazy updates
        void push(int v) {
            if (lazy[v] != 0) {
                tree[v*2] += lazy[v];
                lazy[v*2] += lazy[v];
                tree[v*2+1] += lazy[v];
                lazy[v*2+1] += lazy[v];
                lazy[v] = 0;
            }
        }
    
        // Helper function to perform range max query
        int query(int v, int tl, int tr, int l, int r) {
            if (l > r)
                return INT_MIN; // Return the smallest integer when the range is invalid
            if (l <= tl && tr <= r) {
                return tree[v];
            }
            push(v);
            int tm = (tl + tr) / 2;
            return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
        }
    
        // Helper function to perform range update
        void update(int v, int tl, int tr, int l, int r, int addend) {
            if (l > r)
                return;
            if (l <= tl && tr <= r) {
                tree[v] += addend;
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
        // Constructor to initialize and build the Segment Tree with zeros
        MaxSegmentTree(int size) {
            n = size;
            tree.resize(4 * n);
            lazy.resize(4 * n, 0);
            vector<int> a(n, 0);
            build(a, 1, 0, n - 1);
        }
    
        // Constructor to initialize and build the Segment Tree from an array
        MaxSegmentTree(const vector<int>& a) {
            n = a.size();
            tree.resize(4 * n);
            lazy.resize(4 * n, 0);
            build(a, 1, 0, n - 1);
        }
    
        // Public function to perform range max query
        int query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
    
        // Public function to perform range update
        void update(int l, int r, int addend) {
            update(1, 0, n - 1, l, r, addend);
        }
    };
    

void TC() {
    int n; cin >> n;
    vector<int> a(n), ans(n);
    for(auto &e : a) cin >> e;

    set<int> freeinds;
    map<int, vector<int>> numToInd;
    for(int i = 0; i < n; i++) {
        freeinds.insert(i);
        numToInd[a[i]].push_back(i);
    }

    MaxSegmentTree tree(n);


    // For each, at i, get the max from empty rightmost that is not myself. Set myself in the segtree equal to my max DELAYED.
    for(auto it = numToInd.rbegin(); it != numToInd.rend(); it++) {
        auto &[num, v] = *it;
        vector<pair<int, int>> updates;
        for(auto i : v) {
            freeinds.erase(i);
        }

        for(auto i : v) {
            int rm = i;
            if (freeinds.size()) {
                rm = max(rm, *freeinds.rbegin());
            }
            // Get segtree at this.
            int b = max(num, tree.query(0, rm));
            ans[i] = b;
        }
        for(auto i : v) {
            tree.update(i, i, ans[i]);
        }
    }
    for(auto e : ans) cout << e << ' '; cout << endl;
    
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