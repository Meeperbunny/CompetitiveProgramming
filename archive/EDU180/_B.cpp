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
    vector<int> b(n);
    for(auto &e : b) cin >> e;
    for(int i = 0; i < n - 1; i++) {
        int aa = b[i];
        int bb = b[i + 1];
        if (abs(aa - bb) <= 1) {
            cout << 0 << endl;
            return;
        }
    }
    bool dir = b[1] > b[0]; // 1 is up
    for(int i = 0; i < n - 1; i++) {
        int aa = b[i];
        int bb = b[i + 1];
        if ((aa < bb) ^ (dir)) {
            cout << 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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