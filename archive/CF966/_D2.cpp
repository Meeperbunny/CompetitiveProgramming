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
    int n, q;
    cin >> n >> q;
    vector<int> par(n, -1);
    vector<int> sts(n, 1);
    vector<vector<int>> children(n);
    for(int i = (n - 1) / 2 - 1; i >= 0; i--) {
        sts[i] = sts[i * 2 + 1] + sts[i * 2 + 2] + 1;
    }
    for(int i = 1; i < n; i++) {
        cin >> par[i];
        par[i]--;
        children[par[i]].push_back(i);
    }
    vector<int> p(n);
    vector<int> plookup(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        plookup[p[i]] = i;
    }
    int goodcount = 0;
    // init good count
    vector<bool> wasgood(n, false);
    for(int i = 0; i < n; i++) {
        // Check if node i is good
        // For each child, check if it is "right place" in perm:
        //     if one is k away and other is k + 2 or vice versa
        wasgood[i] = true;
        if (children[i].size()) {
            int c1 = children[i][0], c2 = children[i][1];
            int mypos = plookup[i];
            // cout << c1 << ' ' << c2 << endl;
            int c1p = plookup[c1];
            int c2p = plookup[c2];
            int k = sts[c1];
            // cout << i << ' ' << mypos << ' ' << c1p << ' ' << c2p << ' ' << k << endl;
            if (mypos + 1 == c1p && mypos + k + 1 == c2p) {
            }
            else if (mypos + 1 + k == c1p && mypos + 1 == c2p) {
            }
            else {
                wasgood[i] = false;
            }
        }
        if (wasgood[i]) {
            goodcount++;
        }
    }
    // dbg("WAS GOOD");
    // for(auto e : wasgood) cout << e << ' ';
    // cout << endl;
    while(q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        // dbg(a, b);
        
        // cout << "PLK " << goodcount << endl;
        // for(auto e : plookup) cout << e << ' ';
        // cout << endl;

        int pa = p[a], pb = p[b];
        int para = par[pa], parb = par[pb];
        // SWAP A AND B
        // cout << "swapping " << pa << ' ' << pb << endl;
        swap(plookup[pa], plookup[pb]);
        swap(p[a], p[b]);

        // cout << "WAS GOOD " << goodcount << endl;
        // for(auto e : wasgood) cout << e << ' ';
        // cout << endl;
        // cout << "PLK " << goodcount << endl;
        // for(auto e : plookup) cout << e << ' ';
        // cout << endl;

        // CHECK A GC, B GC, P_A GC, P_B GC
        // Check if parent of a was good
        if (wasgood[pa]) goodcount--, wasgood[pa] = false;
        if (wasgood[pb]) goodcount--, wasgood[pb] = false;
        if (para != -1)
            if (wasgood[para]) goodcount--, wasgood[para] = false;
        if (parb != -1)
            if (wasgood[parb]) goodcount--, wasgood[parb] = false;

        for(auto i : {pa, pb, para, parb}) {
            if (i == -1) continue;
            if (wasgood[i]) continue;
            // cout << "\tUpdating: " << i << endl;
            wasgood[i] = true;
            if (children[i].size()) {
                int c1 = children[i][0], c2 = children[i][1];
                int mypos = plookup[i];
                // cout << '\t' << i << ' ' << c1 << ' ' << c2 << endl;
                int c1p = plookup[c1];
                int c2p = plookup[c2];
                int k = sts[c1];
                // cout << '\t' <<i << ' ' << mypos << ' ' << c1p << ' ' << c2p << ' ' << k << endl;
                if (mypos + 1 == c1p && mypos + k + 1 == c2p) {
                }
                else if (mypos + 1 + k == c1p && mypos + 1 == c2p) {
                }
                else {
                    wasgood[i] = false;
                }
            }
            if (wasgood[i]) {
                // cout << "\twas good!" << endl;
                goodcount++;
            }
            else {
                // cout << "\twas not good." << endl;
            }
        }

        // cout << "WAS GOOD " << goodcount << endl;
        // for(auto e : wasgood) cout << e << ' ';
        // cout << endl;

        //GET GC
        if (goodcount == n) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
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