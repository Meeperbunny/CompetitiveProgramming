#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ways = 0;
    if ((a > c && b == d) || (a == c && b > d) || (a > c && b > d)) ways++;
    if ((a > d && b == c) || (a == d && b > c) || (a > d && b > c)) ways++;
    if ((b > c && a == d) || (b == c && a > d) || (b > c && a > d)) ways++;
    if ((b > d && a == c) || (b == d && a > c) || (b > d && a > c)) ways++;
    cout << ways << endl;
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