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

class SegmentTree {
    private:
        vector<ll> tree, lazy;
        ll n;
    
        // Helper function to build the Segment Tree
        void build(const vector<ll>& a, ll v, ll tl, ll tr) {
            if (tl == tr) {
                tree[v] = a[tl];
            } else {
                ll tm = (tl + tr) / 2;
                build(a, v*2, tl, tm);
                build(a, v*2+1, tm+1, tr);
                tree[v] = max(tree[v*2], tree[v*2+1]);
            }
        }
    
        // Helper function to propagate the lazy updates
        void push(ll v) {
            if (lazy[v] != 0) {
                tree[v*2] += lazy[v];
                lazy[v*2] += lazy[v];
                tree[v*2+1] += lazy[v];
                lazy[v*2+1] += lazy[v];
                lazy[v] = 0;
            }
        }
    
        // Helper function to perform range max query
        ll query(ll v, ll tl, ll tr, ll l, ll r) {
            if (l > r)
                return INT_MIN; // Return the smallest integer when the range is invalid
            if (l <= tl && tr <= r) {
                return tree[v];
            }
            push(v);
            ll tm = (tl + tr) / 2;
            return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
        }
    
        // Helper function to perform range update
        void update(ll v, ll tl, ll tr, ll l, ll r, ll addend) {
            if (l > r)
                return;
            if (l <= tl && tr <= r) {
                tree[v] += addend;
                lazy[v] += addend;
            } else {
                push(v);
                ll tm = (tl + tr) / 2;
                update(v*2, tl, tm, l, min(r, tm), addend);
                update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
                tree[v] = max(tree[v*2], tree[v*2+1]);
            }
        }
    
    public:
        // Constructor to initialize and build the Segment Tree with zeros
        SegmentTree(ll size) {
            n = size;
            tree.resize(4 * n);
            lazy.resize(4 * n, 0);
            vector<ll> a(n, 0);
            build(a, 1, 0, n - 1);
        }
    
        // Constructor to initialize and build the Segment Tree from an array
        SegmentTree(const vector<ll>& a) {
            n = a.size();
            tree.resize(4 * n);
            lazy.resize(4 * n, 0);
            build(a, 1, 0, n - 1);
        }
    
        // Public function to perform range max query
        ll query(ll l, ll r) {
            return query(1, 0, n - 1, l, r);
        }
    
        // Public function to perform range update
        void update(ll l, ll r, ll addend) {
            update(1, 0, n - 1, l, r, addend);
        }
    };
    

void TC() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> a(n);
    vector<ll> c(n);
    for(auto &e : a) cin >> e;
    ll cc = (1ll<<31ll);
    for(ll j = 1ll << 31ll; j >= 1; j >>= 1) {
        while(true) {
            ll np = cc - j;
            if (np < 0) break;;
            for(ll i = 0; i < n; i++) {
                if (a[i] > np) {
                    c[i] = s[i] == 'B' ? 0 : 1;
                }
                else {
                    c[i] = 2;
                }
            }
            ll is = 0, ls = -1;
            for(ll i = 0; i < n; i++) {
                if (i == n - 1 && c[i] == 0) {
                    is++;
                    break;
                }
                if (ls == 0 && c[i] == 1) {
                    is++;
                }
                if (c[i] == 2) {
                    ls = ls;
                }
                else {
                    ls = c[i];
                }
            }
            if (is > k) {
                break;
            } else {
                cc = np;
            }

        }
    }
    cout << cc << endl;
}

int main() {
    HEADER;
    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++) {
        TC();
    }
    return 0;
}