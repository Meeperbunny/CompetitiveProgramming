#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);freopen("file.out", "w+", stdout);};
typedef long long LL;
typedef std::pair<LL, LL> LP;
const LL MOD = 1e9 + 7;
const LL MOD9 = 998244353;
using vl = vector<LL>;
using vs = vector<string>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
#define MP make_pair
#define FOR(a, b) for(LL a = 0; a < b; a++)
#define RFOR(a, b) for(LL a = b - 1; a >= 0; a--)
#define SZ(x) (LL)(x).size()
#define pb push_back
#define GETV(_a) FOR(_it, _a.size()) cin >> _a[_it]; 
#define PD cout << string(20, '#') << endl;
#define PN cout << "NO" << endl
#define PY cout << "YES" << endl
#define P(_val) cout << _val << endl;
template <class T>
LL VMIN(vector<T>& A) { T mi = A[0]; FOR(i, SZ(A)) { mi = min(mi, A[i]); } return mi; }
template <class T>
LL VMAX(vector<T>& A) { T ma = A[0]; FOR(i, SZ(A)) { ma = max(ma, A[i]); } return ma; }
template <class T>
void sort(vector<T>& A) { sort(A.begin(), A.end()); }
template <class T>
void PV(vector<T>& A, string delim = " ", string end = "\n") { for (LL _i = 0; _i < SZ(A); _i++) { cout << A[_i] << delim; } cout << end; }
LL gcd(LL a, LL b) { if (b == 0) { return a; }return gcd(b, a % b); }
LL lcm(LL a, LL b) { return a * b / gcd(a, b); }
LL modpow(LL a, LL b, LL m) { a %= m; LL r = 1; while (b > 0) { if (b & 1) { r = r * a % m; }a = a * a % m; b >>= 1; }return r; }
LL modinv(LL val, LL mod) { return modpow(val, mod - 2, mod); }
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}
LL TEST, testcase;
#define DEBUG false
#define ID if (DEBUG)
#define MAXN 100000

void TC() {
    LL N, K; 
    cin >> N >> K;
    vector<LL> dp(N, LLONG_MAX);
    vl H(N);
    GETV(H);
    dp[0] = 0;
    for (LL i = 1; i < N; i++) {
        for (LL k = 1; k <= min(K, i); k++) {
            ckmin(dp[i], dp[i - k] + abs(H[i] - H[i - k]));
        }
            
    }
    cout << dp[N - 1] << endl;
}


int main() {
    HEADER;
    TEST = 1;
    //cin >> TEST;
    for (testcase = 1; testcase <= TEST; testcase++) {
        //cout << "Case #" << testcase << ": ";
        TC();
    }
}