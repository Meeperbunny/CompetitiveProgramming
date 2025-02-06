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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    if (accumulate(a.begin(), a.end(), 0ll) <= m) {
        cout << "infinite" << endl;
        return;
    }
    ll k = -1;
    for(ll j = m; j >= 1; j /= 2) {
        while(true) {
            ll s = 0;
            for(auto e : a) s += min(e, k + j);
            if (s <= m) {
                k += j;
            }
            else break;
        }
    }
    cout << k << endl;
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