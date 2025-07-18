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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    ll tb = 0;
    vector<vector<ll>> costSeq(n, vector<ll>(70, LLONG_MAX));
    for(ll i = 0; i < n; i++) {
        ll bb = __builtin_popcount(a[i]);
        tb += bb;
        ll ln = a[i];
        ll inc = 0;
        costSeq[i][0] = a[i];
        // cout << "I IS " << i << endl;
        bool changed = true;
        while(changed) {
            changed = false;
            // cout << "LN " << ln << endl;
            for(ll q = 0; q < 63; q++) {
                if (((ln >> q) & 1) == 0) {
                    // cout << q << endl;
                    ln |= (1ll << q);
                    changed = true;
                    break;
                }
            }
            // cout << "DONE" << endl;
            inc++;
            costSeq[i][inc] = min(costSeq[i][inc], ln);
        }
        // cout << "DD" << endl;
        for(int q = 63; q >= 1; q--) {
            if (costSeq[i][q] != LLONG_MAX)
                costSeq[i][q] -= costSeq[i][q - 1];
        }
        costSeq[i][0] = 0;
    }
    vector<ll> cind(n, 1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;

    // for(int i = 0; i < n; i++) {
    //     cout << a[i] << " : : ";
    //     for(int q = 0; q < 5; q++) cout << costSeq[i][q] << ' ';
    //      cout << endl;
    // }
    
    for(int i = 0; i < n; i++) {
        Q.push({costSeq[i][1], i});
    }
    while(true) {
        auto [mi, ind] = Q.top();
        Q.pop();
        if (mi > k) break;
        k -= mi;
        tb++;
        Q.push({costSeq[ind][++cind[ind]], ind});
    }
    cout << tb << endl;
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