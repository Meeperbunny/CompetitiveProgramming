#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int fac(int n) {
    int r = 1;
    for(int i = 1; i <= n; ++i) {
        r *= i;
    } return r;
}

void TC() {
    ll n, d;
    cin >> n >> d;
    set<int> isgood;

    isgood.insert(1);
    if (n >= 3 || (n * d) % 3 == 0) isgood.insert(3);
    if (d == 5) isgood.insert(5);
    if (n >= 6 || (fac(n) * d) % 9 == 0) isgood.insert(9);
    if (n >= 6 || (fac(n) * d) % 9 == 0) isgood.insert(9);

    if (n >= 3 || d == 7) {
        isgood.insert(7);
    }
    
    for(auto e : isgood) {
        cout << e << ' ';
    }
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