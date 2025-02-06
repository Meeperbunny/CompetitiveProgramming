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
    map<int, int> cnts;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int q; cin >> q;
        if (q == 1) {
            int x; cin >> x;
            cnts[x]++;
        }
        else if (q == 2) {
            int x; cin >> x;
            cnts[x]--;
            if (cnts[x] == 0) {
                cnts.erase(x);
            }
        }
        if (q == 3) {
            cout << cnts.size() << endl;
        }
    }
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