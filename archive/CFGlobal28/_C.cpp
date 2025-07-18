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
    string s; cin >> s;
    cout << 1 << ' ' << s.size() << ' ';
    int bo = 0;
    int boi = -1;
    int n = s.size();
    // If is all 1s, do small
    if (count(all(s), '1') == n) {
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    int fz = s.find('0');
    int sz = n - fz;
    vector<bool> bm(sz, 0);
    int bi = -1;
    for(int i = 0; i + sz <= n; i++) {
        for(int q = 0; q < sz; q++) {
            bool r = s[fz + q] ^ s[i + q];
            if (r && !bm[q]) {
                // This is better, set as the ind and reset bm.
                for(int j = 0; j < sz; j++) {
                    bm[j] = s[fz + j] ^ s[i + j];
                }
                bi = i;
            }
            else if (!r && bm[q]) {
                // This is worse
                break;
            } // Otherwise can't tell.
        }
    }
    cout << 1 + bi << ' ' << bi + sz << endl;
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