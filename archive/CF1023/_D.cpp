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

vector<vector<int>> getConnectedComponents(vector<vector<int>> &adj, vector<bool> &dead) {
    const int n = adj.size();
    vector<vector<int>> ret;
    vector<bool> seen(n, false);
    for(int i = 0; i < n; i++) {
        if (!dead[i] && !seen[i]) {
            ret.push_back({});
            queue<int> Q;
            Q.push(i);
            seen[i] = true;
            while(Q.size()) {
                int c = Q.front();
                Q.pop();
                ret.back().push_back(c);
                for(auto e : adj[c]) {
                    if (!dead[e] && !seen[e]) {
                        Q.push(e);
                        seen[e] = true;
                    }
                }
            }
        }
    }
    return ret;
}

int n;
// Returns shortest distances from src to all other vertices
vector<bool> checked;
vector<int> getFurthest(vector<vector<int>> &adj, int src, vector<bool> &dead) {
    assert(!dead[src]);
    vector<int> ret;
    queue<pair<int, int>> Q;
    int bd = -1;
    Q.push({src, 0});
    checked[src] = 1;
    while(Q.size()) {
        auto [node, d]= Q.front();
        Q.pop();
        if (d > bd) {
            ret.clear();
            bd = d;
        }
        if (d == bd) {
            ret.push_back(node);
        }
        for(auto e : adj[node]) {
            if (!dead[e] && !checked[e]) {
                Q.push({e, d + 1});
                checked[e] = 1;
            }
        }
    }
    return ret;
}

vector<int> parent(n, -1);
vector<int> getPath(vector<vector<int>> &adj, int src, int des, vector<bool> &dead) {
    assert(!dead[src]);
    queue<pair<int, int>> Q;
    int bd = -1;
    Q.push({src, 0});
    parent[src] = src;
    while(Q.size()) {
        auto [node, d]= Q.front();
        Q.pop();
        for(auto e : adj[node]) {
            if (!dead[e] && parent[e] == -1) {
                Q.push({e, d + 1});
                checked[e] = 1;
                parent[e] = node;
            }
        }
    }
    vector<int> ret;
    int cn = des;
    while(cn != src) {
        ret.push_back(cn);
        cn = parent[cn];
    }
    ret.push_back(src);
    return ret;
}

void TC() {
    cin >> n;
    vector<vector<int>> adj(n);
    vector<bool> dead(n, false);
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<tuple<int, int, int>> answer;
    while(true) {
        // cout << "GETTING CCS " << endl;
        // GET CCS
        vector<vector<int>> ccl = getConnectedComponents(adj, dead);
        checked = vector<bool>(n, false);
        parent = vector<int>(n, -1);
        // IF NONE LEFT THEN BREAK
        if (ccl.size() == 0) break;
        // cout << "DONE GETTING CCS " << endl;
        // FOR EACH CC FIND DIA BORDERS
        for(auto &cc : ccl) {
            // cout << "Working on CC: ";
            // for(auto e : cc) cout << e << ' '; cout << endl;
            int arbNode = cc[0];
            auto f1 = getFurthest(adj, arbNode, dead);
            for(auto e : cc) checked[e] = 0;
            vector<int> dworthy(f1);
            auto f2 = getFurthest(adj, f1[0], dead);
            for(auto e : cc) checked[e] = 0;
            dworthy.insert(dworthy.end(), all(f2));
            // cout << "DWORTHY ";
            // for(auto e : dworthy) cout << e << ' '; cout << endl;
            // Find the largest el in dworthy
            auto it = max_element(all(dworthy));
            int startNode = *it;
            auto f3 = getFurthest(adj, startNode, dead);
            // cout << "F3 ";
            // for(auto e : f3) cout << e << ' '; cout << endl;
            int endNode = *max_element(all(f3));
            // Find second largest in other
            // KILL THE PATH, ADD IT

            auto path = getPath(adj, startNode, endNode, dead);
            // Add in
            answer.push_back({path.size(), startNode + 1, endNode + 1});
            // Kill my path
            // cout << "Tuple is " << format("[{}, {}, {}]", path.size(), startNode, endNode) << endl;
            // cout << "THE PATH IS ";
            for(auto e : path) {
                // cout << e << ' ';
                dead[e] = 1;
            }
            // cout << endl;
        }
    }
    sort(all(answer), greater<tuple<int, int, int>>());
    for(auto [a, b, c] : answer) {
        cout << a << ' ' << b << ' ' << c << ' ';
    } cout << endl;
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