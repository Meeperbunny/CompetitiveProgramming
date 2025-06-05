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

struct CS {
    ll offset = 0;
    bool isneg = false;
    map<ll, ll> nums;
    void flip() {
        isneg = !isneg;
    }
    void add(ll num) {
        if (isneg) {
            num = -num;
            nums[num - offset] += 1;
        }
        else {
            nums[num - offset] += 1;
        }
    }
    void remove(ll num) {
        ll tn;
        if (isneg) {
            num = -num;
            tn = num - offset;
        }
        else {
            tn = num - offset;
        }
        nums[tn] -= 1;
        if (!nums[tn]) nums.erase(nums.find(tn));
    }
    ll max() {
        if (!isneg) {
            return nums.begin()->first + offset;
        }
        else {
            return -(nums.rbegin()->first) - offset;
        }
    }
    void addToAll(ll num) {
        if (isneg) num = -num;
        offset += num;
    }
    void clear() {
        offset = 0;
        nums.clear();
    }
};

void TC() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> a(n + 1, vector<ll>(m));
    for(int i = 1; i < n + 1; i ++) {
        for(auto &e : a[i]) cin >> e;
    }
    n += 1;
    vector<ll> pre(m, LLONG_MAX);
    pre[0] = 0;
    CS cs;
    vector<ll> nums(m);
    vector<ll> nxt(m, LLONG_MAX);
    for(int i = 0; i < n - 1; i++) {
        int qm = m;
        if (i == 0) qm = 1;
        for(int q = 0; q < m; q++) nxt[q] = LLONG_MAX;
        ll bcnum = 0;
        for(int tsize = 0; tsize < m; tsize++) {
            cs.clear();
            int ssize = tsize + 1;
            // Get inum
            ll cn = 0;
            bcnum += a[i + 1][tsize];
            cn = bcnum;
            // Fill cs
            ll off = 0;
            for(int q = 0; q < m; q++) {
                // cout << "I " << cn << ' ' << off << endl;
                nums[q] = cn;
                cs.add(cn + off);
                off += k;
                // Next num
                cn += a[i + 1][(q + ssize) % m];
                cn -= a[i + 1][q];
            }
            for(int q = 0; q < qm; q++) {
                nxt[(q + tsize) % m] = min(
                    nxt[(q + tsize) % m],
                    cs.max() + pre[q]
                );
                cs.remove(nums[q]);
                cs.add(nums[q] + k * m);
                cs.addToAll(-k);
            }
        }
        swap(nxt, pre);
    }
    cout << pre[m - 1] << endl;
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