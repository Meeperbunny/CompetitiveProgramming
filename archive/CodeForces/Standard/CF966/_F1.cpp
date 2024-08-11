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

#define MAXN 20000001
bool sieve[MAXN];

bool isprime(const int &a) {
    return !sieve[a];
}

void TC() {
    ll n; cin >> n;
    vector<ll> ans(n);
    vector<vector<ll>> a(n, vector<ll>(4));
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][3] = i;
        if (a[i][1] < a[i][2]) swap(a[i][1], a[i][2]);
    }
    sort(a.begin(), a.end(), [](vector<ll> &a, vector<ll> &b){
        return a[0] < b[0];
    });
    ll lp = -1;
    ll larprime = 0;
    ll las = 0;
    for(int i = 0; i < n; i++) {
        ll m = a[i][0];
        ll lv = a[i][1];
        ll sv = a[i][2];
        ll qind = a[i][3];
        // update largest  prime
        while(las < m) {
            las++;
            if (isprime(las)) {
                lp = larprime;
                larprime = las;
            }
        }
        // Use 1 and m or lar prime and lar prime - 1
        ans[qind] = max(lv * m + sv, larprime * lv + (larprime - 1) * sv);
        for(int j = larprime - 1; j >= 3; j--) {
            if (isprime(j)) {
                ll x = ((larprime / j) + 1) * j - 1;
                // dbg(qind, lp, x, lp * lv + (m) * sv);
                dbg(j, x);
                ans[qind] = max(ans[qind], min(m, x) * lv + j * sv);

            }
        }
        if (lp >= 2) {
            ll x = ((larprime / lp) + 1) * lp - 1;
            // dbg(qind, lp, x, lp * lv + (m) * sv);
            ans[qind] = max(ans[qind], min(m, x) * lv + lp * sv);
        }
    }
    for(int i = 0; i  < n; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    HEADER;
    int T = 1;
    // Sieve
    memset(sieve, 0, sizeof(sieve));
    sieve[0] = 1, sieve[1] = 1;
    for(int i = 0; i < MAXN; i++) {
        if (!sieve[i]) {
            for(int q = 2 * i; q < MAXN; q += i) {
                sieve[q] = 1;
            }
        }
    }
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}