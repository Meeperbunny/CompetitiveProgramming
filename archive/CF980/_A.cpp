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
    vector<pair<int, int>> a(n);
    for(auto &e : a) {
        cin >> e.first >> e.second;
    }
    sort(all(a), [&](pair<int, int> &i, pair<int, int> &j){
        if (min(i.first, i.second) == min(j.first, j.second)) {
            return max(i.first, i.second) < max(j.first, j.second);
        }
        return min(i.first, i.second) < min(j.first, j.second);
    });
    for(auto e : a) {
        cout << e.first << ' ' << e.second << ' ';
    } cout << endl;
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