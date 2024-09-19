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

pair<ll, vector<ll>> bfs(ll start, const vector<vector<ll>> &adj, vector<bool> &visited) {
    ll n = adj.size();
    vector<ll> dist(n, LLONG_MAX); // Stores distance to each node, initialized to infinity
    vector<ll> parent(n, -1);      // Stores parent of each node to reconstruct the path
    queue<ll> q;
    dist[start] = 0;
    visited[start] = true;
    q.push(start);

    ll farthest_node = start;
    ll max_dist = 0;

    while (!q.empty()) {
        ll node = q.front();
        q.pop();

        for (ll neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node; // Track the parent for path reconstruction
                q.push(neighbor);
                
                if (dist[neighbor] > max_dist) {
                    max_dist = dist[neighbor];
                    farthest_node = neighbor;
                }
            }
        }
    }

    // Reconstruct the longest path using the parent array
    vector<ll> path;
    ll current = farthest_node;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    return {farthest_node, path};
}

// Function to compute the longest connected path in the graph
vector<ll> getLongestConnectedPath(const vector<vector<ll>> &adj) {
    ll n = adj.size();
    vector<bool> visited(n, false);  // Track visited nodes
    vector<ll> longest_path;         // Store the longest path

    for (ll i = 0; i < n; ++i) {
        if (!visited[i]) {
            // Step 1: Perform BFS from an arbitrary node (i) in the current component
            pair<ll, vector<ll>> result1 = bfs(i, adj, visited);
            ll farthest_from_i = result1.first;

            // Reset visited array for BFS on the same connected component
            fill(visited.begin(), visited.end(), false);

            // Step 2: Perform BFS from the farthest node found in step 1
            pair<ll, vector<ll>> result2 = bfs(farthest_from_i, adj, visited);

            // If the path found is longer than the current longest path, update it
            if (result2.second.size() > longest_path.size()) {
                longest_path = result2.second;
            }
        }
    }

    return longest_path;
}


void TC() {
    int n; cin >> n;
    map<string, int> gti, wti;
    vector<pair<int, int>> order(n);
    for(int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (!gti.count(a)) gti[a] = gti.size();
        if (!wti.count(b)) wti[b] = wti.size();
        order[i] = {gti[a], wti[b]};
    }
    ll mdi = 0;
    vector<vector<ll>> adj(n);
    for(int q = 0; q < n; q++) {
        for(int j = 0; j < n; j++) {
            if (q != j && (order[q].first == order[j].first || order[q].second == order[j].second)) {
                adj[q].push_back(j);
                adj[j].push_back(q);
                dbg(j, q);
            }
        }
    }
    mdi = max(mdi, ll(getLongestConnectedPath(adj).size()));
    cout << n - mdi << endl;
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