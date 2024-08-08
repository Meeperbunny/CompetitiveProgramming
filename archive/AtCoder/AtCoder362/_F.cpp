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

pair<LL, LL> dfs(LL curr, LL last, LL distance, const vector<vector<LL>>& adjList) {
    pair<LL, LL> furthestNode = {curr, distance};

    for (LL neighbor : adjList[curr]) {
        if (neighbor != last) {
            pair<LL, LL> candidate = dfs(neighbor, curr, distance + 1, adjList);

            if (candidate.second > furthestNode.second) {
                furthestNode = candidate;
            }
        }
    }

    return furthestNode;
}

void TC() {
    LL N; cin >> N;
    vvl adj(N);
    FOR(i, N - 1) {
        LL a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    LL snode = -1;
    FOR(i, N) if (adj[i].size() == 1) snode = i;
    LL otherNode = dfs(snode, -1, 0, adj).first;
    snode = otherNode;
    otherNode = dfs(snode, -1, 0, adj).first;

    queue<LL> Q1, Q2;
    Q1.push(snode);
    Q2.push(otherNode);
    vb checked(N, false);
    FOR(i, N / 2) {
        LL a = Q1.front(), b = Q2.front();
        Q1.pop(), Q2.pop();
        cout << a + 1 << ' ' << b + 1 << endl;
        for(auto e : adj[a]) {
            if (!checked[e]) {
                Q1.push(e);
                checked[e] = true;
            }
        }
        for(auto e : adj[b]) {
            if (!checked[e]) {
                Q2.push(e);
                checked[e] = true;
            }
        }
    }
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