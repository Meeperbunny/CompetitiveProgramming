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

    vector<pair<ll, ll>> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    a.push_back({INT_MAX, 0});
    stack<pair<ll, ll>> st;
    vector<pair<ll, ll>> lasts;
    vector<ll> preLeft(1, 0);
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        dbg(string(30, '#'));
        ll nextDay = a[i + 1].first;
        ll currDay = a[i].first;
        dbg("day", currDay);
        // for(auto e : lasts) cout << e.first << ' ';
        // cout << endl;
        lasts.push_back({a[i].second, currDay});
        preLeft.push_back(preLeft[preLeft.size() - 1] + a[i].second);
        while (currDay != nextDay) {
            // binary search for rm that is good enough
            // if find a rm that is good, pop backr
            ll bind = lasts.size();
            for(ll j = lasts.size(); j >= 1; j >>= 1) {
                while(true) {
                    ll newInd = bind - j;
                    if (newInd < 0) break;
                    if (lasts[newInd].second + k <= currDay) break;
                    else {
                        bind -= j;
                    }
                }
            }

            // Once checked, ensuer day is good
            // bind is furthest that is good. CHeck if can make something
            ll t = preLeft[preLeft.size() - 1] - preLeft[bind];
            if (t >= m) {
                // Do same as above
                ll minDay = lasts[bind].second;
                ll maxDayUsing = minDay + k;
                ll daycnt = (t) / m;
                ll newMax = min({currDay + daycnt, maxDayUsing, nextDay});
                ll diff = newMax - currDay;
                if (diff == 0) break;
                ll torm = diff * m;
                ans += diff;
                dbg("Adding", diff);
                currDay += diff;
                while(torm > 0 && lasts.size()) {
                    ll taken = lasts[lasts.size() - 1].first;
                    if (torm >= taken) {
                        torm -= taken;
                        lasts.pop_back();
                        preLeft.pop_back();
                    }
                    else {
                        lasts[lasts.size() - 1].first -= torm;
                        preLeft[preLeft.size() - 1] -= torm;
                        torm = 0;
                    }
                }
            }
            else break;
        }
        // If some left, add to end
        if (currDay != nextDay) {
            lasts.clear();
            preLeft.clear();
            preLeft.push_back(0);
        }
        dbg(ans);
    }
    cout << ans << endl;
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