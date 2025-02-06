#include <bits/stdc++.h>
using namespace std;
// #define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);freopen("file.out", "w+", stdout);};
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
typedef long long LL;
typedef std::pair<LL, LL> LP;
const LL MOD = 1e9 + 7;
const LL MOD9 = 998244353;
using vl = vector<LL>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
#define FOR(a, b) for(LL a = 0; a < b; a++)
#define GETV(_a) FOR(_it, _a.size()) cin >> _a[_it]; 
template <class T>
void sort(vector<T>& A) { sort(A.begin(), A.end()); }
template <class T>
void PV(vector<T>& A, string delim = " ", string end = "\n") { for (LL _i = 0; _i < A.size(); _i++) { cout << A[_i] << delim; } cout << end; }
LL modpow(LL a, LL b, LL m) { a %= m; LL r = 1; while (b > 0) { if (b & 1) { r = r * a % m; }a = a * a % m; b >>= 1; }return r; }
LL modinv(LL val, LL mod) { return modpow(val, mod - 2, mod); }
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void TC() {
    LL N, X; cin >> N >> X;
    set<LL> curr;
    vl A(N);
    GETV(A);
    LL cnt = 1;
    FOR(i, N) {
        set<LL> nxt;
        bool b = false;
        for(auto e : curr) {
            if (e * A[i] == X) {
                b = true;
                break;
            }
            else if (e * A[i] < X && X % (e * A[i]) == 0) {
                nxt.insert(e * A[i]);
            }
        }
        if (b) {
            curr.clear();
            curr.insert(A[i]);
            cnt++;
        }
        else {
            if (X % A[i] == 0) {
                nxt.insert(A[i]);
                for(auto e : nxt) {
                    curr.insert(e);
                }
            }
        }
    }
    cout << cnt << endl;
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