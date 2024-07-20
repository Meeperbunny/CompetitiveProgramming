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

void fillLeaf(int c, int l, vector<int> &fl, vector<vector<int>> &adj) {
    int cl = -1;
    for(auto e : adj[c]) {
        if (e != l) {
            fillLeaf(e, c, fl, adj);
            cl = max(cl, fl[e]);
        }
    }
    fl[c] = cl + 1;
}

void query(int x) {
    cout << "? " << x << endl;
    cout.flush();
}

void ans(int x) {
    cout << "! " << x + 1 << endl;
    cout.flush();
}
int constAdv(int c, int l, vector<vector<int>> &adv, vector<vector<int>> &adj, vector<int> &fleaf, const int X) {
    // what to return?
    if (fleaf[c] <= X) {
        return c;
    }
    if (adj[c].size() > 2) {
        // branch
        for(auto e : adj[c]) {
            if (e != l) {
                if (fleaf[e] >= X) {
                    // include it
                    int res = constAdv(e, c, adv, adj, fleaf, X);
                    adv[c].push_back(res);
                }
            }
        }
        return c;
    }
    else {
        for(auto e : adj[c]) {
            if (e != l) {
                int ch = constAdv(e, c, adv, adj, fleaf, X);
                if (c == 0) {
                    adv[c].push_back(ch);
                }
                return ch;
            }
        }
    }
}

void constBin(int c, int l, vector<vector<int>> &adj, vector<vector<int>> &blift) {
    for(auto e : adj[c]) {
        if (e != l) {
            blift[e][0] = c;
            constBin(e, c, adj, blift);
        }
    }
}

void TC() {
    const int X = 50;
    int n; cin >> n;
    int resp; 
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> furthestLeaf(n, -1);
    fillLeaf(0, -1, furthestLeaf, adj);
    // for(auto e : furthestLeaf) cout << e << ' ';
    // cout << endl;
    // Find one that has distance 0. Do that x times. If is 1, then return that node
    // otherwise keep doing it.
    int chosenNode = -1;
    for(int i = 0; i < n; i++) {
        if (furthestLeaf[i] == 0) {
            chosenNode = i;
            break;
        }
    }
    for(int i = 0; i < X; i++) {
        query(chosenNode);
        cin >> resp;
        if (resp == 1) {
            ans(chosenNode);
            return;
        }
        else {
            // wait
        }
    }
    // Have done it x times. Now search
    dbg("Searching");
    int cnode = 0;
    int upper = 0;
    int lower = -1;
    vector<vector<int>> advAdj(n);
    constAdv(0, -1, advAdj, adj, furthestLeaf, X);
    // for(int i = 0; i < n; i++) {
    //     cout << i << " :: ";
    //     for(auto q : advAdj[i]) cout << q << ' ';
    //     cout << endl;
    // }
    while(true) {
        dbg(cnode);
        // All nodes in subtree such that len to leaf > X
        if (advAdj[cnode].size() == 1) {
            cnode = advAdj[cnode][0];
            dbg("Moving to next adv adj");
        }
        else if (advAdj[cnode].size() == 0) {
            lower = cnode;
            break;
            dbg("IS a leaf, breaking");
        }
        else {
            for(auto child : advAdj[cnode]) {
                dbg("DS adv adj child", child);
                int r1, r2;
                query(cnode);
                cin >> r1;
                // If current is 0, the mole is above current
                if (r1 == 0) {
                    upper = 0;
                    lower = cnode;
                    break;
                }
                query(cnode);
                cin >> r2;
                if (r2 == 0) {
                    // Not in this subtree
                    continue;
                }
                else {
                    // In this child. Go down to next intersection
                    cnode = child;
                }
            }
        }
        if (lower != -1) break;
    }

    // BINARY SEARCH
    vector<vector<int>> binaryLifting(n, vector<int>(20, -1));
    constBin(0, -1, adj, binaryLifting);
    vector<int> path;
    for(int i = lower; i != -1; i = binaryLifting[i][0]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    // Path from 0 to lower node
    int L = 0;
    int R = path.size() - 1;
    while(L < R) {
        int M = (L + R + 1) / 2;
        query(path[M]);
        int res; cin >> res;
        if (res == 1) {
            L = M;
        }
        else {
            R = M - 1;
            R = max(0, R - 1);
            L = max(0, L - 1);
        }
    }
    ans(path[L]);
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