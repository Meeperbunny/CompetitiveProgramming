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
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    // Can only be 1 zero. If zero on left, then is good.
    // otherwise if on right check.
    int zc = count(all(a), 0);
    if (!zc) {
        cout << n << endl;
        return;
    }
    bool hz = false;
    if (a[0] == 0) {
        cout << n - zc + 1 << endl;
        return;
    }
    vector<int> nz;
    bool uz = false;
    for(auto e : a) {
        if (!uz && !e) {
            uz=true;
            nz.push_back(e);
        }
        if (e) nz.push_back(e);
    }
    // Go from left and keep mex.
    map<int, int> ma; //ls, rs (inc).
    bool w = true;
    // for(auto e : nz) cout << e << ' ';
    // cout << endl;
    for(int i = nz.size() - 1; i >= 1; i--) {
        int c = nz[i];
        auto it = ma.upper_bound(c);
        if (it == ma.begin()) {
            ma[c] = c;
        }
        else {
            it = prev(it);
            if (it->second == c - 1) {
                it->second = c;
            }
            else if (it->second < c - 1) {
                ma[c] = c;
            }
            else {
                // eaten
            }
        }
        int mex = 0;
        while(ma.size() >= 2) {
            auto f = ma.begin()->second;
            auto s = next(ma.begin())->first;
            if (f + 1 == s) {
                ma.begin()->second = next(ma.begin())->second;
                ma.erase(next(ma.begin()));
            } else break;
        }
        // for(auto e : ma) cout << '\t' << e.first << ' ' << e.second << endl;
        // cout << i << ' ' << nz[i - 1] << ' ' << mex << endl;
        if (ma.begin()->first == 0) {
            mex = ma.begin()->second + 1;
        }
        if (nz[i - 1] >= mex) {
            // 
        }
        else {
            w = false;
            break;
        }
    }
    if (w) {
        cout << nz.size() << endl;
    }
    else {
        cout << nz.size() - 1 << endl;
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