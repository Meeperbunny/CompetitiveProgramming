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
    ll px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    ll pointDistSquared = (px - qx) * (px - qx) + (py - qy) * (py - qy);
    // Is bad if is outside.
    // If can reach center, is good everywhere
    // Can 
    // If is 2, can't fix over / under gap. Abs value
    // If is >= 3, can fix over, not under.
    // if is 1, has to be exact match
    if (n == 1) {
        cout << (a[0] * a[0] == pointDistSquared ? "YES" : "NO") << endl;
        return;
    }
    if (n == 2) {
        ll diff = (a[0] - a[1]) * (a[0] - a[1]);
        ll maxd = (a[0] + a[1]) * (a[0] + a[1]);
        cout << ((diff <= pointDistSquared && maxd >= pointDistSquared) ? "YES" : "NO") << endl;
        return;
    }
    if (n >= 3) {
        ll totLinearDist = accumulate(all(a), 0ll);
        ll me = *max_element(all(a));
        ll tailDist = totLinearDist - me;
        if (tailDist < me) {
            ll diff = me - tailDist;
            if (diff * diff > pointDistSquared) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << ((totLinearDist * totLinearDist >= pointDistSquared) ? "YES" : "NO") << endl;
        return;
    }

}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
}