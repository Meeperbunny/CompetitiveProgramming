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
    int t = 0;
    vector<int> tcounts(n);
    for(int i = 0; i < n; i++) {
        cin >> tcounts[i];
        int z;
        for(int q = 0; q < tcounts[i] - 1; q++) cin >> z;
    }
    for(auto e : tcounts) {
        for(int q = 31; q >= 0; q--) {
            int ebit = (e >> q) & 1, tbit = (t >> q) & 1;
            if (ebit && tbit) {
                t |= (1 << q) - 1;
            }
            else if (ebit) {
                t |= (1 << q);
            }
        }
    }
    cout << t << endl;
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