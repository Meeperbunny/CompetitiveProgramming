#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    ll n, k, l;
    cin >> n >> k >> l;
    k *= 2; l *= 2;
    vector<ll> a(n);
    for(auto &e: a) {cin>>e;e*=2;}
    ll t = 0;
    // Move leftmost to the right.
    ll cpos = k;
    ll lpos = a.front();
    t += lpos;
    lpos = 0;
    dbg(0, t, cpos, lpos);
    for(int i = 1; i < n; i++) {
        // If you are or less, get to last + k.
        if (a[i] <= a[i - 1] + k) {
            // Try to get as far as possible no matter the dist.
            ll cp = a[i];
            cp = min(lpos + k, a[i] + t);
            // Will always pass it on, dont change t.
            cpos = cp + k;
            lpos = cp;
        }
        else {
            // if you are more, compress as much as possible?
            ll cp = max(lpos + k, a[i] - t);
            ll dist = cp - lpos;
            dbg(dist, cp);
            assert(dist % 2 == 0);
            ll te = (dist - k) / 2;
            t += te;
            cp -= te;

            cpos = cp + k;
            lpos = cp;
        }
        dbg(i, t, cpos, lpos);
        if (cpos >= l) {
            cout << t << '\n';
            return;
        }
    }
    // For rightmost, push all the way.
    cout << t + (l - cpos) << '\n';

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