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
    vector<int> h(n), s(n);
    for(auto &e : h) cin >> e;
    for(auto &e : s) cin >> e;
    vector<int> maxPages(x + 1, 0);
    int mp = 0;
    for(int i = 0; i < n; i++) {
        for(int q = x; q >= h[i]; q--) {
            maxPages[q] = max(maxPages[q], maxPages[q - h[i]] + s[i]);
            mp = max(maxPages[q], mp);
        }
    }
    cout << mp << endl;
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