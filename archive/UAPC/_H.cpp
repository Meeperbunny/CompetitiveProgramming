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
    ll N, L, W;
    cin >> N >> L >> W;
    vector<pair<ll, ll>> P(N);
    for(auto &e : P) {
        cin >> e.first >> e.second;
    }
    set<pair<ll, ll>> nails;
    for(auto e : P) {
        ll X = ll(e.first / L) * L;
        ll Y = ll(e.second / W) * W;
        ll XX, YY;
        if (e.first <= X + 1 && X + 1 <= e.first + L) {
            XX = X + 1;
        } else XX = X + L + 1;
        if (e.second <= Y + 1 && Y + 1 <= e.second + W) {
            YY = Y + 1;
        } else YY = Y + W + 1;
        nails.insert({XX, YY});
    }
    cout << nails.size() << endl;
    for(auto e : nails) {
        if (e.first < 2 || e.first > 444444444 || e.second < 2 || e.second > 444444444) continue;
        cout << e.first << ' ' << e.second << '\n';
    }
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