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
    ll n, x, k;
    cin >> n >> x >> k;
    string s; cin >> s;
    ll tot = 0;
    ll ttnz = -1;
    for(int i = 0; i < n; i++) {
        if (k == 0) {
            break;
        }
        x += 2 * int(s[i] == 'R') - 1;
        k--;
        if (x == 0) {
            tot++;
            ll d = 0;
            ll tte = LLONG_MAX;
            for(int q = 0; q < n; q++) {
                d += 2 * int(s[q] == 'R') - 1;
                if (d == 0) {
                    tte = q + 1;
                    tot += k / tte;
                    cout << tot << endl;
                    return;
                }
            }
            break;
        }
    }
    cout << tot << endl;
    return;
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