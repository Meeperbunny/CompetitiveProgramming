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

vector<int> bounded(1000001);
map<pair<int, int>, int> cache;
int solve(int i, int k) {
    auto it = cache.find({i, k});
    if (it == cache.end()) {
        int ans = 0;
        if (i == k || k == 1) ans = 1;
        else {
            int bb = bounded[i];
            if (bb <= 2) {
                ans = 1;
            }
            else {
                // Check if in center
                int half = bb / 2;
                if (i - k < half && k <= half) {
                    ans = 0;
                }
                else if (i - k < half) {
                    ans = solve(i - half, k - half);
                }
                else {
                    ans = solve(i - half, k);
                }
            }
        }
        it = cache.insert({{i, k}, ans}).first;
    }
    return it->second;
}

void TC() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cout << k * solve(n, i) << ' ';
    } cout << endl;
}

int main() {
    int nxt = 1;
    for(int i = 0; i < 1000001; i++) {
        bounded[i] = nxt;
        if (i == nxt) nxt = nxt * 2;
    }
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}