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

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

void TC() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int>  arr(n);
    for(auto &e : arr) cin >> e;
    int ma = -1, mi = INT_MAX;
    for(auto e : arr) {
        ma =  max(ma, e);
        mi =  min(mi, e);
    }
    int g = gcd(a, b);
    for(auto &e : arr) {
        e %= g;
    }
    sort(all(arr));
    int B = arr[n - 1] - arr[0];
    for(int i = 0; i < n - 1; i++) {
        B = min(B, arr[i] + g - arr[i + 1]);
    }
    cout << B << endl;
    
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