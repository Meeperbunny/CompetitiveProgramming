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
    vector<int> a(n);
    vector<pair<int, int>> ops;
    for(int i = 0; i < n; i++) cin >> a[i];
    set<int> inset;
    for(int i = 0; i < n; i++) inset.insert(i);
    for(int i = n - 1; i >= 1; i--) {
        vector<int> at(i, -1);
        for(auto e : inset) {
            if (at[a[e] % i] != -1) {
                // add op
                ops.push_back({at[a[e] % i] + 1, e + 1});
                inset.erase(e);
                break;
            }
            else {
                at[a[e] % i] = e;
            }
        }

    }
    reverse(ops.begin(), ops.end());
    cout << "YES" << endl;
    for(auto e : ops) {
        cout << e.first << ' ' << e.second << endl;
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