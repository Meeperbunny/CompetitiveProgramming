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

#include <vector>

struct FenwickTreeOneBasedIndexing {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<int> a)
        : FenwickTreeOneBasedIndexing(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};


FenwickTreeOneBasedIndexing tree(1e5+1);

void TC() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) {
        cin >> e;
        tree.add(e, 1);
    }
    int gel = a.back();
    ll t = 0;
    for(int i = n - 1; i >= 0; i--) {
        // Remove a[i] from fenwick. get the target. then iterate through lower els and get the sums.
        tree.add(a[i], -1);
        for(int q = i - 1; q >= 1; q--) {
            tree.add(a[q], -1);
            
            // X + a[q] + a[i] > gel
            // X + a[q] > a[i]

            // X > gel - (a[q] + a[i])
            // X > a[i] - a[q]
            int lb = max(a[i] - a[q], gel - (a[q] + a[i])) + 1;

            // cout << i << ' ' << q << ' ' << a[i] << ' ' << a[q] << ' ' << lb << endl;

            if (lb <= a[q - 1]) {
                // cout << '\t' << "adding " << ll(tree.sum(lb, a[q - 1])) << endl;
                t += ll(tree.sum(lb, a[q - 1]));
            }
        }
        
        for(int q = i - 1; q >= 1; q--) {
            tree.add(a[q], 1);
        }
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