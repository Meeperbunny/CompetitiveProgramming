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
    // 1 4 10 + 1 * 2
    ll n, k; cin >> n >> k;
    if (n >= 42) {
        // is good
    }
    else {
        // check
        // n = 3, max is 4
        if (k > (1ll << (n - 1))) {
            cout << -1 << endl;
            return;
        }
    }
    // Now get it.
    // 1 2 3 5 4
    k -= 1;
    // 1
    deque<ll> Q;
    Q.push_back(n);
    for(ll i = n - 1; i >= 1; i--) {
        if (k & 1) {
            Q.push_back(i);
        }
        else {
            Q.push_front(i);
        }
        k >>= 1;
    }
    while(Q.size()) {
        cout << Q.front() << ' ';
        Q.pop_front();
    } cout << endl;
}

int main() {
    HEADER;
    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++) {
        TC();
    }
    return 0;
}