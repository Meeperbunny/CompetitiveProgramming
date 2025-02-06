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
    int n; cin >> n;
    vector<ll> p(n), m(n);
    vector<vector<int>> comb(n, vector<int>());
    ll tot = 0;
    for(int i = 0; i < n; i++){
        cin >> m[i] >> p[i];
        comb[m[i]].push_back(p[i]);
        tot += p[i];
    }
    priority_queue<int> inset;
    for(int i = 0; i < n; i++) {
        for(auto q : comb[i]) {
            inset.push(q);
        }
        if (inset.size()) {
            tot -= inset.top();
            inset.pop();
        }
    }
    cout << tot << endl;
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