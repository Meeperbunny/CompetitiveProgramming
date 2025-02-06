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

int o[200001];
int ops(int k) {
    if (k == 0) return 0;
    else if (!o[k]) o[k] = ops(int(k / 3)) + 1;
    return o[k];
}

int rc[200001];

void TC() {
    ll l, r;
    memset(o, 0, sizeof(o));
    cin >> l >> r;
    ll totops = 0;
    totops += rc[r] - rc[l];
    // for(ll i = l + 1; i <= r; i++) {
    //     totops += ops(i);
    // }
    cout << ops(l) + ops(l) + totops << endl;
}

int main() {
    HEADER;
    rc[0] = 0;
    for(int i = 1; i <= 200000; i++) {
        rc[i] = rc[i - 1] + ops(i);
    }

    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}