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
}

int main() {
    while(true) {
        ll n; 
        cin >> n;
        if (n == -1) return 0;
        ll la = 0;
        ll t = 0;
        for(int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            t += a * (b - la);
            la = b;
        }
        cout << t << " miles" << endl;
    }
}