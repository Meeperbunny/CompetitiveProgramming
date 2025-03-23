#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n, k;
    cin >> n >> k;
    vector<set<int>> kpos(k);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        kpos[a[i]].insert(i);
    }
    ll best = LLONG_MAX;
    for(int i = 0; i + k <= n; i++) {
        cout << "Checking Pos i: " << i << " ###########" << endl;
        vector<bool> filled(k, 0);
        for(int q = 0; q < k; q++) {
            filled[a[i + q]] = 1;
        }
        ll tc = 0;
        set<pair<int, pair<int, int>>> rdiff;
        ll TRC = 0;
        ll TLC = 0;
        int trc = 0;
        int tlc = 0;
        int tsc = 0;
        int sac = 0;
        for(int q = 0; q < k; q++) {
            // Get cost to move something on right side vs left side.
            // right side -> i, left side -> i - 1
            if (!filled[q]) {
                int rc = -1;
                int lc = -1;
                auto rit = kpos[q].lower_bound(i);
                if (rit != kpos[q].end()) {
                    rc = *rit - (i + k);
                }
                if (rit != kpos[q].begin()) {
                    lc = (i - 1) - *prev(rit);
                }
                if (rc != -1 && lc != -1) {
                    tsc++;
                    rdiff.insert({lc - rc, {lc, rc}});
                    trc++;
                    TRC += rc;
                }
                else if (lc != -1) {
                    tlc++;
                    TLC += lc;
                }
                else if (rc != -1) {
                    trc++;
                    TRC += rc;
                }
            }
            else sac++;
        }
        int bs = rdiff.size();
        int blc = tlc;
        for(ll bp = tlc; bp <= blc + bs; bp++) {
            ll leftCost = TLC + tlc * bp;
            ll rightCost = TRC + trc * (k - bp);
            // Get current total
            best = min(best, leftCost + rightCost);
            dbg(bp, tlc, trc, TLC, TRC);
            if (bp == blc + bs) break;
            // Swap at end if not last
            auto p = *rdiff.begin();
            rdiff.erase(rdiff.begin());
            tlc += 1;
            trc -= 1;
            TLC += p.second.first;
            TRC -= p.second.second;
        }
        // See which ones are not filled
        // Assign all to right of line
        // Get the cost for swapping [diff]
        // Move bar right then choose a min diff to swap
        // End when bar is all at right
        cout << i << ' ' << best << endl;
    }
    cout << best << endl;
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