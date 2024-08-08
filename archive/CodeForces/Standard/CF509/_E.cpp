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
    map<int, int> cnts;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        if (a == n) swap(a, b);
        if (b != n || (a == n)) {
            cout << "NO" << endl;
            return;
        }
        cnts[a]++;
    }
    set<int> free;
    vector<int> ans;
    for(int i = 1; i <= n; i++) free.insert(i);
    for(auto e : cnts) {
        if (free.find(e.first) == free.end()) {
            cout << "NO" << endl;
            return;
        }
        free.erase(free.find(e.first));
        ans.push_back(e.first);
        for(int i = 0; i < e.second - 1; i++) {
            // Find one lower
            int c = *free.begin();
            if (c >= e.first) {
                cout << "NO" << endl;
                return;
            }
            ans.push_back(c);
            free.erase(free.begin());
        }
    }
    ans.push_back(n);
    cout << "YES" << endl;
    for(int i = 1; i < n; i++){
        cout << ans[i - 1] << ' ' << ans[i] << endl;
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