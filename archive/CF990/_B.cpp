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
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    vector<int> ans;
    multiset<int> an(all(a));
    multiset<int> b;
    int minb = INT_MAX;
    for(int i = 0; i < n; i++) {
        if (a[i] <= minb && a[i] <= *an.begin()) {
            // needs to be pushed
            an.erase(an.find(a[i]));
            ans.push_back(a[i]);
        }
        else {
            // needs to be pushed
            an.erase(an.find(a[i]));
            b.insert(a[i] + 1);
        }
        // While backlog is valid place it
        while((an.empty() && b.size()) || (b.size() && *b.begin() <= *an.begin())) {
            minb = min(minb, *b.begin());
            ans.push_back(*b.begin());
            b.erase(b.begin());
        }
    }
    for(auto e: ans) cout << e << ' ';
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