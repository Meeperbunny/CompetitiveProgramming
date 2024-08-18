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
    ll n, k, w, h;
    cin >> n >> k >> w >> h;
    string s; cin >> s;
    ll x = 0, y = 0;
    ll dx, dy;
    map<pair<ll, ll>, ll> cnts;
    for(auto e : s) {
        if (e == 'U') y += 1;
        if (e == 'D') y -= 1;
        if (e == 'L') x -= 1;
        if (e == 'R') x += 1;
        y = (y + 2 * h) % (2 * h);
        x = (x + 2 * w) % (2 * w);
        cnts[{x, y}]++;
    }
    dx = x, dy = y;
    x = 0, y = 0;
    ll tot = 0;
    // for(auto e : cnts) {
    //     dbg(e.first.first, e.first.second, e.second);
    // }
    for(ll i = 0; i < k; i++) {
        tot += cnts[{(2 * w - x) % (2 * w), (2 * h - y) % (2 * h)}];
        x += dx, y += dy;
        x %= 2 * w;
        y %= 2 * h;
    }
    cout << tot << endl;


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