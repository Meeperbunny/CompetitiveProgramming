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

void TC() {
    int n, qu;
    cin >> n >> qu;
    string s; cin >> s;
    vector<int> Q(qu);
    for(auto &e : Q) cin >> e;
    // Generate the initial. Find out the counts for each query
    map<int, mint> leftSideToRightAnswer;
    int init = 0;

    // Solve the right side first, go from min to max.
    mint innerCount = 0;
    mint edgeCount = 0;
    mint innerInc = 0;
    mint edgeInc = 0;
    mint cc = 0;
    for(ll i = n + init, inc = 0, q = 1; i <= n; i++, q++) {
        inc += ll(q / 2);
        mint C = combo.choose(n, i);
        // cout << i << ' ' << q << ' ' << C << ' ' << inc << endl;
        if (q & 1) {
            innerInc += C * ((q + 1) / 2);
            innerCount += C;
        }
        else {
            edgeInc += C * ((q + 1) / 2);
            edgeCount += C;
        }
        cc += C * inc;
    }
    // cout << "CC " << cc << endl;
    for(ll t = init, inc = 0, q = 1; t >= -n; t--, q++) {
        // Add current count
        ll i = n + t;
        leftSideToRightAnswer[-i] += cc;
        // add in left side ,update ege cnts
        // inner becomes edge, add more to inner
        if (t == -n) break;
        
        // cout << q << " STARTING" << endl;
        
        // cout << "inner: cnt " << innerCount << " inc: " << innerInc << endl;
        // cout << "edge: cnt " << edgeCount << " inc: " << edgeInc << endl;

        // add edge inc and middle inc
        cc += edgeInc + innerInc;

        // For each on edge, increase edgeinc by # on edge
        edgeInc += edgeCount;

        // Swap counts and add to inner
        // add C to middleinc, C gets added to middlecount
        int I = i - 1;
        mint C = C = combo.choose(n, I);
        swap(edgeInc, innerInc);
        swap(innerCount, edgeCount);
        innerCount += C;
        innerInc += C;

        // cout << "CC " << cc << endl;
        
        // cout << "inner: " << innerCount << ' ' << innerInc << endl;
        // cout << "edge: " << edgeCount << ' ' << edgeInc << endl;
    }

    // Get the sequence of sides.

    // for(auto &[k, v] : leftSideToRightAnswer) {
    //     cout << "A " << k << ' ' << v << endl;
    // }

    ll leftside = -count(all(s), '0');
    for(int i = 0; i < qu; i++) {
        // cout << i << ' ';
        int ind = Q[i] - 1;
        if (s[ind] == '0') {
            s[ind] = '1';
            leftside++;
        }
        else if (s[ind] == '1') {
            s[ind] = '0';
            leftside--;
        }
        // Get the total here
        int L = leftside - 1;
        mint ans = leftSideToRightAnswer[L] + leftSideToRightAnswer[-(n+2) - L];
        // cout << "LS " << leftside << ' ' << ans << endl;
        // cout << L << ' ' << -(n+2) - L << endl;
        cout << ans << '\n';
        // cout << L << ' ' << -(n+2) - L << endl;
    }
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