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
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        if (a[i] & 1) {
            vector<ll> evens;
            ll lo = 0;
            for(auto e : a) {
                if (e % 2 == 0) evens.push_back(e);
                else {
                    lo = max(lo, e);
                }
            }
            sort(evens.begin(), evens.end());
            bool b = false;
            for(auto e : evens) {
                if (lo > e) {
                    lo = e + lo;
                }
                else {
                    b = true;
                    break;
                }
            }
            if (!b) {
                cout << evens.size() << endl;
                return;
            }
            cout << evens.size() + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
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