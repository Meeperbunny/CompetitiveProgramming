#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n; cin >> n;
    ll L = -1;
    ll U = LLONG_MAX;
    while(n--) {
        int q; cin >> q;
        // dbg(L, U);
        if (q == 1) {
            ll a, b, t;
            cin >> a >> b >> t;
            ll lb = (t - 2) * (a - b) + a + 1;
            ll ub = (t - 1) * (a - b) + a;
            if (t == 1) {
                lb = 1;
                ub = a;
            }
            if (lb > U || ub < L) {
                cout << 0 << ' ';
            }
            else {
                L = max(lb, L);
                U = min(ub, U);
                cout << 1 << ' ';
            }
        }
        else {
            ll a, b;
            cin >> a >> b;
            if (L == -1) {
                cout << -1 << ' ';
            }
            else {
                ll start = (L - a + ((a - b) - 1)) / (a - b);
                start = max(0ll, start);
                // dbg(start, (start * (a - b)));
                if ((start * (a - b)) + a >= U) {
                    cout << start + 1 << ' ';
                }
                else {
                    cout << -1 << ' ';
                }
            }
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