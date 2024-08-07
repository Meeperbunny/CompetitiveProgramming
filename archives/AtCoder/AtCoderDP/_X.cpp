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

struct Block {
    ll w, s, v;
};

void TC() {
    int n; cin >> n;
    vector<Block> b(n);
    for(int i = 0; i < n; i++) b[i].w >> b[i].s >> b[i].v;
    sort(b.begin(), b.end(), [](Block &f, Block &s){
        
    });
    vector<ll> dp(20000 + 1, -1e10);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int q = b[i].s; q >= 0; q--) {
            dp[q + b[i].w] = max(dp[q + b[i].w], dp[q] + b[i].v);
        }
    }
    ll ma = 0;
    for(auto e : dp) ma = max(ma, e);
    cout << ma << endl;
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