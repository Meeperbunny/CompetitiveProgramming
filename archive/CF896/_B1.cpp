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
int popcnt(ll n) {
    int t=  0;
    for(int q = 30; q >= 0; q--) {
        t += int((n >> q) & 1);
    }
    return t;
}

void TC() {
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    ll t = accumulate(all(a), 0ll);
    if (t % n) {
        cout << "NO" << endl;
        return;
    }
    ll tar = t / n;
    vector<ll> R(30, 0), G(30, 0);
    for(auto e : a) {
        ll diff = e - tar;
        if (!diff) {
            continue;
        }
        if (diff > 0) {
        }
        else {
            ll needs = tar - e;
            // IF has 1 bit, good
            for(int q = 0; q < 31; q++) {
                if (popcnt(needs + (1 << q)) == 1) {
                    R[q]++;
                    for(int j = 0; j < 30; j++) {
                        if ((needs + (1 << q)) & 1) {
                            G[j]++;
                            break;
                        }
                    }
                    break;
                }
                if (q == 30) {
                    cout << "NO3" << endl;
                    return;
                }
            }
        }
    }
    for(int i = 0; i < 30; i++) {
        if (G[i] != R[i]) {
            cout << "NO4" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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