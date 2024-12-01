#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n, m, L;
    cin >> n >> m >> L;
    multiset<int> pu;
    vector<pair<int, int>> b(n);
    for(int i = 0; i < n; i++) cin >> b[i].first >> b[i].second;
    int rb = 1;
    vector<pair<int, int>> p(m);
    for(int i = 0; i < m; i++) cin >> p[i].first >> p[i].second;
    sort(all(p));
    int cc = 0;
    int jp = 1;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        auto e = b[i];
        rb = e.first - 1;
        while(cc != m && p[cc].first <= rb) {
            pu.insert(p[cc].second);
            cc++;
        }
        int needed = e.second - e.first + 2;
        while(jp < needed) {
            if (!pu.size()) {
                cout << -1 << endl;
                return;
            }
            else {
                cnt += 1;
                jp += *pu.rbegin();
                pu.erase(prev(pu.end()));
            }
        }
    }
    cout << cnt << endl;
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