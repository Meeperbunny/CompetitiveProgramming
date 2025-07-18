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
    // For some trap, either jump and take (remaining - (c_k - 1)) - 
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    reverse(all(a));
    // set of ones ive ran through
    // If I swap, I get: A + (-B + BR) -> (-A + AR) + B
    ll C = 0;
    ll se = 0;
    ll ok = k;
    multiset<ll> cset;
    for(auto e : a) {
        se++;
        if (k) {
            cset.insert(e);
            k--;
        }
        else {
            ll wo = se - ok;
            ll trm = *cset.begin();
            ll NOJ = trm; // im saving this much, I lose on e because not saving
            ll J = e - wo;
            if (J > NOJ) {
                // Do it
                cset.erase(cset.begin());
                cset.insert(e - wo);
            }
        }
        cout << se << ' ';
        for(auto aa : cset) cout << aa << "_";
        cout << endl;
    }
    cout << accumulate(all(a), 0ll) - accumulate(all(cset), 0ll) << endl;
}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
}