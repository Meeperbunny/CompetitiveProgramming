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

void TC() {
    ll n; cin >> n;
    // Find cost per each
    // Find min cost for el greater than
    // Iter on a
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    map<ll, ll> cost, mcost;
    for(int i = 0; i < n; i++) {
        cost[b[i]] = i;
    }
    for(int i = 2 * n; i >= 2; i -= 2) {
        if (i != 2 * n) {
            mcost[i] = mcost[i + 2];
            mcost[i] = min(mcost[i], cost[i]);
        }
        else {
            mcost[i] = cost[i];
        }
    }
    ll mi = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        ll t = i + mcost[a[i] + 1];
        mi = min(mi, t);
    }
    cout << mi << endl;
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