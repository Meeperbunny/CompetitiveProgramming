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
    // int lsz = 1;
    // for(ll i = 66; i <= 1e12; i += 66) {s
    //     auto s = to_string(i);
    //     // cout << s << endl;
    //     auto se = set<char>(all(s));
    //     // cout << "Z" << endl;
    //     // for(auto e : se) cout << e << endl;
    //     if (s.size() > lsz) {
    //         if ((se.size() <= 2 && se.count('3') && se.count('6')) || (se.size() <= 1 && se.count('3') && se.count('6'))) {
    //             cout << i << endl;
    //             lsz = s.size();
    //         }
    //     }
    // }
    int n; cin >> n;
    string ans(n, '3');
    if (n == 2) {
        cout << 66 << endl;
        return;
    }
    if (n <= 3) {
        cout << - 1<< endl;
        return;
    }
    if (!(n & 1)) {
        ans[n - 2] = '6';
        ans[n - 1] = '6';
    }
    else {
        ans[n - 4] = '6';
        ans[n - 2] = '6';
        ans[n - 1] = '6';
    }
    cout << ans << endl;

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