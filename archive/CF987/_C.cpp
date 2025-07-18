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
    // If even,j ust ever 2
    // 2 2 3 3
    // 
    int n; cin >> n;
    if (n % 2 == 0) {
        for(int i = 0; i < n; i++) {
            cout << int(i / 2) + 1 << ' ';
        }
        cout << endl;
        return;
    }
    else {
        if (n < 27) {
            cout << -1 << endl;
            return;
        }
        else {
            cout << "1 13 2 2 3 3 4 4 5 5 6 6 7 7 8 8 1 9 9 10 10 11 11 12 12 1 13 ";
            int i = 14;
            for(int q = 0; q < n - 27; q += 2) {
                cout << i << ' ' << i << ' ';
                i++;
            } cout << endl;
            return;
        }
    }
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