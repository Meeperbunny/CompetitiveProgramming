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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    if (accumulate(all(a), 0ll) != accumulate(all(b), 0ll)) {
        cout << "NO" << endl;
        return;
    }
    map<ll, ll> acnts, bcnts;
    for(auto e : a) acnts[e]++;
    for(auto e : b) bcnts[e]++;
    auto it = prev(bcnts.end());
    while(true) {
        // Assume it is good
        ll num = it->first;
        ll cnt = it->second;
        if (acnts[num] > cnt) {
            cout << "NO" << endl;
            return;
        }
        else if (acnts[num] < cnt) {
            ll diff = cnt - acnts[num];
            ll f = num / 2;
            ll s = num - f;
            bcnts[f] += diff;
            bcnts[s] += diff;
            it->second -= diff;
        }
        it = bcnts.lower_bound(it->first);
        if (it == bcnts.begin()) {
            break;
        }
        else {
            it = prev(it);
        }
    }
    for(auto e : bcnts) {
        acnts[e.first] -= e.second;
    }
    for(auto e : acnts) {
        if (e.second) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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