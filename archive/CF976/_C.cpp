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
    ll b, c, d;
    cin >> b >> c >> d;
    ll a = 0;
    ll ta = (1ll << 61);
    if ((ta|b)-(ta&c)==d) {
        cout << ta << endl;
        return;
    }
    for(int i = 0; i < 61; i++) {
        bool bb = (b>>i)&1;
        bool cb = (c>>i)&1;
        bool db = (d>>i)&1;
        if (cb != bb) {
            continue;
        }
        else {
            a |= (ll(bb ^ db) << i);
        }
    }
    // cout << a << endl;
    if ((a|b)-(a&c)==d) {
        cout << a << endl;
    }
    else {
        cout << -1 << endl;
    }
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