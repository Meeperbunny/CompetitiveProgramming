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

class SegmentTree {
private:
    std::vector<long long> tree, lazy;
    int n;

    void buildTree(int start, int end, int node) {
        if (start == end) {
            tree[node] = 0;
        } else {
            int mid = (start + end) / 2;
            buildTree(start, mid, 2 * node + 1);
            buildTree(mid + 1, end, 2 * node + 2);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void updateRangeUtil(int node, int start, int end, int l, int r, long long value) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > r || end < l) {
            return;
        }

        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * value;
            if (start != end) {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRangeUtil(2 * node + 1, start, mid, l, r, value);
        updateRangeUtil(2 * node + 2, mid + 1, end, l, r, value);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    long long queryRangeUtil(int node, int start, int end, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > r || end < l) {
            return 0;
        }

        if (start >= l && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        long long leftSum = queryRangeUtil(2 * node + 1, start, mid, l, r);
        long long rightSum = queryRangeUtil(2 * node + 2, mid + 1, end, l, r);
        return leftSum + rightSum;
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        buildTree(0, n - 1, 0);
    }

    void updateRange(int l, int r, long long value) {
        updateRangeUtil(0, 0, n - 1, l, r, value);
    }

    long long queryRange(int l, int r) {
        return queryRangeUtil(0, 0, n - 1, l, r);
    }
};

void TC() {
    ll n, k;
    cin >> n >> k;
    ll mael = -1;
    vector<ll> a(n);
    for(auto &e : a) {
        cin >> e;
        mael = max(mael, e);
    }
    SegmentTree tree(2 * k);
    for(auto e : a) {
        ll ne = (e - mael) % (2 * k);
        if (ne != 0) {
            // UPPER
            int lower = 2 * k + ne;
            int upper = 2 * k - 1;
            // dbg(ne, lower, upper);
            tree.updateRange(lower, upper, 1);
        }
        if (-ne < k) {
            // Lower
            int lower = 0;
            int upper = k + ne - 1;
            // dbg(ne, lower, upper);
            tree.updateRange(lower, upper, 1);
        }
        // for(int i = 0; i < 2 * k; i++) {
        //     cout << (tree.queryRange(i, i)) << ' ';
        // }
        // cout << endl;
    }
    for(int i = 0; i < 2 * k; i++) {
        if (tree.queryRange(i, i) == n) {
            cout << i + mael << endl;
            return;
        }
    }
    cout << -1 << endl;
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