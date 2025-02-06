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
    ll n, m;
    cin >> n >> m;
    vector<ll> b(m);
    for(auto &e : b) cin >> e;
    map<ll, ll> cnts;
    for(auto e : b) cnts[e]++;
    ll ops = 0;
    for(ll q = 0; q < 62; q++) {
        if ((n >> q) & 1) {
            ll tofill = 1ll << q;
            // dbg(tofill);
            // Check all smaller to see if can make sum
            bool usedsmaller = false, usedlarger = false;
            ll csum = 0;
            map<ll, ll> hu;
            for(ll k = tofill; k > 0; k >>= 1) {
                // cout << k << ' ' << cnts[k] << endl;
                ll diff = tofill - csum;
                ll needed = diff / k;
                ll used = min(needed, cnts[k]);
                hu[k] = used;
                csum += used * k;
            }
            if (csum == tofill) {
                usedsmaller = true;
                for(auto e : hu) {
                    cnts[e.first] -= e.second;
                }
            }
            // Otherwise check if any larger
            if (!usedsmaller) {
                for(ll k = tofill << 1, d = 1; k < 2e9; k <<= 1, d++) {
                    if (cnts[k] > 0) {
                        ops += d;
                        cnts[k]--;
                        for(ll q = k >> 1; q >= tofill; q >>= 1) {
                            cnts[q]++;
                        }
                        usedlarger = true;
                        break;
                    }
                }
            }
            // Else return -1
            // dbg(usedlarger, usedsmaller);
            if (!usedlarger && !usedsmaller) {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << ops << endl;
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