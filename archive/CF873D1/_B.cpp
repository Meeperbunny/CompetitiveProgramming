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
class MinSegmentTree {
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
            tree[v] = min(tree[v*2], tree[v*2+1]);
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
            return INT_MAX; // Return the smallest integer when the range is invalid
        if (l <= tl && tr <= r) {
            return tree[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        return min(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
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
            tree[v] = min(tree[v*2], tree[v*2+1]);
        }
    }

public:
    // Constructor to initialize and build the Segment Tree with zeros
    MinSegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        vector<int> a(n, 0);
        build(a, 1, 0, n - 1);
    }

    // Constructor to initialize and build the Segment Tree from an array
    MinSegmentTree(const vector<int>& a) {
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

ll solve(vector<int> &a) {
    int n = a.size();
    for(int l = 0; l < n; l++) {
        for(int r = l; r < n; r++) {
            
        }
    }
}

void TC() {
    ll n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    MaxSegmentTree maxTree(a);
    MinSegmentTree minTree(a);
    vector<ll> cnt(n, 1);
    ll cc = 0;
    ll t = 0;
    for(ll i = 1; i < n; i++) {
        if (a[i - 1] < a[i]) {
            cc += 1;
        } else {
            t += cc;
            cc = 0;
        }
    }
    t += cc;
    for(ll i = 0; i < n; i++) {
        t += (i * (i + 1)) / 2;
        ll r = i + 1;
        for(ll j = n; j >= 1; j >>= 1) {
            while(true) {
                ll nr = r + j;
                if (nr > n) break;
                // cout << i << ' ' << nr << ' ' << a[i] << ' ' << minTree.query(i + 1, nr - 1) << endl;
                if (a[i] < minTree.query(i + 1, nr - 1)) {
                    r = nr;
                }
                else {
                    break;
                }
            }
        }
        // cout << a[i] << ' ' << i << ' ' << r << endl;
        t -= r - i - 1;

        ll l = i - 1;
        for(ll j = n; j >= 1; j >>= 1) {
            while(true) {
                ll nl = l - j;
                if (nl < -1) break;
                // cout << i << ' ' << nl + 1 << "  " << i - 1  << ' ' << a[i] << ' ' << maxTree.query(nl + 1, i - 1) << endl;
                if (a[i] > maxTree.query(nl + 1, i - 1)) {
                    l = nl;
                }
                else {
                    break;
                }
            }
        }
        t -= i - l - 1;

        // for(int q = i - 1; q >= -1; q--) {
        //     l = q;
        //     if (l == -1) break;
        //     if (a[q] > a[i]) {
        //         break;
        //     }
        // }
    }
    cout << t << endl;
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