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
    ll n, m; cin >> n >> m;
    map<ll, ll> cnts;
    for(int i = 0; i < n; i++) {
        ll z; cin >> z;
        cnts[z]++;
    }
    ll mas = 0;
    for(auto e : cnts) {
        ll curr = e.first;
        ll cnt = e.second;
        if (cnts.count(curr - 1)) {
            ll cnt2 = cnts[curr - 1];
            for(int i = 0; i <= cnt2; i++) {
                ll bs = i * (curr - 1);
                if (bs > m) continue;
                else {
                    ll nc = m - bs;
                    // dbg(e.first, min(curr * cnt, (nc / curr) * curr));
                    ll av = min(curr * cnt, (nc / curr) * curr) + bs;
                    // dbg(e.first, av);
                    mas = max(mas, av);
                }
            }
        }
        else {
            // dbg(e.first, min(curr * cnt, (m / curr) * curr));
            mas = max(mas, min(curr * cnt, (m / curr) * curr));
        }
    }
    cout << mas << endl;
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