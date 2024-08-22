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

void TC() {
    ll n, m;
    cin >> n >> m;
    ll p1 = 0, p2 = 0;

    ll c = 1;
    for(int i = 0; i < n; i++) {
        p1 += c;
        c += m;
    }
    for(int i = 1; i < m; i++) {
        c += 1;
        p1 += c;
    }
    

    c = 0;
    for(int i = 0; i < m; i++) {
        c += 1;
        p2 += c;
    }
    for(int i = 1; i < n; i++) {
        c += m;
        p2 += c;
    }

    cout << min(p1, p2) << endl;

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