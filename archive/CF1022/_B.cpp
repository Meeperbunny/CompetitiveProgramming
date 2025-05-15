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
    int n, x;
    cin >> n >> x;
    if (n == 1) {
        if (x == 0) {
            cout << -1 << endl;
            return;
        }
        else {
            cout << x << endl;
            return;
        }
    }
    if (x == 1) {
        // TODO
        if (n & 1) {
            cout << n << endl;
        }
        else {
            cout << 4 + n - 1 << endl;
        }
        return;
    }
    else if (x == 0) {
        if (n & 1) {
            if (n == 3) {
                cout << 6 << endl;
            }
            else {
                cout << 4 + n - 1 << endl;
            }
            return;
        }
        else {
            // Even is just 1s
            cout << n << endl;
        }
        return;
    }
    else {
        int used = __builtin_popcount(x);
        int left = n - used;
        if (left <= 0) {
            cout << x << endl;
            return;
        }
        if (x & 1) {
            // Even
            if (left & 1) {
                cout << x + left + 1 << endl;
            }
            else {
                cout << x + left << endl;
            }
        }
        else {
            // Even
            if (left & 1) {
                cout << x + left + 1 << endl;
            }
            else {
                cout << x + left << endl;
            }
        }
        return;
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