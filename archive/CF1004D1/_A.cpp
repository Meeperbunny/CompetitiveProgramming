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
    vector<int> x(n);
    for(auto &e : x) cin >> e;
    set<int> ns(all(x));
    if (ns.size() != n) {
        int mi;
        for(int i = 1; i <= n; i++) if (!ns.count(i)) {
            mi = i;break;
        }
        cout << "? " << (mi == 1 ? 2 : 1) << ' ' << mi << endl;
        int r1, r2;
        cin >> r1;
        cout << "? " << mi << ' ' << (mi == 1 ? 2 : 1) << endl;
        cin >> r2;
        if (r1 == 0 || r2 == 0) {
            cout << "! A" << endl;
        }
        else {
            cout << "! B" << endl;
        }
        return;
    }
    int lw, hi;
    for(int i = 0; i < n; i++) {
        if (x[i] == 1) lw = i + 1;
        if (x[i] == n) hi = i + 1;
    }
    cout << "? " << lw << ' ' << hi << endl;
    int d1; cin >> d1;
    cout << "? " << hi << ' ' << lw << endl;
    int d2; cin >> d2;
    if (d1 == d2 && d1 >= n - 1) {
        cout << "! B" << endl;
    }
    else {
        cout << "! A" << endl;
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