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
    vector<int> a(n - 1);
    for(auto &e : a) cin >> e;

    vector<int> b(n);
    for(int i = 0; i < n - 1; i++) {
        b[i] |= a[i];
        b[i + 1] |= a[i];
    }
    for(int i = 0; i < n - 1; i++) {
        // cout << '\t' << i << ' ' << (b[i] & b[i + 1]) << ' ' << a[i] << endl;
        if ((b[i] & b[i + 1]) != a[i]) {
            cout << -1 << endl;
            return;
        }
    }
    for(auto e : b) cout << e << ' ';
    cout << endl;
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