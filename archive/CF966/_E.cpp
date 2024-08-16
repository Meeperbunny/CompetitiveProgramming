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
    ll n, m, k;
    cin >> n >> m >> k;
    ll w; cin >> w;
    vector<ll> h(w);
    for(auto &e : h) cin >> e;
    sort(all(h));
    priority_queue<ll> maxinc;
    for(ll i = 0; i < n; i++) {
        for(ll q = 0; q < m; q++) {
            ll times = 0;
            ll fr = min(q + (k - 1), m - 1);
            ll fl = max(q - (k - 1), 0ll);
            ll fd = min(i + (k - 1), n - 1);
            ll fu = max(i - (k - 1), 0ll);
            ll lfree = fr - fl - k + 2;
            ll ufree = fd - fu - k + 2;
            maxinc.push(lfree * ufree);
        }
    }
    ll tot = 0;
    for(int i = w - 1; i >= 0; i--) {
        // dbg(maxinc.top());
        tot += h[i] * maxinc.top();
        maxinc.pop();
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