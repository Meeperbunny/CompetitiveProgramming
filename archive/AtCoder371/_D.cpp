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

void TC() {
    int n; cin >> n;
    vector<ll> X(n), P(n);
    for(int i = 0; i < n; i++) cin >> X[i];
    for(int i = 0; i < n; i++) cin >> P[i];
    map<ll, ll> ctp;
    ctp[X[0]] = P[0];
    for(int i = 1; i < n; i++) {
        ctp[X[i]] = ctp[X[i - 1]] + P[i];
    }
    int Q; cin >> Q;
    while(Q--) {
        ll l, r;
        cin >> l >> r;
        // dbg(l,r);
        auto lit = ctp.lower_bound(l);
        auto uit = ctp.upper_bound(r);
        // cout << distance(ctp.begin(), lit) << '\n';
        // cout << distance(ctp.begin(), uit) << '\n';
        if (lit == ctp.end() || uit == ctp.begin()) {
            cout << 0 << '\n';
            continue;
        }
        uit = prev(uit);
        ll tot = uit->second;
        if (lit != ctp.begin()) {
            // dbg("Subbing");
            lit = prev(lit);
            tot -= lit->second;
        }
        cout << tot << '\n';
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