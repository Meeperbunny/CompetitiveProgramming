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

LP dfs(LL c, LL l, vvl &adj, vl &a) {
    LP cp = {a[c], 0};
    for(auto e : adj[c]) {
        if (e != l) {
            LP res = dfs(e, c, adj, a);
            cp.first += res.second;
            cp.second += res.first;
        }
    }
    return cp;
}

void TC() {
    LL N; cin >> N;
    vl A(N);
    GETV(A);
    vvl adj(N);
    FOR(i, N - 1) {
        LL a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (N == 1) {
        cout << A[0] << endl;
        return;
    }
    LP p = dfs(0, -1, adj, A);
    cout << max(p.first, p.second) + 2 * min(p.first, p.second) << endl; 
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