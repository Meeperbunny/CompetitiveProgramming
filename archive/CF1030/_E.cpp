#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
// using ll = long long;
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

void p(int n, int m) {
    cout << n << ' ' << m << '\n';
}

void TC() {
    int n, m;
    cin >> n >> m;
    int cn = (n + 1) / 2;
    int cm = (m + 1) / 2;
    int U = cn;
    int D = cn;
    int L = cm;
    int R = cm;
    p(cn, cm);
    while(D - U + 1 < n || R - L + 1 < m) {
        // Try going up
        if (D - U + 1 < n) {
            // From L to R inc, zigzag out?
            D++, U--;
            int ll = cm, rr = cm;
            while(ll >= L) {
                if (ll == rr) {
                    // Just do top bot.
                    p(U, ll);
                    p(D, ll);
                }
                else {
                    // Do corners.
                    p(U, ll);
                    p(D, rr);
                    p(D, ll);
                    p(U, rr);
                }
                ll--, rr++;
            }
        }
        // Try going side.
        if (R - L + 1 < m) {
            // From L to R inc, zigzag out?
            R++, L--;
            int uu = cn, dd = cn;
            while(uu >= U) {
                if (uu == dd) {
                    // Just do top bot.
                    p(uu, L);
                    p(uu, R);
                }
                else {
                    // Do corners.
                    p(uu, L);
                    p(dd, R);
                    p(uu, R);
                    p(dd, L);
                }
                uu--, dd++;
            }
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
    return 0;
}