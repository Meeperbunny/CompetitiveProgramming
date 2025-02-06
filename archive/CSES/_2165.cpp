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

// (2) [1 to 2] -> (1 to 3 but swap 3 and 2)
// (2) [1 to 3] -> ((1 to 2), (p1 -> p3), (2 to 3))
// (2) [2 to 3] -> (1 to 3 but swap 1 and 2)

// Prev to 2, curr to 3, prev to 3

void TC() {
    LL N; cin >> N;
    vector<vector<LP>> seq(N + 1);
    seq[1] = {{1, 3}};
    for(int i = 2; i <= N; i++) {
        // Prev to 2
        for(auto el : seq[i - 1]) {
            LP c = el;
            if (c.first == 2) c.first = 3;
            else if (c.first == 3) c.first = 2;
            if (c.second == 2) c.second = 3;
            else if (c.second == 3) c.second = 2;
            seq[i].push_back(c);
        }
        seq[i].push_back({1, 3});
        for(auto el : seq[i - 1]) {
            LP c = el;
            if (c.first == 1) c.first = 2;
            else if (c.first == 2) c.first = 1;
            if (c.second == 1) c.second = 2;
            else if (c.second == 2) c.second = 1;
            seq[i].push_back(c);
        }
    }
    cout << seq[N].size() << endl;
    for(auto e : seq[N]) cout << e.first << ' ' << e.second << endl;
}

int main() {
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}