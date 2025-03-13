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
    ll evenmask{}, oddmask{};
    for(int i = 0; i < 30; i += 2) {
        evenmask |= (1ll << i);
    }
    for(int i = 1; i < 30; i += 2) {
        oddmask |= (1ll << i);
    }
    vector<ll> bc(30);
    ll eres, ores;
    cout << oddmask << endl;
    cin >> eres;
    eres -= 2 * oddmask;
    cout << evenmask << endl;
    cin >> ores;
    ores -= 2 * evenmask;
    for(int i = 0; i < 30; i += 2) {
        if ((eres >> i) & 1) {
            bc[i] = 1;
        }
        else if ((eres >> (i + 1)) & 1) {
            bc[i] = 2;
        }
        else {
            bc[i] = 0;
        }
    }
    for(int i = 1; i < 30; i += 2) {
        if ((ores >> i) & 1) {
            bc[i] = 1;
        }
        else if ((ores >> (i + 1)) & 1) {
            bc[i] = 2;
        }
        else {
            bc[i] = 0;
        }
    }
    cout << "!" << endl;
    ll m; cin >> m;
    ll ans = 0;
    for(int i = 0; i < 30; i++) {
        if ((m >> i) & 1) {
            ans += 2ll * (1ll << i);
        }
        else {
            ans += bc[i] * (1ll << i);
        }
    }
    cout << ans << endl;
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