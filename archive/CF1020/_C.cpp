#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    int M = -1;
    for(int i = 0; i < n; i++) {
        if (b[i] != -1) {
            M = b[i] + a[i];
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if (b[i] != -1) {
            if (M != b[i] + a[i]) {
                cout << 0 << endl;
                return;
            }
        }
    }
    if (M == -1) {
        int ma = *max_element(all(a));
        int mi = *min_element(all(a));
        int a = max(0, k - (ma - mi) + 1);
        cout << a << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        int myn = M - a[i];
        if (myn > k || myn < 0) {
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;
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