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

int n, m;
ll t0, t1, t2;
ll dp[200001][3];

bool canmakeit(ll startime, vector<vector<pair<ll, pair<ll, ll>>>> &adj) {
    // cout << "STARTING" << ' ' << startime << endl;
    for(int i = 0; i <= n; i++) {
        dp[i][0] = LLONG_MAX;
        dp[i][1] = LLONG_MAX;
        dp[i][2] = LLONG_MAX;
    }
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> Q;
    Q.push({startime, 0, 0});
    if (t1 <= startime && startime <= t2)
        Q.push({startime, 0, 1});
    Q.push({max(t2, startime), 0, 2});
    while(Q.size()) {
        tuple<ll, ll, ll> to = Q.top();
        ll time = get<0>(to), ind = get<1>(to), madecall = get<2>(to);
        Q.pop();
        // dbg(time, ind, madecall);
        if (time >= dp[ind][madecall]) continue;
        // Otherwise, this is new best time.
        dp[ind][madecall] = time;
        // dbg("\tUPDAING");
        // Go to other stations. If you havent made the call include making the call.
        // Only push if new time is better than old time.
        // dbg(time, ind, madecall);
        for(auto &e : adj[ind]) {
            ll next = e.first;
            ll bus = e.second.first;
            ll walking = e.second.second;
            if (madecall == 0) {
                // Push not making call
                ll newtime = time + bus;
                if (newtime < dp[next][0]) {
                    // dbg(newtime, ind, next);
                    Q.push({newtime, next, 0});
                    // dbg("A");
                }
                // Walk and make the call
                if (t1 >= time) {
                    newtime = time + walking;
                    if (newtime >= t1) {
                        if (newtime >= t2) {
                            if (newtime < dp[next][2]) {
                                Q.push({newtime, next, 2});
                                // dbg("B");
                            }
                        }
                        else {
                            if (newtime < dp[next][1]) {
                                Q.push({newtime, next, 1});
                            }
                        }
                    }
                }
                if (time <= t1) {
                    newtime = t2;
                    if (newtime < dp[ind][2]) {
                        Q.push({newtime, ind, 2});
                    }
                }
            }
            else if (madecall == 1) {
                ll newtime = time + walking;
                if (newtime >= t2) {
                    if (newtime < dp[next][2]) {
                        Q.push({newtime, next, 2});
                    }
                }
                else {
                    if (newtime < dp[next][1]) {
                        Q.push({newtime, next, 1});
                    }
                }
                newtime = t2;
                if (newtime < dp[ind][2]) {
                    Q.push({newtime, ind, 2});
                }
            }
            else if (madecall == 2) {
                ll newtime = time + bus;
                if (newtime < dp[next][2]) {
                    Q.push({newtime, next, 2});
                }
            }
        }
    }
    return dp[n - 1][2] <= t0;
}

void TC() {
    cin >> n >> m;
    cin >> t0 >> t1 >> t2;
    vector<vector<pair<ll, pair<ll, ll>>>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ll a, b;
        cin >> a >> b;
        adj[u].push_back({v, {a, b}});
        adj[v].push_back({u, {a, b}});
    }
    ll k = -1;
    for(ll j = t0 + 1; j >= 1; j >>= 1) {
        while(canmakeit(k + j, adj)) {
            k += j;
        }
    }
    cout << k << endl;
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