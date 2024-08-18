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

struct Node {
    int hlb = 0, hub = 0;
    int lb = 0, ub = 0;
};

void TC() {
    vector<Node> nodes(1);
    nodes[0].lb = 0, nodes[0].ub = 1;
    nodes[0].hlb = 0, nodes[0].hub = 1;
    int n; cin >> n;
    while(n--) {
        char c; cin >> c;
        if (c == '+') {
            int par, v;
            cin >> par >> v;
            par--;
            Node newnode;
            newnode.lb = min(0, nodes[par].lb + v);
            newnode.ub = max(0, nodes[par].ub + v);
            newnode.hlb = min(nodes[par].hlb, newnode.lb);
            newnode.hub = max(nodes[par].hub, newnode.ub);
            nodes.push_back(newnode);
        }
        else {
            int a, b, k;
            cin >> a >> b >> k;
            a--, b--;
            if (nodes[b].hlb <= k  && k <= nodes[b].hub) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
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