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
    int n, m;
    cin >> n >> m;
    // vector<pair<int, int>> R(m);
    vector<vector<bool>> R(n + 1, vector<bool>(110));
    while(m--) {
        pair<int, int> e;
        cin >> e.first >> e.second;
        R[e.first][e.second] = 1;
    }
    // There is one empty array
    // cany be any
    // how many of size k can we do?

    // For each position, pick a cyclic. Try it out and see if it hits any restrict
    // If it is good, then add to the len at some ind.
    // Otherwise dont do it
    vector<mint> cnts(n + 1);
    vector<mint> end1(n + 1);
    vector<vector<mint>> added(n + 10, vector<mint>(n + 10));
    cnts[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int s = 1; i + s <= n; s++) {
            for(int r = 1; r <= s; r++) {
                // cout << "RR" << endl;
                // Check if break any restrict
                int pos = i + 1;
                bool isg = true;
                for(int q = r; isg && q <= s; q++, pos++) {
                    if (R[pos][q]) {
                        isg = false;
                    }
                    // cout << "Z1 "<< endl;
                }
                for(int q = 1; isg && q <= r - 1; q++, pos++) {
                    if (R[pos][q]) {
                        isg = false;
                    }
                    // cout << "Z "<< endl;
                }
                if (isg) {
                    // if (s >= 1 && r == 1) {
                    //     int tar = i + s; // tar is good
                    //     // cout << "TAR " << tar << endl;
                    //     for(int k = 2; i - k >= 0; k++) {
                    //         // cout << tar << " sub " << i - k << endl;
                    //         // cout << added[i - k][k] << endl;
                    //         cnts[tar] -= added[i - k][k];
                    //         added[i][k] -= added[i - k][k];
                    //     }
                    //     added[i][s] += cnts[i];
                    // }
                    // cnts[i + s] += cnts[i];
                    if (i == 0) {
                        cnts[i + s] += cnts[i];
                        if (r == 2) {
                            end1[i + s] += cnts[i];
                        }
                    }
                    else {
                        if (s == 1) {
                            cnts[i + s] += cnts[i];
                            if (r == 2) {
                                end1[i + s] += cnts[i];
                            }
                        }
                        else if (r == 1) {
                            // Add end 1 to it
                            cnts[i + s] += end1[i];
                        }
                        else {
                            cnts[i + s] += cnts[i];
                            if (r == 2) {
                                end1[i + s] += cnts[i];
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i <= n; i++) {
        /*
        1: [1]
        2: [1, 1]
           [1, 2]
           [2, 1]
        3:
            [1, 1, 1] 
            [1, 2, 3] G
            [2, 3, 1] G
            [3, 1, 2] G
            [1, {2, 1}] X G
            [2, 1, 1]
            [1, 1, 2] 
            [1, 2, 1] X

            [1, 2, 1]

            [1, 2, 3, 4, 5] [1]
            [1, 2, 3, 4, 5] [1, 2]
            [......] [1, 2] [1]
            [...] [1, 2, 3] [1, 2]
            [......] [1, 2] [1]
            [] [1, 2, 3, 4] [1, 2] T
           B [1, 2, 3, 4, 5] [1, 2, 3]
           0  1  2  3  4  5   6

           5 1 2 3 4   
           1 2 3 4 5 | 1 2 3
           1 2 3 | 4 5 1 2 3
           1 2 3 4 5 | 1
           1 2 | 1
            
            
            // If i am 1, 2, will get an extra from the cyclic of 5 for 3 back, 3 for 1 back
            // sz + k for k back
            [3, 4, 5, 1, 2]

            For the end can put set of k last elements, (
            if s != 1, subtract from all greater than n
   
0 1
1 1
2 3
3 6

0 1
1 1
2 3
3 8
        */
        // cout << i << ' ' << cnts[i] << endl;
    }
    cout << cnts[n] << endl;

}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
}