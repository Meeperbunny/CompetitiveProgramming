#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/// @brief Returns a prime sieve as a vector<bool> of size n + 1.
std::vector<bool> sieve(ll n) {
    std::vector<bool> isprime(n + 1, true);
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
std::vector<ll> primes(ll n) {
    auto isprime = sieve(n);
    std::vector<ll> plist;
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