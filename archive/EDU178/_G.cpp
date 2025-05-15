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

ll modpow(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}

void TC() {
    // If is in a loop, any coloring will get all.
    // Any node into the loop or in general is unique.
    // Loop will be a pure loop. If one is disconnected, they are all free
    // Downstream not possible. Only things that are possible are loops, into loops, and dag (into self loop)
    // Only possible is in-loop or into loop
    // Into loop will terminate INTO a single cycle (1 path)
    // Colorings is k^(loop count + into node count) mod 3
    // It can become smaller loop, (some loop index to track this).
        // This frees the index difference
        // SUBCASE If we change one in the loop, it can either become self loop, freeing the loop
    // Go into another loop (frees all)
    // Go into larger loop (Enter some innode, it enters cyc at i, we are at j, it is k dist, we free all and loop is now i - j + k long, rest are free)
    // An outside node can Become its own loop (index diff becomes cyc, rest are free)
    // Enter new loop (no diff)
    // Enter something else (no diff)
    // THings to track:
    // if node is a cycle or not
    // Some cycle index of the node
    // Distance of entry to a cycle
    // Reverse dfs cc id? (for checking if self)
    // First is find cycles.

    // We have initial parity.
    // If goes to self, loop -= 1, if parity is different than original parity then is changed
    // True for anything
    // If we join another, index parity may flip. But fundamental is still the same
    // We know base. When does it change?
    // DSU of linked parities (in a group?)
    // Just as long as it is different???????????????????????? WTF

    int n, q;
    cin >> n >> q;
    vector<int> g(n);
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        k--;
        g[i] = k;
    }
    // Steps are:
    // Label cycle ids
    // This done by dfs at some point. Label all seen with some id. If we hit our own id, then is cycle (find it out here and return)
    // If hit another id, then we are going into a cycle. Change all that we have seen
    // Get cycles index
    vector<int> color(n, -1), cycleId(n, -1), cycleIndex(n, -1);
    vector<int> csizes(n + 2);
    vector<int> colorSizes(n + 2);
    vector<int> cycleSeen;
    int cc = 0;
    int ccount = 0;
    // for(auto e : g) cout << e << ' '; cout << endl;
    for(int i = 0; i < n; i++) {
        if (color[i] == -1) {
            cc++;
            // cout << "Starting on " << i << endl;
            int q = i;
            while(true) {
                // cout << "ON q " << q << endl;
                if (color[q] == -1) {
                    color[q] = cc;
                    colorSizes[cc] += 1;
                    cycleSeen.push_back(q);
                    q = g[q];
                }
                else if (color[q] == cc) {
                    // IS CYCLE. Starting at curr and label all in circle with same cycle id.
                    int j = q;
                    int csize = 0;
                    while(cycleId[j] == -1) {
                        cycleId[j] = cc;
                        j = g[j];
                        csize++;
                    }
                    // Label index
                    j = q;
                    csizes[cc] = csize;
                    for(int m = 0; m < csize; m++) {
                        cycleIndex[j] = m;
                        j = g[j];
                    }
                    break;
                }
                else {
                    // IS INTO, CHANGE ALL SEEN
                    int tc = color[q];
                    colorSizes[tc] += colorSizes[cc];
                    colorSizes[cc] = 0;
                    for(auto e : cycleSeen) {
                        color[e] = tc;
                    }
                    break;
                }
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     cout << cycleId[i] << ' ';
    // } cout << endl;
    // for(int i = 0; i < n; i++) {
    //     cout << cycleIndex[i] << ' ';
    // } cout << endl;

    int fcount = 0;

    // Reverse dfs to get component ids
    vector<vector<int>> reverseG(n);
    vector<int> distanceToCycle(n, -1);
    for(int i = 0; i < n; i++) {
        reverseG[g[i]].push_back(i);
    }
    auto ddfs = [&](auto ddfs, int i, int dist) -> void {
        if (cycleId[i] == -1 && distanceToCycle[i] == -1) {
            fcount += 1;
        }
        distanceToCycle[i] = dist;
        for(auto e : reverseG[i]) {
            if (cycleId[i] == -1)
                ddfs(ddfs, e, dist + 1);
        }
    };
    // Reverse dfs for distances to cycles
    for(int i = 0; i < n; i++) {
        if (cycleId[i] != -1) {
            // Starting on a cycle. Add and continue to add all non cycles with distances
            ddfs(ddfs, i, 0);
        }
    }


    // DUMB IDEA
     // Reverse dfs to get component ids
     
     // Reverse dfs for distances to cycles
    //  for(int i = 0; i < n; i++) {
    //      if (cycleId[i] != -1) {
    //          // Starting on a cycle. Add and continue to add all non cycles with distances
    //          ddfs(ddfs, i, 0);
    //      }
    //  }
    // DUMB IDEA
    while(q--) {
        int x, y, k;
        cin >> x >> y >> k;
        x--, y--;
        if (k % 3 == 1) {
            cout << 1 << endl;
            continue;
        }
        if (k % 3 == 0) {
            cout << 0 << endl;
            continue;
        }
        // Cases. Check if orig is in a cycle
        if (cycleId[x] == -1) {
            // NOT IN
            // CASES: If going into itself, then we need to figure this out. Otherwise, nothing changes?
            if (color[x] == color[y]) {
                // GOING INTO SELF, CARE
                cout << -1 << endl;
            }
            else {
                // NOTHING CHANGES
                ll ways = modpow(k, ccount + fcount, 3);
                cout << "F " << ways << endl;
            }
        }
        else {
            // IS IN CYCLE. IF IT GOES INTO ITSELF, CARE
            // OTHERWISE IS CREATING ITS OWN COLOR SIZE
            if (color[x] == color[y]) {
                // GOING INTO SELF, CARE
                cout << -1 << endl;
            }
            else {
                // Everything is now free!
                int mc = color[x];
                ll ways = modpow(k, ccount - 1ll + fcount + csizes[cycleId[x]], 3);
                cout << "S " << ways << endl;
            }
        }
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