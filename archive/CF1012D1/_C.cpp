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

template<const int64_t &MOD>
struct combinatorics {
    using combo_int = _mint<MOD>;

    vector<combo_int> _factorial = {1}, _inv_factorial = {1};

    void prepare_factorials(int64_t maximum) {
        static int64_t prepared_maximum = 0;

        if (maximum <= prepared_maximum)
            return;

        // Prevent increasing prepared_maximum by only 1 each time.
        maximum = max(maximum, int64_t(1.01L * prepared_maximum));
        _factorial.resize(maximum + 1);
        _inv_factorial.resize(maximum + 1);

        for (int64_t i = prepared_maximum + 1; i <= maximum; i++)
            _factorial[i] = i * _factorial[i - 1];

        _inv_factorial[maximum] = _factorial[maximum].inv();

        for (int64_t i = maximum - 1; i > prepared_maximum; i--)
            _inv_factorial[i] = (i + 1) * _inv_factorial[i + 1];

        prepared_maximum = maximum;
    }

    combo_int factorial(int64_t n) {
        if (n < 0) return 0;
        prepare_factorials(n);
        return _factorial[n];
    }

    combo_int inv_factorial(int64_t n) {
        if (n < 0) return 0;
        prepare_factorials(n);
        return _inv_factorial[n];
    }

    combo_int choose(int64_t n, int64_t r) {
        if (r < 0 || r > n) return 0;
        prepare_factorials(n);
        return _factorial[n] * _inv_factorial[r] * _inv_factorial[n - r];
    }

    combo_int permute(int64_t n, int64_t r) {
        if (r < 0 || r > n) return 0;
        prepare_factorials(n);
        return _factorial[n] * _inv_factorial[n - r];
    }

    combo_int inv_choose(int64_t n, int64_t r) {
        assert(0 <= r && r <= n);
        prepare_factorials(n);
        return _inv_factorial[n] * _factorial[r] * _factorial[n - r];
    }

    combo_int inv_permute(int64_t n, int64_t r) {
        assert(0 <= r && r <= n);
        prepare_factorials(n);
        return _inv_factorial[n] * _factorial[n - r];
    }
};

combinatorics<MOD> combo;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        int msb = 0;
        for (int temp = n; temp >>= 1; ++msb);
        for (int i = 1 << msb; i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void TC() {
    int n, l, K;
    cin >> n >> l >> K;
    l += K;
    using T = Fenwick<mint>;
    vector<mint> expec(n, 0);
    vector<vector<Fenwick<mint>>> trees(l + 1, vector<Fenwick<mint>>(K + 2, Fenwick<mint>(n)));
    trees[0][0].add(n - 1, 1);
    // 
    // binom(l, k) -> number of ways to use the k locks
    for(int i = 0; i < l; i++) {
        mint fullsum = 0;
        for(int q = 0; q <= min(i, K); q++) {
            fullsum += combo.choose(i, q);
        }
        // Normalize current row
        for(int k = 0; k <= min(i, K); k++) {
            mint cn = trees[i][k].rangeSum(k, k + 1);
            trees[i][k].add(k, -cn);
            trees[i][k].add(k, cn / fullsum);
        }
        for(int k = 0; k <= min(i, K); k++) {
            auto &ft = trees[i][k];
            auto &sameft = trees[i + 1][k];
            auto &diffft = trees[i + 1][k + 1];
            int tries = (l - i + k);
            mint ts = ft.rangeSum(0, n);
            int fullLoops = tries / n;
            int back = tries % n;
            // Fakes left / total locks left
            mint probNextIsFake = mint(K - k) / mint(l - i);
            mint probNextNotFake = mint(1) - probNextIsFake;
            vector<mint> chances(n);
            mint tt = 0;
            for(int q = 0; q < n; q++) {
                int gb = q - back;
                mint tsum = ft.rangeSum(max(0, gb), q);
                tsum += fullLoops * ts;
                if (gb < 0) {
                    tsum += ft.rangeSum(gb + n, n);
                }
                chances[q] += tsum;
                tt += tsum;
            }
            // Normalize
            for(int q = 0; q < n; q++) {
                chances[q] /= tt;
            }
            for(int q = 0; q < n; q++) {
                expec[q] += chances[q] * probNextNotFake;
                sameft.add(q, chances[q] * probNextNotFake);
            }
            // If it is fake, then just shift it
            for(int q = 0; q < n; q++) {
                int prev = (((q - tries) % n) + n) % n;
                diffft.add(q, ft.rangeSum(prev, prev + 1) * probNextIsFake);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << expec[i] << ' ';
    } cout << endl;
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