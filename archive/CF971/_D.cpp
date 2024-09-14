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
    ll n; cin >> n;
    set<pair<int, int>> pnts;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pnts.insert({a, b});
    }
    ll tot= 0;
    for(auto &p : pnts) {
        int yc = p.second;
        int c = !yc;
        if (pnts.count({p.first, c})) {
            // do all other poiunts
            tot += n - 2;
        }
        // Check for on comp of other side
        if (pnts.count({p.first - 1, c}) && pnts.count({p.first + 1, c})) {
            tot += 2;
        }
    }
    cout << tot / 2 << endl;
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