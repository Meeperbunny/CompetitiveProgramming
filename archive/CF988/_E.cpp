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
    int n; cin >> n;
    string s(n, '1');
    int co = 0;
    int ls = 0;
    int pr = 0;
    for(int i = 2; i <= n; i++) {
        cout << "? 1 " << i << endl;
        int r; cin >> r;
        int d = r - pr;
        if (!d && co) {
            s[i - 1] = '0';
            co += 1;
            continue;
        }
        pr = r;
        int no = d - co;
        co += no;
        // cout << "new ones: " << no << endl;
        for(int q = i - 2; q >= i - 2 - no + 1; q--) s[q]--;
    }
    if (!pr) {
        cout << "! IMPOSSIBLE" << endl;
    }
    else {
        cout << "! " << s << endl;
    }
}

int main() {
    // HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}