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

pair<int, int> cnts(string &floor) {
    int m = floor.size();
    vector<bool> checked(m);
    int dc = m / 4;
    int sc = m / 2;
    int mic = 0;
    for(int i = 0; i < m; i++) {
        if (i != m - 1) {
            if (dc > 0 && floor[i] == '1' && floor[i + 1] == '1' && !checked[i] && !checked[i + 1]) {
                checked[i] = 1;
                checked[i + 1] = 1;
                dc -= 1;
                mic += 1;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        if (sc && !checked[i] && floor[i] == '1') {
            mic += 1;
            checked[i] = 1;
            sc--;
        }
    }
    checked = vector<bool>(m);
    dc = m / 4;
    sc = m / 2;
    int mac = 0;
    for(int i = 0; i < m; i++) {
        if (i != m - 1) {
            if (dc > 0 && ((floor[i] == '0' && floor[i + 1] == '1') || (floor[i] == '1' && floor[i + 1] == '0')) && !checked[i] && !checked[i + 1]) {
                checked[i] = 1;
                checked[i + 1] = 1;
                dc -= 1;
                mac += 1;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        if (sc && !checked[i] && floor[i] == '1') {
            checked[i] = 1;
            mac += 1;
            sc--;
        }
    }
    int oc = 0;
    for(int i = 0; i < m; i++) {
        if (i != m - 1) {
            if (dc > 0 && ((floor[i] == '1' && floor[i + 1] == '1')) && !checked[i] && !checked[i + 1]) {
                checked[i] = 1;
                checked[i + 1] = 1;
                dc -= 1;
                mac += 1;
            }
        }
    }
    if (dc != 0) {
        checked = vector<bool>(m);
        dc = m / 4;
        sc = m / 2;
        int mc = 0;
        for(int i = 0; i < m - 1; i++) {
            if (!dc) break;
            if (!checked[i] && !checked[i + 1]) {
                if (floor[i] == floor[i + 1] && floor[i] == '0') {
                    checked[i] = 1;
                    checked[i + 1] = 1;
                    dc -= 1;
                }
            }
        }
        for(int i = 0; i < m - 1; i++) {
            if (!dc) break;
            if (!checked[i] && !checked[i + 1]) {
                if (floor[i] != floor[i + 1]) {
                    checked[i] = 1;
                    checked[i + 1] = 1;
                    mc += 1;
                    dc -= 1;
                }
            }
        }
        // cout << mc << endl;
        // for(int i = 0; i < m; i++) {
        //     cout << checked[i];
        // } cout << endl;
        // cout << mc << endl;
        // for(int i = 0; i < m; i++) {
        //     cout << checked[i];
        // } cout << endl;
        for(int i = 0; i < m; i++) {
            if (i < m - 1 && dc && (!checked[i] && !checked[i + 1])) {
                // cout << "D AT " << i << endl;
                checked[i + 1] = 1;
                dc -= 1;
                mc += 1;
                // cout << "ADDING " << endl;
            }
            else if (sc && !checked[i]) {
                // cout << "S AT " << i << endl;
                sc -= 1;
                if (floor[i] == '1') {
                    // cout << "ADDING " << endl;
                    mc += 1;
                }
            }
        }
        return {mic, mc};
    }
    return {mic, mac};
}

void TC() {
    // int n, m;
    // cin >> n >> m;
    // vector<string> floors(n);
    // for(auto &e : floors) cin >> e;
    // int mi = 0, ma = 0;
    // for(auto &e : floors) {
    //     auto [mii, maa] = cnts(e);
    //     mi += mii;
    //     ma += maa;
    // }
    // cout << mi << ' ' << ma << '\n';
    string s;
    int mi, ma;
    cin >> s >> mi >> ma;
    auto p = cnts(s);
    // cout << mi << ' ' << ma << ' ' << p.first << ' ' << p.second << endl;
    if (p.first != mi || p.second != ma) {
        cout << s << " IS WRONG " << mi << ' ' << ma << ' ' << p.first << ' ' << p.second << endl;
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