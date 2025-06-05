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
    int n, x, y; cin >> n >> x >> y;
    x %= n;
    y %= n;
    vector<int> a(n);
    int c = x;
    int curr = 1;
    for(int i = 0; i < n; i++) {
        if (c == y) {
            if (curr == 1) {
                a[x] = 2;
                a[y] = curr;
                curr = 0;
            }
            else {
                a[y] = curr;
                curr = 1;
            }
        }
        else {
            a[c] = curr;
            if (i == n - 1) {
                if (curr == 1 && a[(c + 1) % n] == 1) {
                    a[c] = 2;
                }
            }
            curr = curr == 0 ? 1 : 0;
        }
        c = (c + 1) % n;
    }
    int i = 1;
    for(auto e : a) {
        cout << a[i] << ' ';
        i = (i + 1) % n;
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