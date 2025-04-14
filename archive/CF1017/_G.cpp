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

struct dll {
    dll* nx[2] = {0,0};
    ll v = 0;
};

void TC() {
    dll *nb = 0;
    ll sz = 0;
    ll nrz = 0;
    ll nsum = 0;
    ll rrz = 0;
    ll rsum = 0;
    int dr = 0;
    int q; cin >> q;
    while(q--) {
        int s; cin >> s;
        if (s == 1) {
            ll bv = nb->v;
            nrz -= bv * sz;
            nrz += nsum;

            // ll rbv = nb->nx[1 ^ dr]->v;
            rrz -= rsum;
            rrz += bv * sz;

            nb = nb->nx[0 ^ dr];

        }
        if (s == 2) {
            swap(nrz, rrz);
            swap(nsum, rsum);
            nb = nb->nx[1 ^ dr];
            dr ^= 1;
        }
        if (s == 3) {
            ll k; cin >> k;
            auto nn = new dll;
            nn->v = k;
            if (sz == 0) {
                nb = nn;
                nb->nx[1 ^ dr] = nb;
                nb->nx[0 ^ dr] = nb;
            }
            else if (sz == 1) {
                nn->nx[1 ^ dr] = nb;
                nn->nx[0 ^ dr] = nb;
                nb->nx[1 ^ dr] = nn;
                nb->nx[0 ^ dr] = nn;
                nb = nn;
            }
            else if (sz >= 2) {
                nn->nx[1 ^ dr] = nb->nx[1 ^ dr];
                nn->nx[0 ^ dr] = nb;
                nb->nx[1 ^ dr]->nx[0 ^ dr] = nn;
                nb->nx[1 ^ dr] = nn;
                nb = nn;
            }
            sz += 1;
            nsum += k;
            rsum += k;
            nrz = nrz + k * sz;
            rrz = rrz + rsum;
        }
        cout << nrz << '\n';
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