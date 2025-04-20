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
    // "BPP" -> 0
    // "PBP" -> 2
    // "PPB" -> 4

    // "BBP" -> 0
    // "BPB" -> 2
    // "PBB" -> 4
    int n; cin >> n;
    string s; cin >> s;
    ll tc = 0;
    ll bp = 0;
    vector<ll> pps;
    ll pp = n - 1;
    ll tc = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            int d = i - bp;
            tc += d;
            bp += 1;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if (s[i] == 'P') {
            tc += pp - i;
            pps.push_back(i);
            pp -= 1;
        }
    }
    // EE -> good
    // OO -> + 1 more
    // OE -> + 0 more
    // EO -> + 0 more
    // OOE
    // PPB -> 4
    int la = n;
    vector<int> gaps;
    bool haseven = false;
    for(auto i : pps) {
        if (((la - i) & 1)) {
        }
        else {
            tc += 2;
        }
        gaps.push_back(la - i);
        la = i;
    }
    // cout << tc << ' ' << haseven << endl;
    cout << tc / 4 <<  endl;
    // tot cost decreases by 4.
    // need a 2 decrease if not even
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