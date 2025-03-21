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

void add(string &s) {
    int carry = 1;
    for(int i = s.size() - 1; i >= 0; i--) {
        int curr = s[i] == '1';
        s[i] = ((curr + carry) & 1) + '0';
        carry = (curr + carry) >> 1;
        if (!carry) break;
    }
    if (carry) {
        s = "1" + s;
    }
}

void shiftRight(string &s) {
    s.pop_back();
}

bool isEven(string &s) {
    return s.back() == '0';
}

bool isOne(string &s) {
    return s.size() == 1 && s[0] == '1';
}

void TC() {
    int n; cin >> n;
    string s; cin >> s;
    string k;
    bool areEqual = true;
    mint pOnS = 1, pOnK = 0;
    mint EV = 0;
    bool hassplit = false;
    while(s.size() || k.size()) {
        // cout << s << ' ' << k << ' ' << EV << ' ' << pOnS << ' ' << pOnK << endl;
        // If one is one, then one is either one or two. Check for both
        if (isOne(s) || (hassplit && isOne(k))) {
            if (!isOne(s)) {
                swap(s, k);
                swap(pOnS, pOnK);
            }
            if (!hassplit) { // If hasnt split, then print ev
                cout << EV << endl;
                return;
            }
            else {
                // K is two:
                EV += pOnK;
                cout << EV << endl;
                return;
            }
        }
        // If both even
        if (!hassplit) {
            if (isEven(s)) {
                EV += pOnS;
                shiftRight(s);
            }
            else if (!isEven(s)) {
                // If not even, then we split into two.
                pOnS /= 2;
                pOnK = pOnS;
                EV += pOnS + pOnK;

                k = s;
                shiftRight(s);
                shiftRight(k);
                add(k);
                hassplit = true;
            }
        }
        else {
            // One is even and the other is odd.
            // Even will produce two of the same, odd will be split into two.
            if (isEven(k)) {
                swap(s, k);
                swap(pOnS, pOnK);
            } // S is even
            // cout << s << ' ' << k << endl;
            // s will go into s.
            // k will half the time go into s and the other half go into k
            EV += pOnK + pOnS;
            pOnS = pOnS + pOnK / 2;
            pOnK /= 2;

            shiftRight(s);
            shiftRight(k);
            if (isEven(s) == isEven(k)) {
                add(k);
            }
        }
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