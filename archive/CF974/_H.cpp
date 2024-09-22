#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

ll H[1000001];

void TC() {
    int n, q; cin >> n >> q;
    vector<ll> preHash(n + 1);
    for(int i = 1; i <= n; i++) {
        int j; cin >> j;
        preHash[i] = preHash[i - 1] ^ H[j];
    }
    // for(int i = 0; i < n + 1; i++) {
    //     cout << preHash[i] << ' ';
    // } cout << endl;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--;
        // cout << l << ' ' << r << endl;
        // dbg(preHash[l], preHash[r]);
        if ((preHash[r] ^ preHash[l]) == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    memset(H, 0, sizeof(H));
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 0; i <= 1000000; i++) {
        H[i] = rng();
    }
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}