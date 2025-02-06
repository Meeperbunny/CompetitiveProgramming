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
    ll n; cin >> n;
    vector<ll> ans(10, 0);
    vector<ll> cntsWO(10, 0);
    vector<ll> cnts(10, 0);
    for(ll i = 0; i < 100000; i++) {
        string s = to_string(i);
        cnts[0] += 5 - s.size();
        for(auto c : s) {
            cnts[c - '0']++;
            cntsWO[c - '0']++;
        }
    }
    // Get above 100000
    for(ll i = 0; i < n / 100000; i++) {
        vector<ll> subc(10, 0);
        string u = to_string(i);
        for(auto c : u) {
            if (i == 0) break;
            subc[c - '0']++;
        }
        for(ll q = 0; q < 10; q++) {
            if (i == 0) ans[q] += subc[q] * 100000ll + cntsWO[q];
            else ans[q] += subc[q] * 100000ll + cnts[q];
        }
    }
    // Get for last 1000000
    ll lastnum = n / 100000ll;
    ll times = n % 100000ll;
    vector<ll> upper(10, 0);
    string t = to_string(lastnum);
    for(auto c : t) {
        if (lastnum == 0) break;
        upper[c - '0']++;
    }
    for(ll i = 0; i <= times; i++) {
        string s = to_string(i);
        if (lastnum != 0) {
            ans[0] += 5 - s.size();
        }
        for(auto c : s) {
            ans[c - '0']++;
        }
        for(ll q = 0; q < 10; q++) {
            ans[q] += upper[q];
        }
    }
    for(ll i = 0; i < 10; i++) {
        cout << ans[i] - ll(i == 0) << ' ';
    } cout << endl;

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