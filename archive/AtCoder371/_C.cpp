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
    cin >> n;
    cin >> m;
    vector<set<int>> AA(n), BB(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a>>b;
        a--,b--;
        AA[b].insert(a);    
        AA[a].insert(b);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a>>b;
        a--,b--;
        BB[b].insert(a);    
        BB[a].insert(b);
    }
    vector<vector<int>> costs(n, vector<int>(n));
    for(int i = 0; i < n - 1; i++) {
        for(int q= i + 1; q < n; q++){
            cin >> costs[i][q];
            costs[q][i] = costs[i][q];
        }
    }
    vector<int> order(n);
    iota(all(order), 0);
    int mtc = INT_MAX;
    do {
        // For each, check
        int tc = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int q= i + 1; q < n; q++){
                int A = order[i], B = order[q];
                if (AA[i].count(q) != BB[A].count(B)) {
                    tc += costs[A][B];
                }
            }
        }
        // for(auto e : order) cout << e << ' ';
        // cout << mtc << endl;
        mtc = min(tc, mtc);
    }
    while(next_permutation(all(order)));
    cout << mtc << endl;
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