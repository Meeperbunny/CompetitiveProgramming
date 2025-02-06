class SegmentTree {
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
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        vector<int> a(n, 0);
        build(a, 1, 0, n - 1);
    }

    // Constructor to initialize and build the Segment Tree from an array
    SegmentTree(const vector<int>& a) {
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
