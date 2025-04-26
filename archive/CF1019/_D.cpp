#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n; cin >> n;
    vector<pair<int, int>> ops(n);
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++) {
        cin >> ops[i].first;
        ops[i].second = i;
    }
    int lrange = 1;
    int urange = n;
    for(int it = 1; ops.size() != 1; it++) {
        int cit = -1;
        for(int j = 0; j < ops.size(); j++) {
            if (ops[j].first == -1) {
                cit = j;
                break;
            }
        }
        int lc = 0, rc = 0;
        // cout << it << ' ' << cit << endl;
        for(int q = 0; q < ops.size(); q++) {
            if (ops[q].first != it) {
            }
            else {
                if (it & 1) {
                    rc += 1;
                }
                else {
                    lc += 1;
                }
            }
        }
        int lstart = lrange;
        int ustart = urange;
        if (it & 1) {
            ustart -= rc;
            urange = ustart;
        }
        else {
            lstart += lc;
            lrange = lstart;
        }
        // cout << rc << ' ' << lc  << ' ' << lstart << ' ' << ustart << endl;
        vector<pair<int, int>> nc;
        vector<pair<int, int>> left;
        for(int q = cit + 1; q < ops.size(); q++) {
            if (ops[q].first != it) {
                left.push_back(ops[q]);
            }
            else {
                if (it & 1) {
                    ustart++;
                    ans[ops[q].second] = ustart;
                }
                else {
                    lstart--;
                    ans[ops[q].second] = lstart;
                }
            }
        }
        for(int q = cit; q >= 0; q--) {
            if (ops[q].first != it) {
                nc.push_back(ops[q]);
            }
            else {
                if (it & 1) {
                    ustart++;
                    ans[ops[q].second] = ustart;
                }
                else {
                    lstart--;
                    ans[ops[q].second] = lstart;
                }
            }
        }
        reverse(all(nc));
        nc.insert(nc.end(), all(left));
        swap(ops, nc);
        // for(auto e : ans) {
        //     if (e == -1) cout << "#";
        //     else cout << e;
        //     cout << ' ';
        // } cout << endl;
        // if (it == 10) break;
    }
    ans[ops[0].second] = lrange;
    for(auto e : ans) cout << e << ' ';
     cout << endl;
}

/*
3 1 2 1 -1 1 1 2
4 # # #  3 # # #

# 1 # 1  # 1 1 #
# 1 2 1  # 1 1 2



*/

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}