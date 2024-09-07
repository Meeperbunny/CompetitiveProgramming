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

void dfs(int c, int l, vector<vector<int>> &adj, map<char, int> &cnts, map<char, int> &extra, string &s) {
    if (adj[c].size() == 1 && l != -1) {
        cnts[s[c]]++;
        return;
    }
    else {
        extra[s[c]]++;
    }
    for(auto e : adj[c]) {
        if (e != l) {
            dfs(e, c, adj, cnts, extra, s);
        }
    }
}

void TC() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    map<char, int> cnts, ex;
    string s; cin >> s;
    dfs(0, -1, adj, cnts, ex, s);
    if (s[0] == '?') ex['?']--;
    dbg(cnts['0'], cnts['1'], cnts['?']);

    int extra = 0;
    if (s[0] == '?') {
        if (cnts['0'] + cnts['1']) {
            int add = int(cnts['?'] / 2);
            cout << max(cnts['0'], cnts['1']) + add << endl;
        }
        else {
            int add = int((cnts['?']) / 2);
            if (ex['?'] & 1) add = int((cnts['?'] + 1) / 2);
            cout << add << endl;
            //
        }
    }
    else {
        int add = int((cnts['?'] + 1) / 2);
        if (ex['?'] & 1) add = int(cnts['?'] / 2);
        cout << (s[0] == '1' ? cnts['0'] : cnts['1']) + add << endl;
    }
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