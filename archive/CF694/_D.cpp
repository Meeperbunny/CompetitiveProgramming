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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> marked(n, 0);
    vector<int> cnt(n, 0);
    queue<int> Q;
    Q.push(0);
    marked[0] = 1;
    for(auto e : adj[0]) {
        cnt[e]++;
    }
    while(Q.size()) {
        int curr = Q.front();
        for(auto e : adj[curr]) {
            if (!marked[e] && marked[curr] == 1) {
                marked[e] = 2;
                Q.push(e);
            }
            else if (!marked[e] && marked[curr] == 2 && cnt[e] == 0) {
                marked[e] = 1;
                for(auto el : adj[e]) {
                    cnt[el]++;
                }
                Q.push(e);
            }
            else if (!marked[e] && cnt[e]) {
                marked[e] = 2;
                Q.push(e);
            }
        }
        Q.pop();
    }
    // for(int i = 0; i < marked.size(); i++) cout << marked[i] << ' ';
    // cout << endl;
    if (count(all(marked), 0)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> inset;
    for(int i = 0; i < marked.size(); i++) {
        if (marked[i] == 1) inset.push_back(i + 1);
    }
    cout << inset.size() << endl;
    for(auto e : inset) cout << e << ' ';
    cout << endl;
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