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

map<ll, ll> f;
ll fib(ll i) {
    if (i <= 1) return 1;
    if (i <= 2) return 2;
    if (!f.count(i)) {
        f[i] = fib(i - 1) + fib(i - 2);
    }
    return f[i];
}

void TC() {
    int n, m;
    cin >> n >> m;
    ll b1 = fib(n);
    ll b2 = fib(n - 1);
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        vector<ll> dims({a, b, c});
        sort(all(dims));
        if (dims[2] >= b1 + b2 && dims[1] >= b1 && dims[0] >= b1) {
            cout << '1';
        }
        else {
            cout << '0';
        }
    }
    cout << endl;
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