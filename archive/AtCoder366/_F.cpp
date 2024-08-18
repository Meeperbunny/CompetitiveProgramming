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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [&](const pair<ll, ll>& a, const pair<ll, ll>& b){
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second > b.second;
    });
    // for(auto e : a) {
    //     dbg(e.first, e.second);
    // }
    ll ans = 0;
    for(ll i = 0; i <= k; i++) {
        ll curr = 1;
        // Short term
        ll ma = 0, mind = -1;
        vector<bool> used(n, 0);
        for(ll q = 0; q < i; q++) {
            for(ll j = n - 1; j >= 0; j--) {
                if (used[j]) continue;
                if (a[j].first * curr + a[j].second > ma) {
                    ma = a[j].first * curr + a[j].second;
                    mind = j;
                    // cout << ma << ' ' << j << endl;
                }
            }
            curr = ma;
            used[mind] = 1;
        }
        // cout << "C " << curr << endl;
        // for(auto e : used) cout << e<< ' ';
        // cout << endl;
        // Long term
        vector<int> binds;
        ll l = k - i;
        ll j = 0;
        while(l) {
            if (!used[j]) {
                binds.push_back(j);
                l--;
            }
            j++;
        }
        for(j = binds.size() - 1; j >= 0; j--) {
            curr = a[binds[j]].first * curr + a[binds[j]].second;
        }

        // cout << i << ' ' << curr << endl;
        ans = max(curr, ans);
    }
    cout << ans << endl;
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