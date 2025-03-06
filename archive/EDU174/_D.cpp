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

void TC() {
    string s; cin >> s;
    // int A; cin >> A;
    int n = s.size();
    int m = n / 2;
    int mans = INT_MAX;
    for(int j = 0; j < 2; j++) {
        vector<bool> eq(m);
        vector<vector<int>> pcnts(n + 1, vector<int>(26));
        for(int i = 1; i <= n; i++) {
            for(int q = 0; q < 26; q++) {
                pcnts[i][q] = pcnts[i - 1][q] + int(s[i - 1] == 'a' + q);
            }
        }
        auto rc = [&](int l, int r) -> vector<int> {
            if (l > r) {
                swap(l, r);
            }
            vector<int> c(26);
            for(int i = 0; i < 26; i++) {
                c[i] = pcnts[r + 1][i] - pcnts[l][i];
            }
            return c;
        };
        auto ADD = [](const vector<int> &a, const vector<int> &b) -> vector<int> {
            vector<int> c(26);
            for(int i = 0; i < 26; i++) {
                c[i] = a[i] + b[i];
            }
            return c;
        };
        auto op = [&](int i) -> int {
            return n - i - 1;
        };
        for(int i = 0; i < m; i++) {
            eq[i] = (s[i] == s[op(i)]);
        }
        int sm = m, la = -1;
        for(int i = 0; i < m; i++) {
            if (!eq[i]) {
                sm = min(sm, i);
                la = max(la, i);
            }
        }
        if (sm == m) {
            cout << 0 << endl;
            return;
        }
        int l = sm, r = la;
        if (rc(l, r) == rc(op(l), op(r))) {
            mans = min(mans, r - l + 1);
        }
        int OL = op(m - 1);
        int E = op(l);
        for(int OR = OL; OR < E; OR++) {
            vector<int> tot = ADD(rc(l, OL - 1), rc(OL, OR));
            int tr = OR + 1;
            vector<int> OP = rc(tr, E);
            bool issuper = true;
            for(int i = 0; i < 26; i++) {
                if (tot[i] >= OP[i]) {}
                else issuper = false;
            }
            if (issuper) {
                mans = min(mans, OR - l + 1);
            }
        }
        mans = min(mans, op(l) - l + 1);
        reverse(all(s));
    }
    // if (A != mans) {
    //     cout << "BROKEN " << s << ' ';
    // }
    cout << mans << endl;
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