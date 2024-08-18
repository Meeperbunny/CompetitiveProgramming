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
    vector<ll> a(n);
    ll tot = 0;
    for(auto &e : a) {
        cin >> e;
        tot -= e;
    }
    for(ll q = 0; q < 30; q++) {
        ll cnts[2] = {1, 0};
        ll c = 0;
        for(ll i = 0; i < n; i++) {
            c ^= (a[i] >> q) & 1;
            if (c) {
                tot += cnts[0] << q;
                cnts[1]++;
            }
            else {
                tot += cnts[1] << q;
                cnts[0]++;
            }
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