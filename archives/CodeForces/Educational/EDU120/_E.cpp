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

void TC() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for(auto &e : x) cin >> e;
    vector<string> a(n);
    for(auto &e : a) {
        cin >> e;
    }
    int lsup = -1;
    vector<int> bestPerm;
    int maxOrd = (1 << n);
    for(int ord = 0; ord < maxOrd; ord++) {
        vector<bool> dir(n);
        for(int q = 0; q < n; q++) {
            dir[q] = (ord >> q) & 1;
        }
        // Go through each and assign values
        vector<vector<int>> toassign(n * 2 + 1);
        for(int i = 0; i < m; i++) {
            int tot = 0;
            for(int q = 0; q < n; q++) {
                if (a[q][i] == '1') {
                    if (dir[q]) tot += 1;
                    else tot -= 1;
                }
            }
            toassign[tot + n].push_back(i);
        }
        int curr = 1;
        vector<int> res(n, 0);
        vector<int> perm(m);
        for(int i = 0; i < 2 * n + 1; i++) {
            for(auto ind : toassign[i]) {
                for(int q = 0; q < n; q++) {
                    if (a[q][ind] == '1')
                        res[q] += curr;
                }
                perm[ind] = curr;
                curr++;
            }
        }
        int tval = 0;
        // cout << ord << '\t';
        for(int i = 0; i < n; i++) {
            // cout << res[i] << ' ';
            tval += abs(res[i] - x[i]);
        }
        // cout << "   " << tval << '\t' << endl;
        // for(auto e : perm) cout << e << ' ';
        // cout << endl;
        if (tval > lsup) {
            lsup = tval;
            swap(perm, bestPerm);
        }
    }
    for(auto e : bestPerm) cout << e << ' ';
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