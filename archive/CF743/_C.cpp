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
    ll n; cin >> n;
    vector<vector<ll>> adj(n);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    vector<ll> cnt(n, 0);
    vector<bool> seen(n, false);
    for(int i = 0; i < n; i++) {
        int j; cin >> j;
        cnt[i] = j;
        if (j == 0) {
            Q.push({1, i});
            seen[i] = true;
        }
        for(int q = 0; q < j; q++) {
            int c; cin >> c;
            adj[c - 1].push_back(i);
        }
    }
    // ll ans; cin >> ans;
    ll ma = -1;
    while(Q.size()) {
        pair<ll, ll> curr = Q.top();
        Q.pop();
        ll ind = curr.second, d = curr.first;
        // cout << ind + 1 << ' ' << d << endl;
        ma = max(ma, d);
        for(auto e : adj[ind]) {
            if (seen[e]) continue;
            else {
                cnt[e]--;
                if (cnt[e] == 0) {  
                    seen[e] = true;
                    pair<ll, ll> par = {d, e};
                    if (e < ind) par.first++;
                    Q.push(par);
                }
            }
        }
    }
    ll checked = 0;
    for(int i = 0; i < n; i++) if (seen[i]) checked++;
    ll an;
    if (checked == n) {
        an = ma;
    }
    else {
        an = -1;
    }
    cout << an << endl;
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