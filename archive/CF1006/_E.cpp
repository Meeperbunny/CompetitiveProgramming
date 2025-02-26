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
    // Two is one
    vector<int> tri(501);
    for(int i = 1; i <= 500; i++) {
        tri[i] = (i * i - i) / 2;
    }
    int k; cin >> k;
    int tt = 0;
    vector<int> a;
    for(int i = 500; i >= 1; i--) {
        while(tt + i <= 500 && k && tri[i] <= k) {
            // cout << "T " << tri[i] << ' ' << i << endl;
            k -= tri[i];
            a.push_back(i);
            tt += i;
        }
    }
    int x = 0;
    int y = 0;
    vector<pair<int, int>> pairs;
    for(int i = 0; i < a.size(); i++) {
        for(int q = 0; q < a[i]; q++) {
            pairs.push_back({x, y + q});
        }
        y += 500;
        x += 500;
    }
    cout << pairs.size() << endl;
    for(auto e : pairs) cout << e.first << ' ' << e.second << '\n';
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