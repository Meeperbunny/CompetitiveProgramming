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
    int oc{}, ec{};
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < n; i++) {
        if (a[i] == '1') {
            if (i & 1) {
                oc++;
            }
            else {
                ec++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if (b[i] == '1') {
            if (i & 1) {
                ec++;
            }
            else {
                oc++;
            }
        }
    }
    if (ec > n / 2) {
        cout << "NO" << endl;
        return;
    }
    if (oc > (n + 1) / 2) {
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