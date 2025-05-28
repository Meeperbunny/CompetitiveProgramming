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
const int maxn = 1e6 + 1;

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    else return gcd(b, a % b);
}

ll lcm(ll x, ll y) {
    return x * y / gcd(x, y);
}

const int N = maxn;
ll primes[maxn];
bool isnotprime[N + 1];
int pc = 0;
void sieve() {
    memset(isnotprime, 0, sizeof(isnotprime));
    isnotprime[0] = 1;
    isnotprime[1] = 1;
    for(int i = 2; i <= N; i++) {
        if (!isnotprime[i]) {
            primes[pc++] = i;
            for(int q = i * 2; q <= N; q += i) {
                isnotprime[q] = 1;
            }
        }
    }
}

vector<vector<ll>> divs(maxn);

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<ll, ll, custom_hash> pfs(int x) {
    unordered_map<ll, ll, custom_hash> m;
    for(int i = 0;; i++) {
        if (i * i > x) break;
        int prime = primes[i];
        while(x % prime == 0) {
            x /= prime;
            m[prime] += 1;
        }
    }
    if (x) {
        m[x] += 1;
    }
    return m;
}

map<int, int> distances(int num, int k) {
    // cout << "GETTING NUMS" << endl;
    auto pf = pfs(num);
    // For each dist pf, add it to the shit
    set<ll> nums = {1};
    for(auto [e, _] : pf) {
        if (e == 1) continue;
        // cout << e << endl;
        set<ll> newSet;
        ll curr = 1;
        while(curr <= k) {
            for(auto el : nums) {
                if (curr * el <= k)
                    newSet.insert(curr * el);
            }
            curr *= e;
        }
        swap(nums, newSet);
    }
    // cout << "NUMS DONE" << endl;
    map<ll, ll> distances;
    distances[1] = 0;
    for(auto it = distances.begin(); it != distances.end(); it++) {
        for(auto e : nums) {
        }
    }
    return distances;
}

void TC() {
    int x, y, k;
    cin >> x >> y >> k;
    int b = INT_MAX;
    for(auto d : divs[x]) {
        // Go to this div first, then to y if we can.
        if (y % d != 0) {
            continue;
        }
        // cout << "Getting c1" << endl;
        int lower = cost(x / d, k);
        // cout << "Getting c2" << endl;
        int upper = cost(y / d, k);
        // cout << "done" << endl;
        // cout << x << ' ' << y << ' ' << k << "   " << d << ' ' << lower << ' ' << upper << endl;
        if (lower == -1 || upper == -1) {
            continue;
        }
        b = min(b, lower + upper);
    }
    if (b >= INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << b << endl;
    }
}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    sieve();
    for(int i = 1; i < maxn; i++) {
        for(int q = i; q < maxn; q+= i) {
            divs[q].push_back(i);
        }
    }
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}