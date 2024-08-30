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
    ll n, k;
    cin >> n >> k;
    ll mav = 0;
    vector<ll> inset;
    for(ll i = 1;; i *= 2) {
        if (i + mav >= k) break;
        inset.push_back(i);
        mav += i;
    }
    ll diff = (k - 1) - mav;
    if (diff) inset.push_back(diff);
    inset.push_back(k + 1);
    inset.push_back(k + 2);
    for(ll i = k + 1; inset.size() != 25; i *= 2) {
        inset.push_back(i);
    }
    cout << inset.size() << endl;
    for(auto e : inset) cout << e << ' ';
    cout << endl;

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