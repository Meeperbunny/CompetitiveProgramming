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
const int N = 20000000;
ll primes[N / 5 + 1];
bool isp[N + 1];
int pc = 0;
void sieve() {
    memset(isp, 0, sizeof(isp));
    for(int i = 2; i <= N; i++) {
        if (!isp[i]) {
            primes[pc++] = i;
            for(int q = i * 2; q <= N; q += i) {
                isp[q] = 1;
            }
        }
    }
}

ll cnts[N + 1];
ll best[N + 1];

void TC() {
    int n, q; cin >> n;
    memset(cnts, 0, sizeof(cnts));
    memset(best, 0, sizeof(best));
    sieve();
    for(int i = 0; i < n; i++) {
        cin >> q;
        cnts[q]++;
    }
    for(int i = 0; i < pc; i++) {
        for(int q = N / primes[i]; q >= 1; q--) {
            cnts[q] += cnts[q * primes[i]];
        }
    }
    ll bc = 0;
    best[1] = n;
    for(ll i = 1; i <= N; i++) {
        for(ll q = 0; q < pc; q++) {
            if (i * primes[q] > N) break;
            ll nu = i * primes[q];
            best[nu] = max(best[nu], cnts[nu] * (nu - i) + best[i]);
        }
        bc = max(bc, best[i]);
    }
    cout << bc << endl;
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