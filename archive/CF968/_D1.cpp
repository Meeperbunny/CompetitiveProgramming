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
    vector<ll> best(n);
    ll bbest = -1;
    for(ll i = 0; i < n; i++) {
        ll sz; cin >> sz;
        for(ll q = 0; q < sz; q++) {
            ll t; cin >> t;
            seq[i].insert(t);
        }
        bool gap = false;
        for(ll q = 0; q <= sz + 2; q++) {
            if (!seq[i].count(q)) {
                if (gap) {
                    best[i] = q;
                    break;
                }
                else {
                    gap = true;
                }
            }
        }
        bbest = max(best[i], bbest);
    }
    if (bbest >= m) {
        cout << bbest * (m + 1) << endl;
    }
    else {
        cout << tri(m) + tri(bbest) << endl;
    }
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