#include <bits/stdc++.h>
using namespace std;
// #define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);freopen("file.out", "w+", stdout);};
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
typedef long long LL;
typedef std::pair<LL, LL> LP;
using vl = vector<LL>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
#define FOR(a, b) for(LL a = 0; a < b; a++)
#define GETV(_a) FOR(_it, _a.size()) cin >> _a[_it]; 
template <class T>
void sort(vector<T>& A) { sort(A.begin(), A.end()); }
template <class T>
void PV(vector<T>& A, string delim = " ", string end = "\n") { for (LL _i = 0; _i < A.size(); _i++) { cout << A[_i] << delim; } cout << end; }
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

using pii = LP;
vector<LL> dijkstra(LL curr, const vector<vector<pii>>& adj) {
    LL n = adj.size();
    vector<LL> distance(n, LLONG_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distance[curr] = 0;
    pq.push({0, curr});

    while (!pq.empty()) {
        LL dist = pq.top().first;
        LL u = pq.top().second;
        pq.pop();

        if (dist > distance[u]) continue;

        for (const pii& neighbor : adj[u]) {
            LL v = neighbor.first;
            LL weight = neighbor.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

void TC() {
    LL N, M;
    cin >> N >> M;
    vl A(N);
    GETV(A);
    vector<vector<LP>> adj(N);
    FOR(i, M) {
        LL a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, A[a] + A[b] + 2 * c});
        adj[b].push_back({a, A[a] + A[b] + 2 * c});
    }
    vector<LL> dist = dijkstra(0, adj);
    FOR(i, N) {
        dist[i] += A[0];
        dist[i] += A[i];
    }
    for(LL i = 1; i < N; i++) {
        cout << dist[i] / 2 << ' ';
    } cout << endl;
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