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
    string s, t;
    cin >> s >> t;
    int si = 0;
    int ti = 0;
    while(ti < t.size()) {
        if (si >= s.size()) {
            cout << "NO" <<endl;
            return;
        }
        char sc = s[si];
        char tc = t[ti];
        if (sc != tc) {
            cout << "NO" <<endl;
            return;
        }
        int scnt = 0;
        int tcnt = 0;
        while(si < s.size() && s[si] == sc) {
            scnt += 1;
            si++;
        }
        while(ti < t.size() && t[ti] == tc) {
            tcnt += 1;
            ti++;
        }
        if (2 * scnt < tcnt || tcnt < scnt) {
            cout << "NO" << endl;
            return;
        }
    }
    if (si != s.size()) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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