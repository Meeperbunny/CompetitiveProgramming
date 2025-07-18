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

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/// @brief Returns a prime sieve as a vector<bool> of size n + 1.
vector<bool> sieve(ll n) {
    vector<bool> isprime(n + 1, true);
    isprime[0] = false, isprime[1] = false;

    // Do 2 first.
    for(ll i = 4; i <= n; i += 2) {
        isprime[i] = false;
    }

    for(ll i = 3; i * i <= n; i += 2) {
        if (isprime[i] && i * i <= n) {
            for(ll q = i * i; q <= n; q += 2 * i) {
                isprime[q] = false;
            }
        }
    }
    return isprime;
}

/// @brief Returns a vector of primes <= n.
vector<ll> primes(ll n) {
    auto isprime = sieve(n);
    vector<ll> plist;
    // TODO: Approx size and reserve plist.
    if (n >= 2) {
        plist.push_back(2);
    }
    for(size_t i = 3; i < isprime.size(); i += 2) {
        if (isprime[i]) {
            plist.push_back(i);
        }
    }
    return plist;
}

vector<bool> is_prime;

void TC() {
    int n; cin >> n;
    vector<int> p(n);
    iota(all(p), 1);
    vector<int> inds;

    for(int i = n - 1; i >= 0; i--) {
        int num = i + 1;
        if (is_prime[num]) {
            inds.clear();
            for(int q = i; q < n; q += num) {
                if (p[q] % num == 0) {
                    inds.push_back(q);
                }
            }
            for(int q = 0; q < inds.size() - 1; q++) {
                p[inds[q]] = p[inds[q + 1]];
            }
            p[inds[inds.size() - 1]] = num;
        }
    }
    for(auto e : p) cout << e<< ' ';
    cout << endl;

}

int main() {
    is_prime = sieve(100000);
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
}