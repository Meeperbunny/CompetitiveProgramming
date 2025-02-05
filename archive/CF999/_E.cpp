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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;

    vector<int> mask(1 << m);
    mask[0] = (1 << 30) - 1;
    for(int i = 1; i < (1 << m); i++) {
        int ind = __builtin_ctz(i);
        mask[i] = mask[i ^ (1 << ind)] & b[ind];
    }
    vector<int> saves;
    saves.reserve(n * m);
    for(int i = 0; i < n; i++) {
        vector<int> va(m + 1);
        for(int q = 0; q < (1 << m); q++) {
            int cc = __builtin_popcount(q);
            va[cc] = max(va[cc], a[i] - (mask[q] & a[i]));
        }
        for(int q = 0; q < m; q++) {
            saves.push_back(va[q + 1] - va[q]);
        }
    }
    nth_element(saves.begin(), saves.end() - k, saves.end());
    cout << accumulate(all(a), 0ll) - accumulate(saves.end() - k, saves.end(), 0ll) << '\n';
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