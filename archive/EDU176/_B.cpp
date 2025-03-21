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

void TC() {
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    ll ma = 0;
    if (k == 1) {
        for(int i = 0; i < n; i++) {
            ll b = a[i];
            if (i != 0) {
                ma = max(ma, b + a[0]);
            }
            if (i != n - 1) {
                ma = max(ma, b + a[n - 1]);
            }
        }
        cout << ma << endl;
        return;
    }
    ll K = k;
    multiset<ll> left, right(all(a));
    for(int i = 0; i < n; i++) {
        if (i > 0) left.insert(a[i - 1]);
        right.erase(right.find(a[i]));
        // To have a[i] as last have to have at least one from both, so should take greatest. If k is 1 is not possible.
        ll k = K;
        ll tot = a[i];
        ll TL = -1;
        ll TR = -1;
        if (left.size()) {
            tot += *left.rbegin();
            TL = *left.rbegin();
            left.erase(prev(left.end()));
            k -= 1;
        }
        if (right.size()) {
            tot += *right.rbegin();
            TR = *right.rbegin();
            right.erase(prev(right.end()));
            k -= 1;
        }
        // Get the greatest elements now
        auto lma = left.rbegin();
        auto rma = right.rbegin();
        for(int q = 0; q < k; q++) {
            if (lma != left.rend() && rma != right.rend()) {
                if (*lma > *rma) {
                    tot += *lma;
                    lma++;
                }
                else {
                    tot += *rma;
                    rma++;
                }
            }
            else if (lma != left.rend()) {
                tot += *lma;
                lma++;
            }
            else {
                tot += *rma;
                rma++;
            }
        }
        if (TL != -1) {
            left.insert(TL);
        }
        if (TR != -1) {
            right.insert(TR);
        }
        ma = max(ma, tot);
    }
    cout << ma << endl;
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