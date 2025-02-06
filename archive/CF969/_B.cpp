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
    ll mav = 0;
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(auto &e: a) cin >> e;
    for(auto &e: a) mav = max(mav, e);
    while(m--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == '+') {
            if (mav >= l && mav <= r) {
                mav++;
                
            }
        }
        else {
            if (mav >= l && mav <= r) {
                mav--;
            }

        }
        cout << mav << '\n';
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