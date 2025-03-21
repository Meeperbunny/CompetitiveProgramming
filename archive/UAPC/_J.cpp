#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    ll AA, BB, CC, DD, EE, XX;
    cin >> AA >> BB >> CC >> DD >> EE >> XX;
    ll best =0;
    for(ll aconv = 0; aconv < 20; aconv++) {
        ll A = AA;
        ll B = BB;
        ll C = CC;
        ll D = DD;
        ll E = EE;
        ll X = XX;
        if (A < 3 * aconv) {
            continue;
        }
        A -= 3 * aconv;
        B += aconv;
        C += A / 5;
        // Flush out E and B
        ll econv = E / 3;
        E -= econv * 3;
        D += econv * 2;
        ll mu = min(X, D / 2);
        D -= mu * 2;
        X -= mu;
        B += 3 * mu;
        if (B < 3) {
            // Cant cycle or convert at all
            best = max(best, C);
        }
        else {
            // Try cycling [1...3] times at then end of each of these
            // We should always cycle 4 times if we can
            ll todo = X / 4;
            X -= todo * 4;
            B += 3 * todo;
            // Try doing 0...3 more
            for(int left = 0; left <= 3; left++) {
                ll HC = C + B / 3;
                best = max(best, HC);
                if (X == 0) break;
                // Do cycle
                if (E == 3) {
                    E = 0;
                    B += 3;
                    X--;
                }
                else {
                    E += 1;
                    X--;
                }
            }
        }
    }
    cout << best << endl;
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