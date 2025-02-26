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
    int n, x;
    cin >> n >> x;
    int lcon = 0;
    for(int i = 0; i < 31; i++) {
        if ((x >> i) & 1) lcon++;
        else break;
    }
    int maxMex = (1 << lcon);
    vector<int> a(n);
    int q = 0;
    if (n < maxMex) {
        for(int i = 0; i < n; i++) {
            q |= i;
            a[i] = i;
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            a[i] = min(i, maxMex - 1);
            q |= a[i];
        }
    }
    if (q != x) {
        a.back() = x;
    }
    for(auto e : a) cout << e << ' ';
    cout << endl;
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