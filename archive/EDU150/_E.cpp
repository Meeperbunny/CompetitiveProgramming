#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a)
        cin >> e;
    ll k; cin >> k;
    k += n;
    ll b = 0;
    // offset, mset
    vector<vector<tuple<ll, ll, multiset<pair<ll, ll>>>>> lev(n + 1);
    // height offset mset.
    lev[n].push_back({
        n + 1, 0, {}
    });
    for(ll i = 0; i < n; i++) {
        get<2>(lev[n].back()).insert({a[i], i});
    }
    for(ll gapSize = n; gapSize >= 2; gapSize--) {
        for(auto &[height, offset, mset] : lev[gapSize]) {
            if (mset.empty()) continue;
            // For each one, get the distance we will travel
            ll dist = height - mset.rbegin()->first;
            int mss = mset.size();
            // Calc the global gain.
            ll used = gapSize * dist;
            ll gain = (gapSize - 1) * dist;
            if (k <= used) {
                ll rowCount = ll(k / gapSize);
                k -= rowCount * gapSize;
                b += rowCount * (gapSize - 1);
                if (k) {
                    b += k - 1;
                    k = 0;
                }
                cout << b - (n - 1) << endl;
                return;
            }
            k -= used;
            b += gain;
            // Split the multiset.
            ll best = mset.rbegin()->first;
            ll lind = offset;
            vector<int> torm;
            while(mset.size() && mset.rbegin()->first == best) {
                ll sind = mset.rbegin()->second;
                torm.push_back(sind);
                mset.erase(*mset.rbegin());
            }
            reverse(all(torm));
            for(auto sind : torm) {
                // Go through and erase the ind if it is in the original set.
                // Add it to the new set.
                multiset<pair<ll, ll>> newSet;
                int taking = sind - lind;
                if (taking * 2 > int(mset.size())) {
                    // reverse
                    swap(newSet, mset);
                    for(int q = sind + 1; q < offset + mss; q++) {
                        pair<int, int> p = {a[q], q};
                        auto it = newSet.find(p);
                        if (it == newSet.end()) {
                            continue;
                        }
                        newSet.erase(p);
                        mset.insert(p);
                    }
                }
                else {
                    for(int q = lind; q < sind; q++) {
                        pair<int, int> p = {a[q], q};
                        newSet.insert(p);
                        mset.erase(p);
                    }
                }
                // Now insert the new set into the vector
                lev[newSet.size()].emplace_back(best, lind, move(newSet));
                lind = sind + 1;
            }
            // Finally replace mset in.
            lev[mset.size()].emplace_back(best, lind, move(mset));
        }
        lev[gapSize].clear();
    }
    cout << b - (n - 1) << endl;
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