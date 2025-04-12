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

struct Bt {
    int mind = -1;
    Bt* n[2] = {0, 0};
};

void TC() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    Bt *rt = new Bt;
    int bans = n + 2;
    for(int i = 0; i < n; i++) {
        int c = a[i];
        // insert?
        Bt* tm = rt;
        for(int q = 31; q >= 0; q--) {
            int cb = (c >> q) & 1;
            if (tm->n[cb] == 0) {
                tm->n[cb] = new Bt;
            }
            tm = tm->n[cb];
            tm->mind = i;
        }
        // If we are 1 and k is 1, then we need a 0. If not a zero, then is not possible.
        // If we are 0 and k is 1, then we need a one. If not one, then is not possible.
        // If we are 1 and k is 0, then we need 0 to be good, otherwise, is still possible.
        // If we are 0 and k is 0, then we need 1 to be good, otherwise, is still possible.
        bool possible = true;
        int mn = -1;
        tm = rt;
        int A = -1;
        for(int b = 31; b >= 0; b--) {
            int mb = (a[i] >> b) & 1;
            int kb = (k >> b) & 1;
            // cout << i << ' ' << b << ' ' << kb << ' ' << mb << endl;
            if (kb == 1) {
                if (tm->n[kb ^ mb] == 0) {
                    possible = false;
                    break;
                }
                else {
                    tm = tm->n[kb ^ mb];
                    mn = tm->mind;
                }
            }
            else if (kb == 0) {
                kb = 1;
                if (tm->n[kb ^ mb] != 0) {
                    // If we can go to the best, then check as a valid answer.
                    A = max(tm->n[kb ^ mb]->mind, A);
                }
                // Try going to worst case. 
                if (tm->n[!(kb ^ mb)] == 0) {
                    possible = false;
                    break; // Cant go anywhere
                }
                else { // Can go somewhere, set min num
                    tm = tm->n[!(kb ^ mb)];
                    mn = tm->mind;
                }
            }
        }
        if (possible) {
            A = max(A, mn);
        }
        if (A != -1) {
            bans = min(bans, i - A + 1);
        }
    }
    if (bans == n + 2) {
        bans = -1;
    }
    cout << bans << endl;
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