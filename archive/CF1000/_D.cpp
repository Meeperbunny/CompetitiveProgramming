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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    sort(all(a));
    sort(all(b));
    vector<ll> GA(n / 2);
    vector<ll> GB(m / 2);
    for(int i = 0; i < n / 2; i++) {
        GA[i] = a[n - i - 1] - a[i];
        if (i) {
            GA[i] += GA[i - 1];
        }
    }
    for(int i = 0; i < m / 2; i++) {
        GB[i] = b[m - i - 1] - b[i];
        if (i) {
            GB[i] += GB[i - 1];
        }
    }

    int maxk = 0;
    int A = 0, B = 0;
    // Go back 2 on each after each iter
    // find kmax
    for(int av = 0; 2 * av <= n; av++) {
        int bv = min(n - 2 * av, (m - av) / 2);
        if (bv < 0) continue;
        if (av * 2 + bv <= n && bv * 2 + av <= m) {
            maxk = max(av + bv, maxk);
        }
    }
    cout << maxk << '\n';
    int used = 0;
    ll tot = 0;
    int aused = 0;
    int bused = 0;
    for(int k = 1; k <= maxk; ++k) {
        int ct = aused + bused;
        int toadd = k - ct;
        // Get potentials
        vector<pair<ll, pair<int, int>>> potentials;
        for(int aAdd = 0; aAdd <= toadd; ++aAdd) {
            int bAdd = toadd - aAdd;
            int newa = aused + aAdd;
            int newb = bused + bAdd;
            if (newa * 2 + newb <= n && newb * 2 + newa <= m) {
                // cout << '\t' << newa << ' ' << newb << endl;
                ll ta = 0;
                if (newa) ta += GA[newa - 1];
                if (newb) ta += GB[newb - 1];
                potentials.push_back({ta, {aused + aAdd, bused + bAdd}});
            }
        }
        ll best = 0;
        for(auto e : potentials) {
            if (e.first > best) {
                best = e.first;
                aused = e.second.first;
                bused = e.second.second;
            }
        }
        cout << best << ' ';
        // sub for next
        aused = max(0, aused - 2);
        bused = max(0, bused - 2);
    }
    cout << '\n';
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