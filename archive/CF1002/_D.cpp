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

ll n, s1, s2;
inline ll toC(ll a, ll b) {
    return a * n + b;
}

inline pair<ll, ll> fromC(ll a) {
    return {a / n,  a % n};
}

void TC() {
    cin >> n >> s1 >> s2;
    s1--, s2--;
    vector<set<ll>> A(n), B(n);
    ll m1; cin >> m1;
    for(ll i = 0; i < m1; i++) {
        ll a, b;  cin >> a>>b;
        a--;b--;
        A[a].insert(b);
        A[b].insert(a);
    }
    ll m2; cin >> m2;
    for(ll i = 0; i < m2; i++) {
        ll a, b;  cin >> a>>b;
        a--;b--;
        B[a].insert(b);
        B[b].insert(a);
    }
    set<ll> goods;
    for(int i = 0; i < A.size(); ++i) {
        for(auto q : A[i]) {
            if (B[i].find(q) != B[i].end()) {
                goods.insert(toC(i, i));
                goods.insert(toC(q, q));
            }
        }
    }
    // for(auto e : goods) {
    //     cout << fromC(e).first << ' ' << fromC(e).second << endl;
    // }
    vector<vector<pair<ll, ll>>> SA(n * n);
    // Construct super graph
    for(ll i = 0; i < n; ++i) {
        for(ll q = 0; q < n; ++q) {
            // Get all combinations of moving from some i, q, and get the cost.
            ll S = toC(i, q);
            for(auto aa : A[i]) {
                for(auto bb : B[q]) {
                    ll newC = toC(aa, bb);
                    SA[S].push_back({newC, abs(aa - bb)});
                }
            }
        }
    }
    // Djikstra
    ll start = toC(s1, s2);

    vector<ll> result(n * n, LLONG_MAX);
    result[start] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        ll d = pq.top().first, node = pq.top().second;
        pq.pop();
        if (d != result[node])
            continue;
        for (auto &edge : SA[node]) {
            ll new_node = edge.first;
            ll weight = edge.second;
            if (result[new_node] > d + weight) {
                result[new_node] = d + weight;
                pq.push({result[new_node], new_node});
            }
        }
    }

    ll best = LLONG_MAX;
    for(int i = 0; i < n * n; ++i) {
        if (goods.count(i)) {
            best = min(result[i], best);
        }
    }
    cout << (best == LLONG_MAX ? -1 : best) << endl;
    
}

int main() {
    HEADER;
    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++) {
        TC();
    }
    return 0;
}