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
    int n, m, Q;
    cin >> n >> m >> Q;
    set<int> t;
    while(m--) {
        int a; cin >> a;
        t.insert(a);
    }
    while(Q--) {
        int c; cin >> c;
        int lpos, rpos;
        auto lit = t.upper_bound(c);
        bool leftWall = false, rightWall = false;
        if (lit != t.begin()) {
            lit = prev(lit);
            lpos = *lit;
        }
        else {
            // Just take right.
            leftWall = true;
        }
        auto uit = t.lower_bound(c);
        if (uit == t.end()) {
            // Just take left
            rightWall = true;
        }
        else {
            rpos = *uit;
        }
        if (leftWall) {
            cout << rpos - 1 << '\n';

        }
        else if (rightWall) {
            cout << n - lpos << '\n';
        }
        else {
            cout << (rpos - lpos) / 2 << '\n';
        }
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