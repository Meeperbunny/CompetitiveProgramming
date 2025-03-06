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
    vector<vector<int>> c(n, vector<int>(m));
    for(auto &v : c) {
        for(auto &e : v) cin >> e;
    }
    map<int, set<pair<int, int>>> lk;
    for(int i = 0; i < n; i++) for(int q = 0; q < m; q++) {
        lk[c[i][q]].insert({i, q});
    }
    vector<int> cnts;
    for(auto &[col, vec] : lk) {
        bool hasn = false;
        for(auto &[y, x] : vec) {
            if (vec.count({y+1, x}) || 
                vec.count({y-1, x}) || 
                vec.count({y, x+1}) || 
                vec.count({y, x-1})) {
                    hasn = true;
                    break;
                }
        }
        if (hasn) {
            cnts.push_back(2);
        }
        else {
            cnts.push_back(1);
        }
    }
    sort(all(cnts));
    cout << accumulate(all(cnts), 0) - cnts.back() << endl;
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