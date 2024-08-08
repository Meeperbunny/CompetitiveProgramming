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
    int N;
    cin >> N;
    vector<pair<pair<int, int>, int>> a(N);
    multimap<int, pair<int, int>> arrival;
    vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
        arrival.insert({a[i].first.first, {a[i].first.second, i}});
    }
    sort(a.begin(), a.end());
    int cc = 1;
    while(arrival.size()) {
        auto it = arrival.begin();
        while(it != arrival.end()) {
            int ep = it->second.first;
            int idx = it->second.second;
            arrival.erase(it);
            ans[idx] = cc;
            it = arrival.upper_bound(ep);
        }    
        cc++;
    }
    cout << cc - 1 << endl;
    for(int i = 0; i < N; i++) cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}