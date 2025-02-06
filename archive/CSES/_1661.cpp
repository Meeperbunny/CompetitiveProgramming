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
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> pre(n + 1, 0);
    map<ll, ll> cnts;
    cnts[0]++;
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
        cnts[pre[i]]++;
    }
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        cnts[pre[i]]--;
        ll lk = x + pre[i];
        tot += cnts[lk];
    }
    cout << tot << endl;
}

int main() {
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}