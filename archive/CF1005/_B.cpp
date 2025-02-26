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
    map<int, int> cnts;
    for(auto e : a) cnts[e]++;
    set<int> alone;
    for(auto &[e, c] : cnts) {
        if (c == 1) {
            alone.insert(e);
        }
    }
    int mac = 0;
    int lb = -1, rb = -1;
    int sz = 0;
    for(int i = 0; i < n; i++) {
        if (alone.count(a[i])) {
            sz++;
            if (sz > mac) {
                lb = i - sz + 2, rb = i + 1;
                mac = sz;
            }
        }
        else sz = 0;
    }
    if (lb == -1) {
        cout << 0 << endl;
    }
    else {
        cout << lb << ' ' << rb << endl;
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