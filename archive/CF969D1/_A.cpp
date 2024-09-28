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

int innercount;
int leafQCount;
int leafOneCount;
int leafZeroCount;

void dfs(int c, int l, vector<vector<int>> &adj, string& s) {
    int b = 0;
    for(auto e : adj[c]) {
        if (e == l) continue;
        b++;
        dfs(e, c, adj, s);
    }
    if (b == 0) {
        if (s[c] == '?') leafQCount++;
        if (s[c] == '1') leafOneCount++;
        if (s[c] == '0') leafZeroCount++;
    }
    else if (c != 0) {
        if (s[c] == '?') innercount++;
    }
}

void TC() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    string s;
    for(int i = 0; i < n - 1; i++) {
        int a,b;cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> s;
    innercount = 0;
    leafQCount = 0;
    leafOneCount = 0;
    leafZeroCount = 0;
    dfs(0, -1, adj, s);
    // cout << innercount << ' ' << leafQCount << ' ' << leafOneCount << ' ' << leafZeroCount << endl;
    if (s[0] == '?') {
        int whoseturn = innercount % 2;
        int iriscount = 0;
        if (leafOneCount == leafZeroCount) {
            // Doesnt matter which you choose, just whatever. second is losing
            if (whoseturn == 0) {
                // forced to go first.
                // going second
                iriscount += leafOneCount;
                iriscount += (leafQCount) / 2;
                cout << iriscount << endl;
                return;
            }
            else  {
                // going second
                iriscount += leafOneCount;
                iriscount += (leafQCount + 1) / 2;
                cout << iriscount << endl;
                return;

            }
        }
        else {
            // First does matter.
            iriscount += max(leafZeroCount, leafOneCount);
            iriscount += (leafQCount) / 2;
            cout << iriscount << endl;
            return;
        }
    }
    else {
        int iriscount = 0;
        if (s[0] == '1') iriscount += leafZeroCount;
        else iriscount += leafOneCount;
        iriscount += int((leafQCount + 1) / 2);
        cout << iriscount << endl;
        return;
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