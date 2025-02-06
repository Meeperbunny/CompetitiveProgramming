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


    vector<ll> ltodiff;

void TC() {
    ll l, r;
    cin >> l >> r;
    ll d = (r - l);
    ll k = -1;
    for(ll n = ltodiff.size(); n >= 1; n >>= 1) {
        while(k + n < ltodiff.size() && ltodiff[k + n] <= d) {
            k += n;
        }
    }
    cout << k + 1 << endl;
}

int main() {
    HEADER;
    ll td = 0;
    ltodiff.push_back(td);
    for(ll i = 1;; i++) {
        td += i;
        ltodiff.push_back(td);
        if (td > 1e9) break;
    }
    dbg(ltodiff.size());
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}