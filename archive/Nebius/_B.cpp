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
    int n; cin >> n;
    int k, d, w;
    cin >> k >> d >> w;
    vector<int> t(n);
    for(auto &e : t) cin >> e;
    sort(all(t));
    int lp = -1;
    int dcl = 0;
    int pc = 0;
    for(int i = 0; i < n; i++) {
        int ct = t[i];
        // cout << i << ' ' << ct << endl;
        if (dcl == 0) {
            lp = -1;
        }
        else {
        if (lp != -1) {
            if (dcl == 0) {
                lp = -1;
            }
            else {
                if (lp + d < ct) {
                    lp = -1;
                }
                else {
                    dcl -= 1;
                }
            }
        }
        }
        if (lp == -1) {
            // cout << "OPENING NEW" << endl;
            int bt = ct + w;
            lp = bt;
            dcl = k - 1;
            pc += 1;
        }
    }
    cout << pc << endl;
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