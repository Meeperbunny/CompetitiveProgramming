#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int query(int n) {
    cout << "? " << n + 1 << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}

void answer(int n) {
    cout << "! " << n + 1 << endl;
    cout.flush();
}

void constToLeaf(int c, int l, vector<vector<int>> &adj, vector<int> &ldist, vector<int> &par) {
    int mdist = 0;
    for(auto e : adj[c]) {
        if (e != l) {
            constToLeaf(e, c, adj, ldist, par);
            mdist = max(ldist[e] + 1, mdist);
            par[e] = c;
        }
    }
    ldist[c] = mdist;
}

void TC() {
    const int X = 80;
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Ask X queries at a leaf node
    int leafInd = -1;
    for(int i = 1; i < n; i++) {
        if (adj[i].size() == 1) {
            leafInd = i;
            break;
        }
    }
    for(int i = 0; i < X; i++) {
        int res = query(leafInd);
        if (res == 1) {
            answer(leafInd);
            return;
        }
    }

    // Have queried X times. Now all with a max depth of < X are not included.
    // Find max depth
    vector<int> ldist(n, -1);
    vector<int> par(n, -1);
    constToLeaf(0, -1, adj, ldist, par);

    if (ldist[0] <= X) {
        answer(0);
        return;
    }

    // Have advanced search tree, const search
    int lower = -1;
    int curr = 0;
    while(true) {
        dbg(curr);
        bool found = false;
        vector<int> relNodes;
        for(auto e : adj[curr]) {
            if (e == par[curr]) continue;
            if (ldist[e] < X) continue;
            relNodes.push_back(e);
        }
        if (relNodes.size() == 0) {
            lower = curr;
            break;
        }
        else if (relNodes.size() == 1) {
            curr = relNodes[0];
            continue;
        }
        for(auto e : relNodes) {
            int r1 = query(curr);
            if (r1 == 0) {
                // Mole is above.
                lower = curr;
                break;
            }
            int r2 = query(e);
            if (r2 == 1) {
                // Mole is in subtree, go down till ldist isnt big enough OR find an intersection
                curr = e;
                found = true;
                break;
            }
            else {
                // not in subtree
            }
        }
        if (lower != -1) break;
        if (!found) {
            lower = curr;
        }
    }
    dbg("Binary Searching", lower);
    vector<int> path;
    int c = lower;
    while(c != -1) {
        path.push_back(c);
        c = par[c];
    }
    reverse(path.begin(), path.end());
    int L = 0, R = path.size() - 1;
    while(L < R) {
        int tq = (L + R + 1) / 2;
        int res = query(path[tq]);
        if (res == 0) {
            R = max(0, tq - 2);
            L = max(0, L - 1);
        }
        else {
            L = tq;
        }
    }
    answer(path[L]);
    return;
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