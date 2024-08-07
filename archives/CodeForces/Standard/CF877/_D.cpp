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

#include <iostream>
#include <vector>
using namespace std;

void TC() {
    LL N, Q;
    cin >> N >> Q;
    string s; cin >> s;
    set<LL> isBad, dbL, dbR;
    FOR(i, N) {
        if (s[i] == '(' && i % 2 == 1) isBad.insert(i);
        if (s[i] == ')' && i % 2 == 0) isBad.insert(i);
        if (i >= 1) if (s[i - 1] == '(' && s[i] == '(') dbL.insert(i);
        if (i <= N - 2) if (s[i + 1] == ')' && s[i] == ')') dbR.insert(i);
    }
    FOR(q, Q) {
        LL ind; cin >> ind; ind--;
        // Update shit
        if (N % 2 == 1) {
            cout << "NO" << endl;
            continue;
        }
        // Upd
        if (dbL.count(ind)) {
            dbL.erase(ind);
        }
        if (dbL.count(ind + 1)) {
            dbL.erase(ind + 1);
        }
        if (dbR.count(ind - 1)) {
            dbR.erase(ind - 1);
        }
        if (dbR.count(ind)) {
            dbR.erase(ind);
        }
        s[ind] = s[ind] == '(' ? ')' : '(';
        // Check if has created new dbls
        if (s[ind] == '(') {
            if (ind > 0 && s[ind - 1] == '(') dbL.insert(ind);
            if (ind < N - 1 && s[ind + 1] == '(') dbL.insert(ind + 1);
        }
        if (s[ind] == ')') {
            if (ind > 0 && s[ind - 1] == ')') dbR.insert(ind - 1);
            if (ind < N - 1 && s[ind + 1] == ')') dbR.insert(ind);
        }
        
        // If in bad, then remove
        // Else add to bad
        if (isBad.count(ind)){ 
            isBad.erase(ind);
        }
        else {
            isBad.insert(ind);
        }
        // dbg(s);
        // dbg("isBad");
        // for(auto e : isBad) cout << e << ' ';
        // cout << endl;
        // dbg("DBL");
        // for(auto e : dbL) cout << e << ' ';
        // cout << endl;
        // dbg("DBR");
        // for(auto e : dbR) cout << e << ' ';
        // cout << endl;

        // Check
        if (isBad.empty() || ((dbL.size() && dbR.size()) && *dbL.begin() <= *isBad.begin() && *isBad.rbegin() <= *dbR.rbegin())) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
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