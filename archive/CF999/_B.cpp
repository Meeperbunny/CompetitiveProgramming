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
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    sort(all(a));
    map<ll, ll> cnts;
    vector<ll> twos;
    for(auto e : a) {
        cnts[e]++;
        if (cnts[e] == 2) {
            twos.push_back(e);
        }
        if (cnts[e] == 4) {
            cout << e << ' ';
            cout << e << ' ';
            cout << e << ' ';
            cout << e << endl;
            return;
        }
    }
    if (twos.size() >= 2) {
        cout << twos[0] << ' ';
        cout << twos[0] << ' ';
        cout << twos[1] << ' ';
        cout << twos[1] << endl;
        return;
    }
    if (twos.size() == 0) {
        cout << -1 << endl;
        return;
    }
    ll theone = twos[0];
    cnts[theone] -= 2;
    if (cnts[theone] == 0) {
        cnts.erase(theone);
    }
    for(auto it = cnts.begin(); next(it) != cnts.end(); it++) {
        ll i = it->first, j = next(it)->first;
        if (i + theone * 2 > j) {
            cout << theone << ' ' << theone << ' ' << i << ' ' << j << endl;
            return;
        }
    }
    cout << -1 << endl;
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