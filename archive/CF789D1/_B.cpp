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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> ans(n * m);
    // Solve cols
    vector<int> t(m);
    int c = 0;
    for(int i = 0; i < n * m; i++) {
        int ind = i % m;
        if (t[ind] == 0 && s[i] == '1') {
            t[ind] = 1;
            c++;
        }
        ans[i] += c;
    }
    vector<int> r(n * m);
    multiset<char> ss;
    for(int i = 0; i < n * m; i++) {
        ss.insert(s[i]);
        if (i >= m) {
            ss.erase(ss.find(s[i - m]));
        }
        if (ss.count('1')) {
            r[i] = 1;
        }
        else {
            r[i] = 0;
        }
    }
    // for(auto e : r) cout << e << ' '; cout << endl;
    vector<int> ro(m);
    for(int i = 0; i < n * m; i++) {
        int ind = i % m;
        ro[ind] += r[i];
        ans[i] += ro[ind];
        // dbg(i);
        // for(int q = 0; q < m; q++) cout << ro[q] << ' '; cout << endl;
    }

    for(auto e : ans) cout << e << ' ';
    cout << '\n';
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