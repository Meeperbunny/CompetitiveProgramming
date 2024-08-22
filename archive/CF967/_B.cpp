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
    int n; cin >> n;
    if (n & 1) {
        vector<int> a(n);
        for(int i = 0; i <= n / 2; i++) {
            a[i] = i * 2 + 1;
        }
        int q = n - 1;
        for(int i = n / 2 + 1; i < n; i++, q -= 2) {
            a[i] = q;
        }
        for(int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << endl;
    }
    else {
        cout << -1 << endl;
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