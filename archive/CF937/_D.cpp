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
    vector<ll> bds;
    bds.push_back(1);
    bds.push_back(0);
    for(ll i = 0; i < 6; i++) {
        ll sz = bds.size();
        for(ll q = 0; q < sz; q++) {
            bds.push_back(bds[q] * 10 + 1);
            bds.push_back(bds[q] * 10 + 0);
        }
    }
    set<ll> inset(all(bds));
    for(int i = 0; i < 5; i++) {
        set<ll> cp(inset);
        for(auto e : bds) {
            for(auto q : inset) {
                if (e * q < 100000ll)
                    cp.insert(e * q);
            }
        }
        swap(inset, cp);
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if (inset.count(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
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