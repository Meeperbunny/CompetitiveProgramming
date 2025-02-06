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
    vector<vector<ll>> a(n, vector<ll>(n));
    vector<ll> onechain(n, 0);
    vector<ll> chains(n + 1, 0);
    for(int i = 0; i < n; ++i) for(int q = 0; q < n; q++) {
        cin >> a[i][q];
    }
    for(int i = 0; i < n; i++) {
        for(int q = n - 1; q >= 0; --q) {
            if (a[i][q] == 1) {
                onechain[i]++;
            } else break;
        }
    }
    for(auto e : onechain) {
        chains[e]++;
    }
    for(int q = n - 1; q >= 0; --q) {
        chains[q] += chains[q + 1];
    }
    int mans = chains[0];
    int cans = chains[0];
    // for(auto e : chains) cout << e << ' ';
    // cout << endl;
    for(int i = 1; i < n; i++) {
        if (chains[i] + i < mans) {
            int d = mans - (chains[i] + i);
            mans -= d;
            cans -= d;
        }
        cans--;
        if (cans <= 0) {
            cout << mans << endl;
            return;
        }
    }
    cout << mans << endl;
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