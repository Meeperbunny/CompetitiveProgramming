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

const int N = 100'000;
vector<vector<int>> divs(N + 1);

void TC() {
    ll n, q;
    cin >> n >> q;
    map<int, set<int>> pos;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        int j; cin >> j;
        a[i] = j;
        pos[a[i]].insert(i);
    }
    while(q--) {
        ll k, l, r;
        cin >> k >> l >> r;
        l--, r--;
        ll c = l;
        ll t = 0;
        while(c <= r) {
            if (k == 1) {
                t += r - c + 1;
                break;
            }
            while(k % a[c] == 0) {
                k /= a[c];
            }
            int calcuntil = INT_MAX;
            for(auto &d : divs[k]) {
                auto it = pos[d].lower_bound(c);
                if (it == pos[d].end()) {continue;}
                int mind = *it;
                calcuntil = min(calcuntil, mind);
            }
            // cout << k << ' ' << a[c] << ' ' << c << ' ' << calcuntil << endl;
            // Add [c, calcuntil)
            calcuntil = min(r + 1, ll(calcuntil));
            t += (calcuntil - c) * k;
            c = calcuntil;
        }
        cout << t << endl;
    }
}

int main() {
    for(int i = 1; i <= N; i++) {
        for(int q = i; q <= N; q += i) {
            divs[q].push_back(i);
        }
    }
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}