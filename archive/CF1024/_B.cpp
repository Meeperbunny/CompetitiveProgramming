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
    string s;
    cin >> s;
    int sc{}, pc{};
    int rms = -1;
    int lmp = -1;
    int i = 0;
    for(auto c : s) {
        if (c == 's') {
            sc++;
            if (pc) {
                cout << "NO" << endl;
                return;
            }
            rms = i;
        }
        else if (c == 'p') {
            pc++;
            if (lmp == -1) lmp = i;
            if (pc >= 2 && sc >= 2) {
                cout << "NO" << endl;
                return;
            }
        }
        i++;
    }
    if (rms != -1 && lmp != -1) {
        int s1 = rms;
        int s2 = n - lmp - 1;
        if (s1 != 0 && s2 != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;

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