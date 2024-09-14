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

void TC() {
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        set<int> cs;
        set<int> seen;
        for(int q = 0; q < n; q++) {
            if (i + q < n) {
                if (cs.count(a[i + q] % 4) && !seen.count(a[i + q])) {
                    tot += n - (i + q);
                    break;
                }
                else {
                    cs.insert(a[i + q] % 4);
                    seen.insert(a[i + q]);
                }
            } else break;
        }
    }
    cout << tot  + n << endl;
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