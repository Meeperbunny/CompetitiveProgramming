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
    // 1 2 3 4 5 6
    // If i have top 2 i win
    // B??BA
    // B??AA
    // If someone has both ends they win
    // Must be split
    // if B has n (and b has one other card), B will win
    // If b has n but one card b will lose

    // if A has n and b has n - 1 and 1, B will win
    // If A has top 2, A wins
    int n; cin >> n;
    string s; cin >> s;
    int bc = count(all(s), 'B');
    if (s.size() == 2) {
        if (s == "AB") cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    else {
        if (s[0] == s[n - 1]) {
            if (s[0] == 'A') cout << "Alice" << endl;
            else cout << "Bob" << endl;
        }
        else {
            if (s[n - 1] == 'B') {
                if (bc == 1) cout << "Alice" << endl;
                else cout << "Bob" << endl;
            }
            else {
                if (s[n - 2] == 'B') {
                    cout << "Bob" << endl;
                }
                else {
                    cout << "Alice" << endl;
                }
            }
            // Is split.
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