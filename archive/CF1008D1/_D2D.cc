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
    vector<pair<ll, ll>> add(n, {0,0});
    vector<pair<ll, ll>> mult(n, {1,1});
    for(int i = 0; i < n; i++) {
        char f, s;
        ll a, b;
        cin >> f >> a >> s >> b;
        if (f == '+') add[i].first = a;
        if (f == 'x') mult[i].first = a;
        if (s == '+') add[i].second = b;
        if (s == 'x') mult[i].second = b;
    }
    vector<pair<ll, ll>> addA(n, {0,0});
    vector<pair<ll, ll>> multA(n, {1,1});
    for(int i = n - 1; i >= 0; i--) {
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    cout << ans[0].first + ans[0].second << endl;
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