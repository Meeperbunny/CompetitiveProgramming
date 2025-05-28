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

int turns(int i) {
    int c = 0;
    while(i != 1) {
        c++;
        i = (i + 1) / 2;
    }
    return c;
}

void TC() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    ll nn = min(a, n - a + 1);
    ll mm = min(b, m - b + 1);
    if (turns(n) - turns(nn) > turns(m) - turns(mm)) {
        n = nn;
    }
    else {
        m = mm;
    }
    // cout << n << ' ' << m << ' ' << turns(n) << ' ' << turns(m) << endl;
    cout << 1 + turns(n) + turns(m) << endl;


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