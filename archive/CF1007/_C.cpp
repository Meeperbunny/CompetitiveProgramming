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
    int n, st, en;
    cin >> n >> st >> en;
    st--, en--;
    vector<int> branch(n, -1);
    vector<int> p(n);
    vector<vector<int>> branches(n+1);
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> Q;
    Q.push(st);
    int cc = 0;
    branch[st] = cc++;
    while(Q.size()) {
        int c = Q.front();
        Q.pop();
        branches[branch[c]].push_back(c);
        for(auto e : adj[c]) {
            if (branch[e] == -1) {
                Q.push(e);
                if (c == st) {
                    branch[e] = cc++;
                }
                else {
                    branch[e] = branch[c];
                }
            }
        }
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    int cp = 1;
    int kingbranch = branch[en];
    if (st == en) kingbranch = -1;
    for(int i = 1; i <= n; i++) {
        auto &v = branches[i];
        if (i == kingbranch) continue;
        int bc = branches[i].size();
        for(int q = 0; q < bc; q++) {
            p[branches[i][branches[i].size() - q - 1]] = cp++;
        }
    }
    p[st] = cp++;
    if (kingbranch != -1) {
        int id = -1;
        for(int i = 0; i < branches[kingbranch].size(); i++) {
            if (branches[kingbranch][i] == en) {
                id = i;
                break;
            }
        }
        for(int i = branches[kingbranch].size() - 1; i > id; i--) {
            p[branches[kingbranch][i]] = cp++;
        }
        for(int i = 0; i < id; i++) {
            p[branches[kingbranch][i]] = cp++;
        }
        p[en] = cp++;
    }
    for(auto e : p) cout << e << ' '; cout << endl;
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