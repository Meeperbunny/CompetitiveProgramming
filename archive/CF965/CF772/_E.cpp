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

bool isg = true;

void dfs(int c, vector<set<int>> &adj, vector<bool> &checked, stack<int> &stack) {
    if (checked[c]) {
        isg = false;
    }
    if (!isg) return;
    checked[c] = true;
    for(auto e : adj[c]) {
        dfs(e, adj, checked, stack);
    }
    checked[c] = false;
    stack.push(c);
}

void TC() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> parity(n, 0);
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--, c--;
        adj[b].push_back({c, a});
        adj[c].push_back({b, a});
    }
    vector<set<int>> topoadj(n);
    for(int i = 0; i < n; i++) {
        if (!parity[i]) {
            parity[i] = 1;
            queue<int> Q;
            Q.push(i);
            while(Q.size()) {
                int c = Q.front();
                Q.pop();
                for(auto e : adj[c]) {
                    if (!parity[e.first]) {
                        parity[e.first] = -parity[c];
                        Q.push(e.first);
                    }
                    else {
                        if (parity[e.first] != -parity[c]) {
                            cout << "NO" << endl;
                            return;
                        }
                        int mdir = (parity[c] + 1) >> 1;
                        int rdir = e.second;
                        if (mdir ^ rdir) {
                            topoadj[c].insert(e.first);
                        }
                        else {
                            topoadj[e.first].insert(c);
                        }
                    }
                }
            }
        }
    }
    stack<int> s;
    vector<bool> checked(n, false);
    for(int i = 0; i < n; i++) {
        if (!checked[i]) {
            dfs(i, topoadj, checked, s);
        }
    }
    if (!isg) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<string> ans(n);
    int q = 0;
    while(s.size()) {
        ans[s.top()] = (parity[s.top()] == 1 ? "L " : "R ") +  to_string(++q);
        s.pop();
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << endl;
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