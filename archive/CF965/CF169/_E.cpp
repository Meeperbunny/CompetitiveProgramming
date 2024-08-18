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

int sieve[10000001];
int primes[1000000];
int sfac[10000001];
int ps[10000001];
int pc = 0;

void TC() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int c = 0;
    for(auto e : a) {
        c ^= sfac[e];
    }
    if (c) {
        cout << "Alice" << endl;
    }
    else {
        cout << "Bob" << endl;
    }
}

int main() {
    HEADER;
    int T = 1;
    cin >> T;

    memset(sieve, 0, sizeof(sieve));
    memset(primes, 0, sizeof(primes));
    memset(sfac, 0, sizeof(sfac));
    memset(ps, 0, sizeof(ps));
    sfac[1] = 1;
    for(int i = 2; i <= 10000000; i++) {
        if (!sieve[i]) {
            ps[i] = pc + 1;
            primes[pc++] = i;
            for(int q = i * 2; q <= 10000000; q += i) {
                sieve[q] = 1;
            }
        }
    }
    for(int i = 1; i < pc; i++) {
        int p = primes[i];
        int r = ps[p];
        for(int q = p; q <= 10000000; q += p) {
            if (!sfac[q]) {
                sfac[q] = r;
            }
        }
    }

    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}