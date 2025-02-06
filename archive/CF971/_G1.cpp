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

class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            // Recursively build the segment tree
            build(leftChild, start, mid);
            build(rightChild, mid + 1, end);
            // Internal node will have the maximum of the two children
            tree[node] = max(tree[leftChild], tree[rightChild]);
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            // Leaf node
            arr[idx] = value;
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            if (start <= idx && idx <= mid) {
                // If idx is in the left child, recurse on the left child
                update(leftChild, start, mid, idx, value);
            } else {
                // If idx is in the right child, recurse on the right child
                update(rightChild, mid + 1, end, idx, value);
            }
            // Internal node will have the maximum of the two children
            tree[node] = max(tree[leftChild], tree[rightChild]);
        }
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            // range represented by a node is completely outside the given range
            return INT_MIN;
        }
        if (L <= start && end <= R) {
            // range represented by a node is completely inside the given range
            return tree[node];
        }
        // range represented by a node is partially inside and partially outside the given range
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        int leftMax = query(leftChild, start, mid, L, R);
        int rightMax = query(rightChild, mid + 1, end, L, R);
        return max(leftMax, rightMax);
    }

public:
    SegmentTree(const vector<int>& inputArr) {
        arr = inputArr;
        n = arr.size();
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    int query(int L, int R) {
        return query(0, 0, n - 1, L, R);
    }
};

void TC() {
    int n, k, Q;
    cin >> n >> k >> Q;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    vector<int> incc(n);
    int cnt = 1;
    incc[0] = 1;
    for(int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) {
            cnt++;
        }
        else {
            cnt = 1;
        }
        incc[i] = cnt;
    }
    vector<pair<pair<ll, ll>, ll>> queries(Q);
    for(int q= 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;
        queries[q] = {{l - 1, r - 1}, q};
    }
    vector<ll> ans(Q);
    sort(all(queries));
    SegmentTree tree(incc);
    int currpeak = incc[0];
    int P = 0;
    for(int i = 0; i < Q; i++) {
        int l = queries[i].first.first;
        int r = queries[i].first.second;
        if (P < l) {
            P = l;
            currpeak = incc[P];
            while(P + 1 < n && incc[P + 1] > currpeak) {
                currpeak = incc[P + 1];
                P++;
            }
        }
        int q_l = P + 1;
        int maxincR = 0;
        if (q_l <= r) {
            maxincR = tree.query(q_l, r);
        }
        int truepeak = min((P - l + 1), currpeak);
        // dbg(queries[i].second, maxincR, truepeak);
        ans[queries[i].second] = (r - l + 1) - max(maxincR, truepeak);
    }
    for(int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }


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