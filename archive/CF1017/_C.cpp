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
    int n; cin >> n;
    set<int> inc;
    for(int i = 1; i <= 2 * n; i++) {
        inc.insert(i);
    }
    vector<vector<int>> nums(n, vector<int>(n));
    for(auto &e : nums) for(auto &el : e) cin >> el;
    vector<int> a;
    for(int i = 0; i < n - 1; i++) {
        a.push_back(nums[0][i]);
        inc.erase(nums[0][i]);
    }
    for(int i = 0; i < n; i++) {
        a.push_back(nums[i][n - 1]);
        inc.erase(nums[i][n - 1]);
    }
    cout << *inc.begin() << ' ';
    for(auto e : a) cout << e << ' ';
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