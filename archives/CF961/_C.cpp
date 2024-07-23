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
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> tops(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll tot = 0;
    for(int i = 1; i < n; i++) {
        if (a[i] == 1 && a[i - 1] != 1) {
            cout << -1 << endl;
            return;
        }
        if (a[i - 1] > a[i]) {
            ll c = a[i];
            ll ops = 0;
            while(c < a[i - 1]) {
                c *= c;
                ops++;
            }
            ops += tops[i - 1];
            tops[i] = ops;
            tot += ops;
        }
        else {
            ll used = 0;
            ll c = a[i - 1];
            while(c * c <= a[i] && used + 1 <= tops[i - 1]) {
                c *= c;
                used += 1;
            }
            ll left = max(0ll, tops[i - 1] - used);
            tops[i] = left;
            tot += left;
        }
    }
    cout << tot << endl;
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