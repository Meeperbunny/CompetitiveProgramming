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
    int n, x;
    cin >> n >> x;
    vector<int> mc(x + 1, x + 1);
    mc[0] = 0;
    for(int i = 0; i < n; i++) {
        int c; cin >> c;
        for(int q = c; q <= x; q++) {
            mc[q] = min(mc[q - c] + 1, mc[q]);
        }
    }
    mc[x] = mc[x] == x + 1 ? -1 : mc[x];
    cout << mc[x] << endl;
}

int main() {
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}