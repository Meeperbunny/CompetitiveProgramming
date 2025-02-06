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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
    vector<vector<int>> segTree;
    int n;

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        segTree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            segTree[node].push_back(arr[start]);
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            merge(segTree[2 * node + 1].begin(), segTree[2 * node + 1].end(),
                  segTree[2 * node + 2].begin(), segTree[2 * node + 2].end(),
                  back_inserter(segTree[node]));
        }
    }

    int query(int node, int start, int end, int l, int r, int x) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return segTree[node].end() - upper_bound(segTree[node].begin(), segTree[node].end(), x);
        }
        int mid = (start + end) / 2;
        int leftQuery = query(2 * node + 1, start, mid, l, r, x);
        int rightQuery = query(2 * node + 2, mid + 1, end, l, r, x);
        return leftQuery + rightQuery;
    }

    int range_query(int l, int r, int x) {
        return query(0, 0, n - 1, l, r, x);
    }
};

void TC() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    SegmentTree tree(a);
    vector<vector<pair<int, int>>> Q(200001);
    vector<bool> ans(q, 0);
    for(int i = 0; i < q; i++) {
        int q, x;
        cin >> q >> x;
        q--;
        Q[x].push_back({q, i});
    }
    for(int z = 1; z <= 200000; z++) {
        cout << z << endl;
        if (Q[z].empty()) continue;
        int ind = 0;
        sort(Q[z].begin(), Q[z].end());
        int K = z;
        int base = 0;
        int currlevel = 1;
        while(base < n) {
            cout << base << endl;
            int ub = base - 1;
            for(int j = n; j > 0; j >>= 1) {
                while(true) {
                    int nind = ub + j;
                    if (nind >= n) break;
                    if (tree.range_query(base, nind, currlevel - 1) < K) {
                        ub = nind;
                    } else break;
                }
            }
            ub++;
            // cout << K << "    " << currlevel << " " << base << ' ' << ub << endl;
            // Answer queries here
            while (ind < Q[z].size() && Q[z][ind].first >= base && Q[z][ind].first <= ub) {
                // cout << "Checking " << K << ' ' << Q[z][ind].second << ' ' << a[Q[z][ind].first] << endl;
                if (currlevel <= a[Q[z][ind].first]) {
                    ans[Q[z][ind].second] = true;
                }
                ind++;
            }
            base = ub + 1;
            currlevel++;
        }
    }
    
    for(auto e : ans) {
        if (e) cout << "YES" << endl;
        else cout << "NO" << endl;
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