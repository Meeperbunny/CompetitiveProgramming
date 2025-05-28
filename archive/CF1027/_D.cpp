#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n; cin >> n;
    vector<pair<int, int>> coords(n);
    multiset<int> x, y;
    for(auto &e : coords) {
        cin >> e.first >> e.second;
        x.insert(e.first);
        y.insert(e.second);
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    ll best = LLONG_MAX;
    for(auto &e : coords) {
        auto [xx, yy] = e;
        x.erase(x.find(xx));
        y.erase(y.find(yy));

        ll lx = *x.begin();
        ll ux = *x.rbegin();
        ll ly = *y.begin();
        ll uy = *y.rbegin();
        ll area = (ux - lx + 1ll) * (uy - ly + 1ll);
        // cout << e.first << ' ' << e.second << ' ' << area << endl;
        if (area == ll(n - 1)) {
            best = min(best, 
                min(
                    (ux - lx + 2ll) * (uy - ly + 1ll),
                    (ux - lx + 1ll) * (uy - ly + 2ll)
                )
            );
        }
        else {
            best = min(area, best);
        }
        
        x.insert(xx);
        y.insert(yy);
    }
    cout << best << endl;
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