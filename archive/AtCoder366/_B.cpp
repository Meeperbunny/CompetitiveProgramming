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
    int n; cin >> n;
    vector<string> res(n);
    int m = 0;
    for(auto &e : res) {
        cin >> e;
        m = max(m, int(e.size()));
    }
    vector<string> ret(m);
    for(int i = 0; i < m; i++) {
        for(int q = n - 1; q >= 0; q--) {
            if (i >= res[q].size()) {
                ret[i] += '*';
            }
            else {
                ret[i] += res[q][i];
            }
        }
    }

    for(int i = 0; i < m; i++) {
        bool sq = false;
        for(int q = n - 1; q >= 0; q--) {
            if (!sq && ret[i][q] == '*') {
                ret[i][q] = ' ';
            }
            else if (ret[i][q] != '*') sq = true;
        }
    }

    for(auto e : ret) {
        cout << e << endl;
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