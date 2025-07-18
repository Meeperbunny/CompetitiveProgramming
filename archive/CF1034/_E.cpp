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
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    map<int, int> cnts;
    for(auto &e : a) cnts[e]++;
    // Can change to some mex if we can remove more than the level, or less than or equal to all above.
    // Priority queue to remove once we hit some + 1 of the level? Then we cannot be the mex?
    // once we can remoeve all of ourself then we are mex. 
    // Given some initial mex, it is it.
    // If we can remove all of ourself we are mex
    // if we can remove all ourself and all above and all 1 below, then we can't be mex?
    // we remove everything but the line up, this is stopping.
    vector<int> delta(n + 1, 0); // to input changes.
    int mex;
    for(int i = 0; i < n + 2; i++) {
        if (cnts.contains(i)) continue;
        else {
            mex = i;
            break;
        }
    }
    // if this k is below mex then is good.
    for(auto [k, v] : cnts) {
        if (k < mex) {
            delta[v] += 1;
    
        // add back at some d
        delta[n - k] -= 1;

        }
    }
    int cv = 1;
    for(int k = 0; k <= n; k++) {
        cv += delta[k];
        cout << cv << ' ';
    }
    cout << endl;
}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
}