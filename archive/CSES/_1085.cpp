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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll minsum = -1;
    for(ll Z = 1e15; Z >= 1; Z >>= 1) {
        while(true) {
            int groups = 1;
            ll curr = 0;
            for(int i = 0; i < n; i++) {
                dbg(Z + minsum, i, curr, groups);
                if (a[i] > Z + minsum) {
                    groups = INT_MAX;
                    break;
                }
                else if (curr + a[i] > Z + minsum) groups++, curr = a[i];
                else curr += a[i];
            }
            if (groups > k) {
                minsum += Z;
            }
            else break;
        }
    }
    cout << minsum + 1 << endl;
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