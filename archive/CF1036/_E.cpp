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
    // IF sum is odd or split is IN an edge element, is bad.
    // Try to get split between elements
    // Sub more from the left and the central
    // Diff / 2 -> value on the middle, the just sub as much from the sides
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    ll L = 0, R = n - 1;
    ll ls = a[0], rs = a[n - 1];
    while(L + 1 != R) {
        if (ls < rs) {
            ls += a[++L];
        }
        else {
            rs += a[--R];
        }
    }
    if ((ls + rs) & 1) {
        cout << -1 << endl;
        return;
    }
    ll diff = abs(ls - rs);
    ll ta = diff / 2;
    if (ls == rs) {
        cout << 1 << '\n';
        for(auto e : a) cout << e << ' ';
        cout << endl;
        return;
    }
    if (ls > rs) {
        vector<ll> tp(n);
        vector<ll> A(a);
        tp[L] = ta;
        ll left = ta;
        for(int q = L - 1; q >= 0; q--) {
            ll tsub = min(left, A[q]);
            tp[q] = tsub;
            left -= tsub;
        }
        if (left) {
            cout << -1 << endl;
            return;
        }
        cout << 2 << '\n';
        for(int i = 0; i < n; i++) {
            cout << tp[i] << ' ';
        } cout << '\n';
        for(int i = 0; i < n; i++) {
            cout << A[i] - tp[i] << ' ';
        } cout << '\n';
        return;
    }
    else {
        vector<ll> tp(n);
        vector<ll> A(a);
        tp[R] = ta;
        ll left = ta;
        for(int q = R + 1; q < n; q++) {
            ll tsub = min(left, A[q]);
            tp[q] = tsub;
            left -= tsub;
        }
        if (left) {
            cout << -1 << endl;
            return;
        }
        cout << 2 << '\n';
        for(int i = 0; i < n; i++) {
            cout << tp[i] << ' ';
        } cout << '\n';
        for(int i = 0; i < n; i++) {
            cout << A[i] - tp[i] << ' ';
        } cout << '\n';
        return;
    }


}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
}