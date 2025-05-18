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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    map<int, int> cnts;
    for(auto e : a) cnts[e]++;
    int maa = *max_element(all(a));
    int mii = *min_element(all(a));
    // If current range is greater than k + 1, is bad
    // If current range is k + 1, then is good if max cnt is 1
    // If current range is k or lower, then is baesed on cnt
    int range = maa - mii;
    if (range > k + 1) {
        cout << "Jerry" << endl;
        return;
    }
    else if (range == k + 1) {
        if (cnts[maa] == 1) {
            // Can save
        }
        else {
            cout << "Jerry" << endl;
            return;
        }
    }
    ll sum = accumulate(all(a), 0ll);
    cout << ((sum & 1) ? "Tom" : "Jerry") << endl;
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