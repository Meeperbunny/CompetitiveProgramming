#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    ll n, x;
    cin >> n >> x;
    ll tot = 0;
    for(ll a = 1; a <= x; a++) {
        for(ll b = a; b <= x; b++) {
            if (a * b + a + b > n || a + b + 1 > x) break;
            int minc = 1;
            int maxc = 1;
            for(int cc = n; cc >= 1; cc >>= 1) {
                while(true) {
                    ll newc = maxc + cc;
                    bool isgood = false;

                    if (a * b + b * newc + a * newc <= n && a + b + newc <= x) {
                        isgood = true;
                    }

                    if (isgood) {
                        maxc = newc;
                    } else break;
                }
            }
            // dbg(a, b, minc, maxc);
            if (b != a) 
                tot += maxc - minc + 1;
            tot += maxc - minc + 1;

        }
    }
    cout << tot << endl;
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