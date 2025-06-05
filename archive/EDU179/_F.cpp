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
    int p, a;
    cin >> p >> a;
    for(int t = a; t <= 50'000; t += a) {
        int ip = int(t / a) * p;
        if (ip & 1) continue;
        ip -= 4;
        int ec = ip / 2;
        int l = ec / 2;
        int u = ec - l;
        int cc = l * u;
        if (t - 1 - l - u <= cc && l + u + 1 <= t) {
            cout << t << '\n';
            cout << 0 << ' ' << 0 << '\n';
            for(int i = 1; i <= l; i++) {
                cout << i << ' ' << 0 << '\n';
            }
            for(int i = 1; i <= u; i++) {
                cout << 0 << ' ' << i << '\n';
            }
            int cx = 1, cy = 1;
            int left = t - 1 - l - u;
            while(left) {
                cout << cx << ' ' << cy << '\n';
                cx += 1;
                if (cx > l) {
                    cx = 1;
                    cy++;
                }
                left--;
            }
            return;
        }
    }
    cout << -1 << endl;

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