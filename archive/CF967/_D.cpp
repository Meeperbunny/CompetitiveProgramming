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
    // cout << "STARTING" << endl;
    int n; cin >> n;
    vector<int> a(n);
    vector<int> maxcnts(n, 0), currcnts(n, 0);
    vector<bool> added(n, 0);
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        maxcnts[a[i]]++;
    }
    map<int, int> inset;
    vector<queue<int>> fseen(n);
    int par = -1;
    int last = 0;
    for(int i = 0; i < n; i++) {
        int &c = a[i];
        // cout << "### " << i << " ### " << ' ' << c << endl;
        if (added[c]) continue;
        fseen[c].push(i);
        inset[c]++;
        currcnts[c]++;
        if (currcnts[c] == maxcnts[c]) {
            while(true) {
                // Make decision
                // cout  << inset.size() << endl;
                int tochoose = (par == -1) ? inset.rbegin()->first : inset.begin()->first;
                // cout << '\t' << "Making choice of: " << tochoose << endl;

                ans.push_back(tochoose);
                par *= -1;
                int togo = fseen[tochoose].front();
                if (inset.count(tochoose))
                    inset.erase(tochoose);
                added[tochoose] = true;
                for(int q = last; q <= togo; q++) {
                    int r = a[q];
                    if (added[r]) continue;
                    if (inset.count(r))
                        inset[r]--;
                    if (inset[r] == 0) {
                        // If going to erase last of important one, then make it be chosen.
                        inset.erase(r);
                    }

                    // Pop fseen
                    while (fseen[r].size() && fseen[r].front() <= q) fseen[r].pop();
                }
                fseen[tochoose] = queue<int>();
                last = togo + 1;
                if  (tochoose == c) break;
            }
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << ' ';
    } cout << endl;
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