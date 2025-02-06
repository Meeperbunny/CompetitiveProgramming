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
    vector<int> tree;
    vector<int> array;
    int n;
    int target; // The target value we are counting

    // Helper function to build the Segment Tree
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = (array[tl] == target) ? 1 : 0;
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    // Helper function to perform range query
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l <= tl && tr <= r) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    // Helper function to perform point update
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            tree[v] = (new_val == target) ? 1 : 0;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

public:
    // Constructor to initialize and build the Segment Tree
    SegmentTree(const vector<int>& a, int k) {
        n = a.size();
        array = a;
        target = k;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    // Public function to perform range query
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    // Public function to perform point update
    void update(int pos, int new_val) {
        array[pos] = new_val;
        update(1, 0, n - 1, pos, new_val);
    }
};


void TC() {
    // Either use 2 or 1 and 1.
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> qs;
    vector<pair<int, int>> a(m);
    vector<int> cnts(n, 0);
    for(int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first--, a[i].second--;
        qs.push_back({a[i].first, -(i + 1)});
        qs.push_back({a[i].second, (i + 1)});
    }
    sort(qs.begin(), qs.end());
    int curr = 0;
    int ptr = 0;
    set<int> inset;
    vector<pair<int, int>> isTwo(n, {-1, -1});
    for(int i = 0; i < n; i++) {
        while(ptr != qs.size() && qs[ptr].first == i && qs[ptr].second < 0) {
            int ind = -qs[ptr].second - 1;
            inset.insert(ind);
            curr += 1;
            ptr++;
        }
        cnts[i] = curr;
        if (inset.size() == 2) {
            isTwo[i] = {*inset.begin(), *inset.rbegin()};
        }
        while(ptr != qs.size() && qs[ptr].first == i && qs[ptr].second > 0) {
            int ind = qs[ptr].second - 1;
            inset.erase(ind);
            curr -= 1;
            ptr++;
        }
    }
    SegmentTree zeroTree(cnts, 0), oneTree(cnts, 1), twoTree(cnts, 2);
    // Find max for two elements
    int ans = 0;
    pair<int, int> maxes = {0, 0};
    for(int i = 0; i < m; i++) {
        int l = a[i].first, r = a[i].second;
        int t = oneTree.query(l, r);
        // cout << i << ' ' << t << endl;
        if (t > maxes.first) swap(t, maxes.first);
        if (t > maxes.second) swap(t, maxes.second);
    }
    ans = zeroTree.query(0, n - 1) + maxes.first + maxes.second;

    // cout << "A" << ans << endl;

    for(int i = 0; i < n; i++) {
        if (isTwo[i].first != -1) {
            // Has something
            int f = isTwo[i].first, s = isTwo[i].second;
            int l = max(a[f].first, a[s].first);
            int r = min(a[f].second, a[s].second);
            ans = max(ans, zeroTree.query(0, n - 1) + twoTree.query(l, r) + oneTree.query(a[f].first, a[f].second) + oneTree.query(a[s].first, a[s].second));
        }
    }
    cout << ans << endl;
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