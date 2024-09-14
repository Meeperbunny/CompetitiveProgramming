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
    int n;
    cin >> n;
    string s; cin >> s;
    bool isg = false;
    int sq = 1;
    for(sq = 1; sq * sq <= n; sq++) {
        if (sq*sq == n) {
            isg = true;
            break;
        }
    }
    if (!isg) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        bool isg = true;
        if (i < sq || i >= n - sq) {
            if (s[i] != '1') isg = false;
        }
        else if (i % sq == 0 || i % sq == (sq - 1)) {
            if (s[i] != '1') isg = false;
        }
        else {
            if (s[i] != '0') isg = false;
        }
        if (!isg) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
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