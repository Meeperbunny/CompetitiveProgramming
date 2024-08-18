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

class FenwickTree {
private:
    std::vector<int> bit;  // Binary Indexed Tree (Fenwick Tree)
    int n;

public:
    // Constructor to initialize the tree with size 'n'
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // Function to update the tree by adding 'value' at index 'idx'
    void update(int idx, int value) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += value;
    }

    // Function to get the sum from index 1 to 'idx'
    int sum(int idx) {
        int result = 0;
        for (; idx > 0; idx -= idx & -idx)
            result += bit[idx];
        return result;
    }

    // Function to get the sum from index 'l' to 'r'
    int range_sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void TC() {
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    ll tot = 0;
    FenwickTree tree(300003);
    for(int i = 0; i < n; i++) {
        ll c = a[i];
        if (c == 1) {
            tot++;
            set<int> inset;
            tree.update(1, 1);
            inset.insert(1);
            // Go left
            for(int q = i - 1; q >= 0; q--) {
                // Add current into set
                ll cur = a[q];
                if (inset.count(cur)) break;
                else {
                    inset.insert(cur);
                    tree.update(cur, 1);
                }
                int mael = *inset.rbegin();
                if (tree.range_sum(1, mael) == mael) {
                    dbg(i, q);
                    tot++;
                }
            }
            for(auto e : inset) tree.update(e, -1);
            inset.clear();

            tree.update(1, 1);
            inset.insert(1);
            for(int q = i + 1; q < n; q++) {
                // Add current into set
                ll cur = a[q];
                if (inset.count(cur)) break;
                else {
                    inset.insert(cur);
                    tree.update(cur, 1);
                }
                int mael = *inset.rbegin();
                if (tree.range_sum(1, mael) == mael) {
                    dbg(i, q);
                    tot++;
                }
            }
            for(auto e : inset) tree.update(e, -1);
            inset.clear();
        }
    }
    cout << tot << endl;
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