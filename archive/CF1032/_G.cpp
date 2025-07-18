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

class SegmentTree {
    vector<vector<int>> segTree;
    vector<int> arr;
    int n;

public:
    SegmentTree(int n) : n(n), arr(n, 0) {
        segTree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            segTree[node].push_back(arr[start]);
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            merge(segTree[2 * node + 1].begin(), segTree[2 * node + 1].end(),
                  segTree[2 * node + 2].begin(), segTree[2 * node + 2].end(),
                  back_inserter(segTree[node]));
        }
    }

    void add_to_index(int node, int start, int end, int idx, int v) {
        // Remove old value
        auto& vec = segTree[node];
        auto it = lower_bound(vec.begin(), vec.end(), arr[idx]);
        if (it != vec.end() && *it == arr[idx]) vec.erase(it);

        // Update value
        arr[idx] += v;

        // Insert new value
        vec.insert(upper_bound(vec.begin(), vec.end(), arr[idx]), arr[idx]);

        if (start == end) return;

        int mid = (start + end) / 2;
        if (idx <= mid)
            add_to_index(2 * node + 1, start, mid, idx, v);
        else
            add_to_index(2 * node + 2, mid + 1, end, idx, v);
    }

    void add(int idx, int v) {
        add_to_index(0, 0, n - 1, idx, v);
    }

    int query(int node, int start, int end, int l, int r, int x) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) {
            return segTree[node].end() - upper_bound(segTree[node].begin(), segTree[node].end(), x);
        }
        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r, x)
             + query(2 * node + 2, mid + 1, end, l, r, x);
    }

    int range_query(int l, int r, int x) {
        return query(0, 0, n - 1, l, r, x);
    }
};


void TC() {
    int n;
    string s;
    cin >> n >> s;
    auto getOnes = [&](string &s) -> ll {
        int n = s.size();
        SegmentTree tree(n * 2 + 1);
        ll currentZero = n;
        ll t = 0;
        ll zt = 0;
        for(int i = 0; i < n; i++) {
            tree.add(currentZero, 1);
            int mv = -1;
            if (s[i] == '1') {
                mv = 1;
            }
            currentZero -= mv;
        }
        // Shift all by current
        // Add current to weight
        // Add all positive, add 0.
        // Return cnt
    };
    ll t = 0;
    t += getOnes(s);
    for(auto &e : s) e = (e == '0' ? '1' : '0');
    t += getOnes(s);
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