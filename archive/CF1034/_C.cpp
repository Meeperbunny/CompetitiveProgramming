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
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    string s(n, '1');
    vector<int> mi(a);
    vector<int> ma(a);
    for(int i = 1; i < n; i++) {
        mi[i] = min(mi[i], mi[i - 1]);
        ma[n - i - 1] = max(ma[n - i], ma[n - i - 1]);
    }
    for(int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1) continue;
        // cout << i << ' ' << a[i] << ' ' << mi[i] << ' ' << ma[i] << endl;
        s[i] = (mi[i - 1] >= a[i] || ma[i + 1] <= a[i] ? '1' : '0');
    }
    cout << s << endl;
}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
}