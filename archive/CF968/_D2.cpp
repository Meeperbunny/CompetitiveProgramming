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
    return n * (n + 1) / 2;
}

void TC() {
    ll n, m;
    cin >> n >> m;
    vector<set<ll>> seq(n);

    vector<pair<ll, ll>> arr(n);
    for(ll i = 0; i < n; i++) {
        ll sz; cin >> sz;
        for(ll q = 0; q < sz; q++) {
            ll t; cin >> t;
            seq[i].insert(t);
        }
        bool gap = false;
        int fr = -1;
        for(ll q = 0; q <= sz + 10; q++) {
            if (!seq[i].count(q)) {
                if (gap) {
                    arr[i] = {fr, q};
                    break;
                }
                else {
                    fr = q;
                    gap = true;
                }
            }
        }
    }
    sort(arr.begin(), arr.end());
    ll maxup = 0;
    for(int i = arr.size() - 1; i >= 0; i--) {
        maxup = max(arr[i].second, maxup);
    }
    vector<ll> cnt(maxup + 1);
    ll tc = maxup + 2;
    vector<ll> maxel(tc + 1, 0);

    for(int i = arr.size() - 1; i >= 0; i--) {
        cnt[arr[i].first]++;
    }
    vector<ll> maxes(n, -1);
    vector<vector<ll>> ends(maxup + 1);
    for(int i = 0; i < n; i++) {
        maxel[arr[i].first] = arr[i].second;
    }

    ll bestval = 0;
    for(int i = n - 1; i >= 0; i--) {
        ll f = arr[i].first;
        ll s = arr[i].second;
        // If my f is anothers second, then set that seccond's max to my max
        maxel[arr[i].first] = max(maxel[arr[i].first], maxel[arr[i].second]);
        bestval = max(bestval, arr[i].first);
        if (cnt[arr[i].first] >= 2) {
            bestval = max(bestval, arr[i].second);
        }
    }
    // Can set all others to my max if I have 2. If i dont, can only set a point.
    for(ll i = 0; i <= tc; i++) {
        maxel[i] = max({bestval, maxel[i], i});
    }
    ll tot = 0;
    for(ll i = 0; i <= min(m, tc); i++) {
        tot += maxel[i];
    }
    if (m > tc) {
        tot += tri(m) - tri(tc);
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