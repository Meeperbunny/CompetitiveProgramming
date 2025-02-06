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

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    else return gcd(b, a % b);
}

int popcnt(ll n) {
    int cnt = 0;
    for(int i = 60; i >= 0; i--) cnt += ((n >> i) & 1);
    return cnt;
}

void TC() {
    ll a, b;
    cin >> a >> b;
    int res = b / gcd(a, b);
    if (popcnt(res) == 1) {
        // Is good
        vector<int> cnts(40, 0);
        cnts[0] += a;
        int ops = 0;
        for(int i = res, q = 0; i >= 1; i /= 2, q++) {
            int c = int(a / i) * b;
            a -= int(a / i) * i;
            for(int q = 39; q >= 0; q--) {
                if (cnts[q])
            }
        }
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