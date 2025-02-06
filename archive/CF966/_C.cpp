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

ll dist(pair<ll, ll> &a, pair<ll, ll> &b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void TC() {
    int n; cin >> n;
    vector<pair<ll, ll>> c(n);
    for(auto &e : c) {
        cin >> e.first >> e.second;
    }
    pair<ll, ll> p1, p2;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    ll myd = dist(p1, p2);
    for(auto e : c) {
        if (dist(e, p2) <= myd) {
            cout<< "NO" << endl;
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