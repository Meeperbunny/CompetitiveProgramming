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
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for(auto &e : a) cin >> e;
    for(auto &e : b) {
        cin >> e;
        e--;
    }
    // If b is lower than i, should never skip.
    // Only should use one to get to something higher.
    // Always do rightmost
    // 2nd from right is either take it, or skip to higher.
    // 3rd from right is either take it or skip to 2nd or skip to rightmost. 
    // v[i] = value of starting at some index i. Once I get rightmost, then should just take all.
    // What is cheapest to get to index i?
    set<pair<ll, ll>> priceInd; // {priceToGetToi, i}
    priceInd.insert({0, 0});
    ll best = 0;
    ll totalSum = 0;
    for(int i = 0; i < n; i++) {
        totalSum += a[i];
        // Get rid of invalid.
        while(priceInd.size() && priceInd.begin()->second < i) {
            priceInd.erase(priceInd.begin());
        }
        // Cant do anything else.
        if (priceInd.empty()) break;
        // Get the best.
        best = max(best, totalSum - priceInd.begin()->first);
        // Insert current.
        priceInd.insert({priceInd.begin()->first + a[i], b[i]});
    }
    cout << best << endl;
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