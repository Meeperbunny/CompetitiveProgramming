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
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
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
 
const int64_t MOD = 998244353;
// const int64_t MOD = int64_t(1e9) + 7;
using mint = _mint<MOD>;
 
struct StringHash {
    const ll incPrime = 29;
    vector<mint> prefixHash;
    string s;
    StringHash(string _s) {
        s = _s;
        prefixHash = vector<mint>(_s.size() + 1);
        prefixHash[0] = 0;
        for(int i = 1; i <= s.size(); i++) {
            prefixHash[i] = prefixHash[i - 1] * mint(incPrime) + mint(s[i - 1] - 'a');
        }
    }
    bool comp(int l1, int r1, int l2, int r2) {
        if (r1 - l1 != r2 - l2) return false;
        if (l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }
        mint h1 = prefixHash[r1 + 1] - prefixHash[l1] * mint(incPrime).pow(r1 - l1 + 1);
        mint h2 = prefixHash[r2 + 1] - prefixHash[l2] * mint(incPrime).pow(r2 - l2 + 1);
 
        return h1 == h2;
    }
};
 