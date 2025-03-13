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
    ll x; cin >> x;
    vector<ll> ones, zeros;
    for(int i = 31 - __builtin_clz(x); i >= 0; i--) {
        if ((x >> i) & 1) {
            ones.push_back(i);
        }
        else {
            zeros.push_back(i);
        }
    }
    if (ones.size() >= 2 && zeros.size() >= 1) {
        cout << ((1 << ones.back()) | (1 << zeros.back())) << endl;
    }
    else {
        cout << -1 << endl;
    }
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