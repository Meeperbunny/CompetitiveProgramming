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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> lights(k);
    bool hasend = false;
    for(auto &e : lights) {
        cin >> e.first >> e.second;
        if (e.first == n && e.second == m) hasend = true;
    }
    sort(all(lights));
    // If no end light, then has to get on row / col. Otherwise if is a end light, then operate as normal.
    vector<int> dist(k, INT_MAX);
    dist[0] = 0;
    vector<vector<int>> rowadj(n + 1), coladj(m + 1);

    // Const adj
    for(int i = 0; i < k; i++) {
        for(int q = -2; q <= 2; q++) {
            if (lights[i].first + q >= 1 && lights[i].first + q <= n)
                rowadj[lights[i].first + q].push_back(i);
            if (lights[i].second + q >= 1 && lights[i].second + q <= m)
                coladj[lights[i].second + q].push_back(i);
        }
    }
    set<pair<int, int>> Q;
    vector<bool> in(k, 0);
    in[0] = 1;
    Q.insert({0, 0});
    while(Q.size()) {
        int d = Q.begin()->first;
        int q = Q.begin()->second;
        // dbg(d, q, lights[q].first, lights[q].second);
        Q.erase(Q.begin());
        in[q] = false;
        if (d > dist[q]) continue;
        if (hasend) {
            if (lights[q].first == n && lights[q].second == m) {
                cout << d << endl;
                return;
            }
        }
        else {
            if (lights[q].first == n || lights[q].first == n - 1 || lights[q].second == m || lights[q].second ==  m - 1) {
                cout << d + 1 << endl;
                return;
            }
        }
        int cost = 1;
        for(auto e : rowadj[lights[q].first]) {
            if (e == q) continue;
            int di = cost;
            if (abs(lights[e].first - lights[q].first) + abs(lights[e].second - lights[q].second) <= 1) di = 0;
            int el = e;
            if (dist[el] > d + di) {
                if (!in[el]) {
                    in[el] = 1;
                }
                else {
                    Q.erase(Q.find({dist[el], el}));
                }
                dist[el] = d + di;
                Q.insert({d + di, el});
            }
        }
        for(auto e : coladj[lights[q].second]) {
            if (e == q) continue;
            int di = cost;
            if (abs(lights[e].first - lights[q].first) + abs(lights[e].second - lights[q].second) <= 1) di = 0;
            int el = e;
            if (dist[el] > d + di) {
                if (!in[el]) {
                    in[el] = 1;
                }
                else {
                    Q.erase(Q.find({dist[el], el}));
                }
                dist[el] = d + di;
                Q.insert({d + di, el});
            }
        }
    }
    cout << -1 << endl;
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