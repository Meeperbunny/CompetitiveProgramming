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

ll tri(ll n) {
    return n*(n+1)/2;
}

void TC() {
    ll k;cin>>k;
    ll j = -1;
    for(ll b = 1e9+1; b >= 1; b >>= 1) {
        while(true) {
            ll res = b + j;
            ll tot = tri(res) * 2;
            if (tot < k) j = res;
            else break;
        }
    }
    ll rem = k - tri(j);
    cout << 1 + tri(j) + j + (rem) << endl; 

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