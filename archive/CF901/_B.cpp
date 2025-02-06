#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> A(n), B(m);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < m; i++) cin >> B[i];

    ll as = 0, bs = 0;
    ll minA = LLONG_MAX;
    for(int i = 0; i < n; i++) minA = min(minA, A[i]), as += A[i];
    ll maxB = LLONG_MIN;
    for(int i = 0; i < m; i++) maxB = max(maxB, B[i]), bs += B[i];

    ll gmin = minA;
    ll gmax = maxB;
    for(int i = 0; i < m; i++) gmin = min(gmin, B[i]);
    for(int i = 0; i < n; i++) gmax = max(gmax, A[i]);

    if (k >= 1) {
        if (maxB - minA > 0) {
            as += maxB - minA;
        }
    }
    if (k % 2 == 1) {
        cout << as << endl;
    }
    else {
        cout << as + gmin - gmax << endl;
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