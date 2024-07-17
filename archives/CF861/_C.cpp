#include <bits/stdc++.h>
using namespace std;
// #define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);freopen("file.out", "w+", stdout);};
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
typedef long long LL;
typedef std::pair<LL, LL> LP;
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
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

LL rep(LL n) {
    if (n == 0) return  0ll;
    if (n == 1) return  1ll;
    if (n == 2) return  11ll;
    if (n == 3) return  111ll;
    if (n == 4) return  1111ll;
    if (n == 5) return  11111ll;
    if (n == 6) return  111111ll;
    if (n == 7) return  1111111ll;
    if (n == 8) return  11111111ll;
    if (n == 9) return  111111111ll;
    if (n == 10) return 1111111111ll;
    if (n == 11) return 11111111111ll;
    if (n == 12) return 111111111111ll;
    if (n == 13) return 1111111111111ll;
    if (n == 14) return 11111111111111ll;
    if (n == 15) return 111111111111111ll;
    if (n == 16) return 1111111111111111ll;
    if (n == 17) return 11111111111111111ll;
    if (n == 18) return 111111111111111111ll;
}

void TC() {
    LL L, R;
    cin >> L >> R;
    // Choose starting digit
    LL upP = 10;
    LL tn = -1;
    LL maxl = LLONG_MAX;
    for(LL i = 1; i <= 18; i++) {
        for(LL bm = 0; bm <= 9; bm++) {
            for(LL tm = 0; tm <= 9; tm++) {
                LL theNum = (upP / 10) * bm + rep(i - 1) * tm;
                // cout << theNum << endl;
                if (theNum < L) {
                    LL t = theNum;
                    if (bm == 0) {
                        theNum = L / (upP / 10);
                        theNum *= (upP / 10);
                    }
                    else {
                        theNum = L / (upP);
                        theNum *= (upP);
                    }
                    theNum += t;
                }
                if (theNum < L) {
                    theNum = L;
                }
                if (theNum > R) theNum = R;
                char mi = CHAR_MAX, ma = CHAR_MIN;
                for(auto c : to_string(theNum)) {
                    ckmin(mi, c);
                    ckmax(ma, c);
                }
                if (ma - mi < maxl) {
                    maxl = ma - mi;
                    tn = theNum;
                }
            }
        }
        upP *= 10;
    }
    cout << tn << endl;
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