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
    ll n; string s;
    cin >> n >> s;
    vector<ll> U(n);
    vector<ll> L(n);

    // for(int i = 0; i < n; i++) {
    //     s[i] = '0' + int(!(s[i] - '0'));
    //     cout << s << endl;
    //     s[i] = '0' + int(!(s[i] - '0'));
    // }


    ll ma = 0;
    if (s[0] == '0') {
        U[0] = 0;
        L[0] = n - 1;
    }
    else {
        U[0] = 1;
        L[0] = 0;
    }
    ma = max({ma, L[0], U[0]});

    for(int i = 1; i < n; i++) {
        char lc = s[i - 1];
        char c = s[i];
        if (c == '1') {
            if (lc == '1') {
                U[i] = 1;
                L[i] = 0;
            }
            else {
                U[i] = 1 + L[i - 1];
                L[i] = 0;
            }
        }
        else {
            // If last is zero, then just add to it
            L[i] = (n - i - 1) + L[i - 1];
            U[i] = (i) + U[i - 1];
        }
        ma = max({ma, L[i], U[i]});
    }
    // for(int i = 0; i < n; i++) cout << L[i] << ' '; cout << endl;
    // for(int i = 0; i < n; i++) cout << U[i] << ' '; cout << endl;
    cout << ma << endl;
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