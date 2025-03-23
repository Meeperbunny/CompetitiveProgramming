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

vector<ll> getdivs(ll n) {
    vector<ll> r;
    for(ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            r.push_back(i);
            r.push_back(n / i);
        }
    }
    return r;
}

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

void TC() {
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    unordered_map<long long, int, custom_hash> ac, bc;
    for(auto e : a) ac[e]++;
    for(auto e : b) bc[e]++;
    auto as = accumulate(all(a), 0ll);
    auto bs = accumulate(all(b), 0ll);
    ll mi = *max_element(all(b)) + 1;
    ll d = as - bs;
    bool ww = true;
    for(auto e : ac) {
        if (bc[e.first] == e.second) {
        }
        else ww = false;
    }
    if (ww) {
        cout << 1000000000 << endl;
        return;
    }
    else {
        vector<ll> c = getdivs(d);
        for(auto d : c) {
            if (d < mi) continue;
            unordered_map<long long, int, custom_hash> cnts;
            for(auto e : a) {
                cnts[e % d]++;
            }
            bool w = true;
            for(auto &[k, v] : cnts) {
                if (v != bc[k]) {
                    w = false;
                }
            }
            if (w) {
                cout << d << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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