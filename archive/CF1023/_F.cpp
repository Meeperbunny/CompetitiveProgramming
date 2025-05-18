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
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;

    vector<tuple<ll, ll, ll>> s; // EL, IDX, TC
    ll TC = 0;
    for(int i = 0; i < n; i++) {
        // Check if a[i] is needed. If it is not, then dont insert.
        // If it is, then insert. Get rid of all that it dominates (< a[i])
        // 
        ll c = a[i];
        bool shouldInsert = true;
        while(s.size()) {
            // If last is dominating, then don't insert.
            if (get<0>(s.back()) + 2 <= c) {
                shouldInsert = false;
                break;
            }
            else if (get<0>(s.back()) + 1 <= c) {
                // We should use me until we get to the prev one.
                shouldInsert = true;
                break;
            }
            else {
                // Use me, and get rid of last.
                // GET RID OF LAST HERE
                shouldInsert = true;
                TC -= get<2>(s.back());
                s.pop_back();
                continue;
            }
        }
        // If should insert, insert myself in
        if (s.empty() || shouldInsert) {
            ll moveTo = -1;
            if (s.size()) {
                moveTo = get<1>(s.back());
            }
            ll dist = i - moveTo;
            s.push_back({c, i, dist * c + (dist - 1)});
            TC += dist * c + (dist - 1);
            // cout << i << ' ' << c << dist * c + (dist - 1) << endl;
        }

        auto [aa, ab, ac] = s.back();
        ll move = i - ab;
        // cout << TC << ' ' << 2 * move + (move) * aa << endl;
        cout << TC + 2 * move + (move) * aa << ' ';
    }
    cout << endl;
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