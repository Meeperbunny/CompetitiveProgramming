
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

class LazySegmentTree {
private:
    vector<ll> tree;      // Segment tree array
    vector<ll> lazy;      // Lazy propagation array
    vector<bool> isSet;    // Boolean array to check if a range was set
    ll n;                // Size of the array

    void build(ll node, ll start, ll end, const vector<ll>& arr) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            ll mid = (start + end) / 2;
            build(2 * node + 1, start, mid, arr);
            build(2 * node + 2, mid + 1, end, arr);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void propagate(ll node, ll start, ll end) {
        if (isSet[node]) {
            tree[node] = (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] = lazy[node];
                lazy[2 * node + 2] = lazy[node];
                isSet[2 * node + 1] = true;
                isSet[2 * node + 2] = true;
            }
            isSet[node] = false;
        }
    }

    void rangeUpdate(ll node, ll start, ll end, ll l, ll r, ll value) {
        propagate(node, start, end);

        if (start > end || start > r || end < l) return;

        if (start >= l && end <= r) {
            tree[node] = (end - start + 1) * value;
            if (start != end) {
                lazy[2 * node + 1] = value;
                lazy[2 * node + 2] = value;
                isSet[2 * node + 1] = true;
                isSet[2 * node + 2] = true;
            }
            return;
        }

        ll mid = (start + end) / 2;
        rangeUpdate(2 * node + 1, start, mid, l, r, value);
        rangeUpdate(2 * node + 2, mid + 1, end, l, r, value);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    ll rangeQuery(ll node, ll start, ll end, ll l, ll r) {
        propagate(node, start, end);

        if (start > end || start > r || end < l) return 0;

        if (start >= l && end <= r) {
            return tree[node];
        }

        ll mid = (start + end) / 2;
        ll leftSum = rangeQuery(2 * node + 1, start, mid, l, r);
        ll rightSum = rangeQuery(2 * node + 2, mid + 1, end, l, r);
        return leftSum + rightSum;
    }

public:
    LazySegmentTree(const vector<ll>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        isSet.resize(4 * n, false);
        build(0, 0, n - 1, arr);
    }

    void updateRange(ll l, ll r, ll value) {
        rangeUpdate(0, 0, n - 1, l, r, value);
    }

    ll queryRange(ll l, ll r) {
        return rangeQuery(0, 0, n - 1, l, r);
    }

    ll queryPoll(ll idx) {
        return rangeQuery(0, 0, n - 1, idx, idx);
    }
};


void TC() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    LazySegmentTree tree(a);
    ll Q; cin >> Q;
    ll tot = 0;
    while(Q--) {
        ll ind, loc;
        cin >> ind >> loc;
        ind--;
        loc -= ind;
        // dbg(ind, loc);
        // for(ll i = 0; i < n; i++) {
        //     cout << tree.queryPoll(i) << ' ';
        // }
        // cout << endl;
        ll cpos = tree.queryPoll(ind);
        if (cpos == loc) {
            tot += 0;
        }
        else if (cpos < loc) {
            // Search for last el with val eq to end poll
            ll k = ind;
            for(ll j = n; j >= 1; j >>= 1) {
                while (k + j < n && tree.queryPoll(k + j) <= loc) {
                    k += j;
                }
            }
            tot += loc * (k - ind + 1) - tree.queryRange(ind, k);
            tree.updateRange(ind, k, loc);
            // dbg(ind, k);
        }
        else if (cpos > loc) {
            // Search for first lower el that has val of loc
            ll k = -1;
            for(ll j = n; j >= 1; j >>= 1) {
                while (k + j < ind && tree.queryPoll(k + j) < loc) {
                    k += j;
                }
            }
            k++;
            tot += tree.queryRange(k, ind) - loc * (ind - k + 1);
            tree.updateRange(k, ind, loc);
            // dbg(k, ind);
        }
        // cout << tot << endl;
    }
    cout << tot << endl;
}

int main() {
    HEADER;
    ll T = 1;
    // cin >> T;
    for (ll t = 0; t < T; t++) {
        TC();
    }
    return 0;
}