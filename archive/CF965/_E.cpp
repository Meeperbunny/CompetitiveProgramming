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
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    vector<ll> pre(n + 1, 0);
    for(ll i = 1; i <= n; i++) {
        pre[i] = a[i - 1] + pre[i - 1];
    }
    vector<bool> isgood(n, false);
    set<ll> done;
    set<ll, greater<ll>> rdone;
    vector<pair<ll, ll>> arr(n);
    ll amax = 0;
    for(ll i = 0; i < n; i++) {
        amax = max(amax, a[i]);
        arr[i] = {a[i], i};
    }
    sort(arr.begin(), arr.end(), greater<pair<ll,ll>>());
    ll cnt = 0;
    for(ll i = 0; i < arr.size(); i++) {
        ll ind = arr[i].second;
        bool isGood = false;
        ll mv = amax;
        ll lower = 0, upper = n;
        auto it = done.upper_bound(ind);
        if (it != done.end()) {
            upper = *it;
            if (isgood[*it]) {
                mv = min(mv, a[*it]);
                isGood = true;
            }
        }
        it = rdone.upper_bound(ind);
        if (it != rdone.end()) {
            lower = *it + 1;
            if (isgood[*it]) {
                isGood = true;
                mv = min(mv, a[*it]);
            }
        }
        done.insert(ind);
        rdone.insert(ind);
        if (lower == 0 && upper == n) {
            isgood[ind] = true;
            cnt++;
        }
        else if (isGood && pre[upper] - pre[lower] >= mv) {
            isgood[ind] = true;
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    HEADER;
    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++) {
        TC();
    }
    return 0;
}