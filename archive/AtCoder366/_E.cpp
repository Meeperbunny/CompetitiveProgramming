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
    ll n, d;
    cin >> n >> d;
    vector<pair<ll, ll>> a(n);
    int full = 5e6;
    int half = full / 2;
    vector<ll> xcnts(int(full), 0), ycnts(int(full), 0);
    vector<ll> rxdcnts(int(full), 0), lxdcnts(int(full), 0);
    vector<ll> uydcnts(int(full), 0), dydcnts(int(full), 0);
    for(auto &e : a) {
        cin >> e.first >> e.second;
        e.first += half;
        e.second += half;
        xcnts[e.first]++;
        ycnts[e.second]++;
    }
    ll tdist = 0, cnt = 0;
    for(int i = 0; i < full; i++) {
        tdist += cnt;
        rxdcnts[i] = tdist;
        if (xcnts[i]) {
            cnt += xcnts[i];
        }
    }
    tdist = 0, cnt = 0;
    for(int i = full; i >= 0; i--) {
        tdist += cnt;
        lxdcnts[i] = tdist;
        if (xcnts[i]) {
            cnt += xcnts[i];
        }
    }

    tdist = 0, cnt = 0;
    for(int i = 0; i < full; i++) {
        tdist += cnt;
        uydcnts[i] = tdist;
        if (ycnts[i]) {
            cnt += ycnts[i];
        }
    }

    tdist = 0, cnt = 0;
    for(int i = full; i >= 0; i--) {
        tdist += cnt;
        dydcnts[i] = tdist;
        if (ycnts[i]) {
            cnt += ycnts[i];
        }
    }

    // for(int i = 2e6 - 10; i < 2e6 + 10; i++) {
    //     cout  << i << " YC " << ycnts[i] << ' ' << uydcnts[i] << ' ' << dydcnts[i] << endl;
    // }

    ll minYInd = -1, miV = LLONG_MAX;
    for(int i = 0; i < full; i++) {
        xcnts[i] = rxdcnts[i] + lxdcnts[i];
        ycnts[i] = uydcnts[i] + dydcnts[i];
        if (ycnts[i] < miV) {
            miV = ycnts[i];
            minYInd = i;
        }
    }
    
    ll tot = 0;
    for(int i = 0; i < full; i++) {
        ll base = xcnts[i];
        // Calc the number of points such that total sum is less than d + 1.
        // If curr x val + minYInd is greater than D, then none are good.
        if (base + ycnts[minYInd] > d) {
            continue;
        }
        // cout << i << " IS DOING " << endl;
        // Calc up
        ll upVal = minYInd;
        for(int j = half; j >= 1; j >>= 1) {
            while(upVal + j < full && ycnts[upVal + j] + base <= d) {
                upVal += j;
            }
        }
        // Calc down
        ll downVal = minYInd;
        for(int j = half; j >= 1; j >>= 1) {
            while(downVal - j >= 0 && ycnts[downVal - j] + base <= d) {
                downVal -= j;
            }
        }
        // Otherwise, sub 1 for double counting min point.
        tot += upVal - downVal + 1;
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