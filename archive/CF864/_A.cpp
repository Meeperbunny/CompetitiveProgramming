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
    int N, M;
    cin >> N >> M;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int cc = 4;
    if (a == 1 || a == N) {
        cc--;
    }
    if (b == 1 || b == M) {
        cc--;
    }
    int dd = 4;
    if (c == 1 || c == N) {
        dd--;
    }
    if (d == 1 || d == M) {
        dd--;
    }
    cout << min(cc, dd) << endl;
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