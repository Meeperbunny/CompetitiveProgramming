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

struct Node {
    map<pair<ll, ll>, ll> ma;
    ll imp;
    ll mysts;
    ll myind;
    ll par = -1;
};

void construct(ll c, ll l, vector<Node> &nodes, vector<vector<ll>> &adj) {
    nodes[c].mysts = -1;
    nodes[c].myind = c;
    for(auto e : adj[c]) {
        if (e != l) {
            nodes[e].par = c;
            construct(e, c, nodes, adj);
            nodes[c].imp += nodes[e].imp;
            nodes[c].mysts += nodes[e].mysts;
            nodes[c].ma.insert({{nodes[e].mysts, nodes[e].myind}, nodes[e].myind});
        }
    }
}

void op(ll cur, vector<Node> &nodes, vector<vector<ll>> &adj) {
    if (nodes[cur].ma.size()) {
        Node& curr = nodes[cur];
        Node& heavy = nodes[nodes[cur].ma.begin()->second];
        Node& fa = nodes[nodes[cur].par];

        ll curroldsts = curr.mysts;

        heavy.par = nodes[cur].par;
        curr.par = nodes[cur].ma.begin()->second;

        // Get rid of from my subtree
        curr.imp -= heavy.imp;
        curr.mysts -= heavy.mysts;

        heavy.mysts += curr.mysts;
        heavy.imp += curr.imp;

        curr.ma.erase(curr.ma.begin());
        heavy.ma.insert({{curr.mysts, curr.myind}, curr.myind});
        fa.ma.erase({curroldsts, curr.myind});
        fa.ma.insert({{heavy.mysts, heavy.myind}, heavy.myind});
    }
}

void TC() {
    int N, Q;
    cin >> N >> Q;
    vector<Node> nodes(N);
    for(int i = 0; i < N; i++) {
        cin >> nodes[i].imp;
    }
    vector<vector<ll>> adj(N);
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    construct(0, -1, nodes, adj);
    for(int q = 0; q < Q; q++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            cout << nodes[x - 1].imp << endl;
        }
        else {
            op(x - 1, nodes, adj);
        }
        // for(auto e : nodes) cout << e.imp << ' ';
        // cout << endl;
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