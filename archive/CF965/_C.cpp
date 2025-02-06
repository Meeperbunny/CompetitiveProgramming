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
    // Biggest el that I can change OR biggest el that I cant, then try to change all
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), c(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++) {
        cin >> c[i];
    }
    ll vbic = 0;
    ll vbicc = 0;
    ll bICC = -1;
    for(ll i = 0; i < n; i++) {
        if (c[i]) {
        }
        else {
            if (a[i] > vbicc) {
                vbicc = a[i];
                bICC = i;
            }

        }
    }
    // Try changing a[i] to max and find median
    ll ma = -1;
    for (int bIC = 0; bIC < n; bIC++) {
        if (!c[bIC]) continue;
        vector<ll> cp;
        for(ll i = 0; i < n; i++) {
            if (i == bIC) continue;
            cp.push_back(a[i]);
        }
        sort(cp.begin(), cp.end());
        ma = max(k + a[bIC] + cp[ll((cp.size() - 1) / 2)], ma);
    }
    if (bICC != -1) {
        // Use one I can't change
        vector<ll> cp;
        for(ll i  = 0; i < n; i++) {
            if (i == bICC) continue;
            cp.push_back(a[i]);
        }
        sort(cp.begin(), cp.end());
        ll mav = -1;
        for(ll j = 1000000001; j >= 1; j >>= 1) {
            while(true) {
                ll atV = j + mav;
                bool w = true;
                ll cost = 0;
                for(ll i = 0; i <= ll((cp.size() - 1) / 2); i++) {
                    if (cp[i] < atV) {
                        cost += atV - cp[i];
                    }
                    if (cost > k) {
                        w = false;
                        break;
                    }
                }
                if (!w) break;
                mav += j;
            }
        }
        // dbg(ma);
        ma = max(mav + a[bICC], ma);
    }
    cout << ma << endl;
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