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
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
   if (n & 1) {
        cout << l << endl;
        return;
    }
    if (n == 2) {
        cout << -1 << endl;
        return;
    }

    bool bpHasOne = false;
    ll sh = 64;
    if (l == r) {
        cout << -1 << endl;
        return;
    }
    ll bd = __builtin_clzll(l);
    sh = 63 - bd;
    
    /*
    if n is odd -> all ones means it is fine.
                -> if not all ones, must have even number of one bits.
                -> 
    Find longest bit prefix
    if there is a 1 in it and n is even, then is bad.
    otherwise, do minimum an even number of times.
    if n is odd, then do the min number that flips every bit.
    if n is 1, then do min number.
    */
   // 1001, 110
   // 
    {
        ll mi = (((l >> sh) + 1) << sh);
        if (mi > r) {
            cout << -1 << endl;
            return;
        }
        if (k < n - 1) {
            cout << l << endl;
            return;
        }
        else {
            cout << mi << endl;
            return;
        }
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