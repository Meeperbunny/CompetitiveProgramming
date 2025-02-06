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

void TC() {
    LL N, M;
    cin >> N >> M;
    vvl A(N, vl(M));
    if (N % 2 == 0) {
        LL n = 1;
        FOR(q, M) {
            FOR(i, N) {
                A[i][q] = n++;
            }
        }
    }
    else if (M % 2 == 0) {
        LL n = 1;
        FOR(i, N) {
            FOR(q, M) {
                A[i][q] = n++;
            }
        }
    }
    else {
        LL orows = (M + 1) / 2;
        FOR(i, orows) {
            FOR(q, N) {
                A[q][i] = (M * N) - q - (2 * N * i);
            }
        }
        for(int i = orows; i < M; i++) {
            FOR(q, N) {
                A[N - q - 1][i] = ((M - i - 1) * 2 + 1) * N + 1 + q;
            }
        }
    }
    FOR(i, N) {
        PV(A[i]);
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