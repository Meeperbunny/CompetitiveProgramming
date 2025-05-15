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

vector<bool> isprime(10000000, true);
vector<ll> primes;
vector<ll> primePrefix(1, 0);

void TC() {
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    sort(all(a), greater<ll>());
    ll best = 0;
    ll bind = 0;
    for(int i = 0; i < n; i++) {
        best += a[i];
        if (best < primePrefix[i + 1]) {
            break;
        }
        bind += 1;
    }
    cout << n - bind << endl;
}

int main() {
    for(int i = 2; i < 10000000; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            primePrefix.push_back(primePrefix.back() + i);
            for(int q = i; q < 10000000; q += i) {
                isprime[q] = false;
            }
        }
    }


    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}