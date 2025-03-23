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

int mex(set<int> &s) {
    for(int i = 0; i < s.size(); i++) {
        if (!s.count(i)) return i;
    } return s.size();
}

void TC() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    if (count(all(a), 0) == 0) {
        cout << "1\n1 " << n << '\n';
        return;
    }
    int lmz = n, rmz = -1;
    for(int i = 0; i < n; i++) {
        if (a[i] == 0) {
            lmz = min(lmz, i);
            rmz = max(rmz, i);
        }
    }
    if (lmz == rmz) {
        if (lmz == 0) {
            cout << 2 << '\n';
            cout << 1 << ' ' << 2 << '\n';
            cout << 1 << ' ' << n - 1 << '\n';
        }
        else {
            cout << 2 << '\n';
            cout << 2 << ' ' << n << '\n';
            cout << 1 << ' ' << 2 << '\n';
        }
    }
    else {
        if (lmz == 0 && rmz == n - 1) {
            cout << 3 << '\n';
            cout << 1 << ' ' << 2 << '\n';
            cout << 2 << ' ' << n - 1 << '\n';
            cout << 1 << ' ' << 2 << '\n';
        }
        else {
            int d = rmz - lmz;
            cout << 2 << endl;
            cout << lmz + 1 << ' ' << rmz + 1 << '\n';
            cout << 1 << ' ' << n - d << '\n';
        }
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