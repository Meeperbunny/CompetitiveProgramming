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

template<const int64_t &MOD>
struct _mint {
    int val;

    _mint(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _mint(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _mint(int v) : _mint(int64_t(v)) {}
    _mint(unsigned v) : _mint(uint64_t(v)) {}

    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    _mint& operator+=(const _mint &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    _mint& operator-=(const _mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
        return unsigned(x % m);
    }

    _mint& operator*=(const _mint &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    _mint& operator/=(const _mint &other) {
        return *this *= other.inv();
    }

    friend _mint operator+(const _mint &a, const _mint &b) { return _mint(a) += b; }
    friend _mint operator-(const _mint &a, const _mint &b) { return _mint(a) -= b; }
    friend _mint operator*(const _mint &a, const _mint &b) { return _mint(a) *= b; }
    friend _mint operator/(const _mint &a, const _mint &b) { return _mint(a) /= b; }

    _mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _mint operator++(int) { _mint before = *this; ++*this; return before; }
    _mint operator--(int) { _mint before = *this; --*this; return before; }

    _mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    friend bool operator==(const _mint &a, const _mint &b) { return a.val == b.val; }
    friend bool operator!=(const _mint &a, const _mint &b) { return a.val != b.val; }
    friend bool operator<(const _mint &a, const _mint &b) { return a.val < b.val; }
    friend bool operator>(const _mint &a, const _mint &b) { return a.val > b.val; }
    friend bool operator<=(const _mint &a, const _mint &b) { return a.val <= b.val; }
    friend bool operator>=(const _mint &a, const _mint &b) { return a.val >= b.val; }

    static const int64_t SAVE_INV = int(1e6) + 5;
    static _mint save_inv[SAVE_INV];

    static void prepare_inv() {
        // Ensures that MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        save_inv[0] = 0;
        save_inv[1] = 1;

        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    _mint inv() const {
        if (save_inv[1] == 0)
            prepare_inv();

        if (val < SAVE_INV)
            return save_inv[val];

        _mint product = 1;
        int v = val;

        do {
            product *= MOD - MOD / v;
            v = MOD % v;
        } while (v >= SAVE_INV);

        return product * save_inv[v];
    }

    _mint pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _mint a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const _mint &m) {
        return os << m.val;
    }
};

template<const int64_t &MOD> _mint<MOD> _mint<MOD>::save_inv[_mint<MOD>::SAVE_INV];

// const int64_t MOD = 998244353;
const int64_t MOD = int64_t(1e9) + 7;
using mint = _mint<MOD>;

int dist(pair<int, int> &a, pair<int, int> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void TC() {
    int n, m, k; cin >> m >> n >> k;
    vector<vector<mint>> arr(n + 1, vector<mint>(m + 1));
    vector<vector<int>> idx(n + 1, vector<int>(m + 1, -1));
    map<int, mint> cc;
    vector<pair<int, int>> a(k + 1);
    for(int i = 0; i < k + 1; i++) {
        cin >> a[i].second >> a[i].first;
    }
    int ans; cin >> ans;
    // cout << "ANS " << ans << ' ';
    
    const vector<pair<int, int>> T = {
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, 0}
    };
    for(auto [x, y] : T) {
        if (a[0].first + x >= 0 && a[0].first + x <= n && a[0].second + y >= 0 && a[0].second + y <= m) {
            if (idx[a[0].first + x][a[0].second + y] == -1) {
                idx[a[0].first + x][a[0].second + y] = INT_MAX;
            }
        }
    }
    arr[a[0].first][a[0].second] = 1;
    for(int i = 0; i < k; i++) {
        auto prev = a[i];
        auto nxt = a[i + 1];
        int dist = abs(prev.first - nxt.first) + abs(prev.second - nxt.second);
        if (dist == 2) {
            // Check if straight
            if (abs(prev.first - nxt.first) == 2 || abs(prev.first - nxt.first) == 0) {
                // cout << "STARTIGN " << endl;
                // Straight. Just add count of last.
                // All paths go through here
                mint mc = arr[prev.first][prev.second];
                arr[nxt.first][nxt.second] += mc;
                const vector<pair<int, int>> T = {
                    {1, 0},
                    {0, -1},
                    {0, 1},
                    {-1, 0}
                };
                for(auto [x, y] : T) {
                    if (nxt.first + x >= 0 && nxt.first + x <= n && nxt.second + y >= 0 && nxt.second + y <= m) {
                        if (idx[nxt.first + x][nxt.second + y] == -1) {
                            idx[nxt.first + x][nxt.second + y] = i;
                        }
                    }
                }
                cc[i] = mc;
                arr[nxt.first][nxt.second] = mc;
            }
            else {
                mint mc = 0;
                if (idx[nxt.first][prev.second] == INT_MAX) {
                    mc += 1;
                }
                else mc += cc[idx[nxt.first][prev.second]];
                if (idx[prev.first][nxt.second] == INT_MAX) {
                    mc += 1;
                }
                else mc += cc[idx[prev.first][nxt.second]];
                const vector<pair<int, int>> T = {
                    {1, 0},
                    {0, -1},
                    {0, 1},
                    {-1, 0}
                };
                for(auto [x, y] : T) {
                    if (nxt.first + x >= 0 && nxt.first + x <= n && nxt.second + y >= 0 && nxt.second + y <= m) {
                        if (idx[nxt.first + x][nxt.second + y] == -1) {
                            idx[nxt.first + x][nxt.second + y] = i;
                        }
                    }
                }
                cc[i] = mc;
                arr[nxt.first][nxt.second] = mc;
                cout << "CNT " << mc << endl;
            }
        }
        else {
            cout << 0 << endl;
            return;
        }
    }
    cout << arr[a[k].first][a[k].second] << endl;
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