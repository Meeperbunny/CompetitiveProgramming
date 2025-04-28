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

// https://codeforces.com/blog/entry/57593
int OneCentroid(int root, const vector<vector<int>> &g, const vector<bool> &dead) {
    int k = g.size();
    vector<int> sz(k);
    function<void (int, int)> get_sz = [&](int u, int prev) {
            sz[u] = 1;
            for (auto v : g[u]) if (v != prev && !dead[v]) {
                    get_sz(v, u);
                    sz[u] += sz[v];
            }
    };
    get_sz(root, -1);
    int n = sz[root];
    function<int (int, int)> dfs = [&](int u, int prev) {
            for (auto v : g[u]) if (v != prev && !dead[v]) {
                    if (sz[v] > n / 2) {
                            return dfs(v, u);
                    }
            }
            return u;
    };
    return dfs(root, -1);
}

// https://codeforces.com/blog/entry/57593
vector<int> Centroid(int root, const vector<vector<int>> &g, const vector<bool> &dead) {
    int k = g.size();
    vector<int> sz(k);
    function<void (int, int)> get_sz = [&](int u, int prev) {
            sz[u] = 1;
            for (auto v : g[u]) if (v != prev && !dead[v]) {
                    get_sz(v, u);
                    sz[u] += sz[v];
            }
    };
    get_sz(root, -1);
    int n = sz[root];
    vector<int> centroid;
    function<void (int, int)> dfs = [&](int u, int prev) {
            bool is_centroid = true;
            for (auto v : g[u]) if (v != prev && !dead[v]) {
                    dfs(v, u);
                    if (sz[v] > n / 2) is_centroid = false;
            }
            if (n - sz[u] > n / 2) is_centroid = false;
            if (is_centroid) centroid.push_back(u);
    };
    dfs(root, -1);
    return centroid;
}

void TC() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    int ans; 
    for(int i = 0; i < n - 1; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    
    // Idea: Find centroid of current tree. Pick any adjacent non dead node.
    // Get sum, toggle one, get sum. if +- 4, then root is on the side of the picked node. Otherwise is on
    // Other side. We dfs on the side of the Opposite, killing all nodes. Then we repeat.
    // Once we have root, then we dfs for sums of each.

    vector<bool> dead(n, false);
    while(count(all(dead), false) > 1) {
        // Pick some arb root
        int r = -1;
        for(int i = 0; i < n; i++) {
            if (!dead[i]) {
                r = i;
                break;
            }
        }
        int c = OneCentroid(r, adj, dead);

        // for(auto e : dead) cout << e<< ' ';
        // cout << endl;
        // cout << "Centroid " << c+1 << endl;

        // Pick half of my alive adjacent group to test
        vector<int> toTest, notTest;
        set<int> TT, NT;
        int freq = 1;
        for(auto e : adj[c]) {
            if (!dead[e]) {
                if (freq) {
                    queue<int> tk;
                    tk.push(e);
                    while(tk.size()) {
                        int cc = tk.front();
                        tk.pop();
                        if (cc == c || dead[cc]) continue;
                        if (TT.count(cc)) continue;
                        TT.insert(cc);
                        for(auto Q : adj[cc]) {
                            if (Q != c && !dead[Q] && !TT.count(Q)) tk.push(Q);
                        }
                    }
                }
                else {
                    queue<int> tk;
                    tk.push(e);
                    while(tk.size()) {
                        int cc = tk.front();
                        tk.pop();
                        if (cc == c || dead[cc]) continue;
                        if (NT.count(cc)) continue;
                        NT.insert(cc);
                        for(auto Q : adj[cc]) {
                            if (Q != c && !dead[Q] && !NT.count(Q)) tk.push(Q);
                        }
                    }
                }
                freq = !freq;
            }
        }

        for(auto e : TT) toTest.push_back(e);
        for(auto e : NT) notTest.push_back(e);

        int eAbsChange = int(toTest.size() + 1) * 2;

        // Now test
        int osum, nsum;
        cout << "? 1 " << int(toTest.size() + 1) << ' ' << c + 1 << ' ';
        for(auto e : toTest) cout << e + 1 << ' ';
        cout << endl;
        cin >> osum;

        cout << "? 2 " << c + 1 << endl;

        cout << "? 1 " << int(toTest.size() + 1) << ' ' << c + 1 << ' ';
        for(auto e : toTest) cout << e + 1 << ' ';
        cout << endl;
        cin >> nsum;
        queue<int> tk;
        // cout << "CHANGE " << abs(osum - nsum) << endl;
        if (abs(osum - nsum) == eAbsChange) {
            // Is not in toTest (could be c). Remove all in toTest
            // cout << "IS AS EXPECTD " << endl;
            for(auto e : toTest) tk.push(e);
            
            while(tk.size()) {
                int cc = tk.front();
                tk.pop();
                if (cc == c || dead[cc]) continue;
                dead[cc] = 1;
                // cout << "KILLING " << cc + 1 << endl;
                for(auto e : adj[cc]) {
                    if (e != c && !dead[e]) tk.push(e);
                }
            }
        }
        else {
            // Is in toTest. Is not c.
            for(auto e : notTest) tk.push(e);
            
            while(tk.size()) {
                int cc = tk.front();
                tk.pop();
                if (cc == c || dead[cc]) continue;
                dead[cc] = 1;
                // cout << "KILLING " << cc + 1 << endl;
                for(auto e : adj[cc]) {
                    if (e != c && !dead[e]) tk.push(e);
                }
            }
            if (count(all(dead), false) == 2)
                dead[c] = 1;
        }
    }
    int root;
    for(int i = 0; i < n; i++) {
        if (!dead[i]) {
            root = i;
            break;
        }
    }
    vector<int> answer(n);
    auto dfs = [&](auto dfs, int i, int j, int bsum) -> void {
        int csum;
        cout << "? 1 1 " << i + 1 << endl;
        cin >> csum;
        answer[i] = csum - bsum;
        
        for(auto e : adj[i]) {
            if (e != j) dfs(dfs, e, i, csum);
        }
    };
    dfs(dfs, root, -1, 0);
    cout << "! ";
    for(auto e : answer) {
        cout << e << ' ';
    }
    cout << endl;
}

int main() {
    // HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}