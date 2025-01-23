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
    int pc = 0, nc = 0;
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    int ind = 0;
    for(int i = 0; i < n; ++i) {
        int e = a[i];
        if (e != -1 && e != 1) {
            ind = i;
        }
    }
    set<int> r;
    pair<int, int> LL{}, LR{};
    pair<int, int> RL{}, RR{};
    pair<int, int> v;
    for(int i = 0; i < ind; ++i) { 
        v.first = min(0, v.first + a[i]);
        v.second = max(0, v.second + a[i]);
        LL.first = min(LL.first, v.first);
        LL.second = max(LL.second, v.second);
    }
    v = {0,0};
    for(int i = ind - 1; i >= 0; --i) { 
        v.first = min(0, v.first + a[i]);
        v.second = max(0, v.second + a[i]);
        LR.first = min(LR.first, v.first);
        LR.second = max(LR.second, v.second);
    }
    v = {0,0};
    for(int i = ind + 1; i < n; ++i) { 
        v.first = min(0, v.first + a[i]);
        v.second = max(0, v.second + a[i]);
        RL.first = min(RL.first, v.first);
        RL.second = max(RL.second, v.second);
    }
    v = {0,0};
    for(int i = n - 1; i >= ind + 1; --i) { 
        v.first = min(0, v.first + a[i]);
        v.second = max(0, v.second + a[i]);
        RR.first = min(RR.first, v.first);
        RR.second = max(RR.second, v.second);
    }
    for(int i = LL.first; i <= LL.second; ++i) r.insert(i);
    for(int i = LR.first; i <= LR.second; ++i) r.insert(i);
    for(int i = RL.first; i <= RL.second; ++i) r.insert(i);
    for(int i = RR.first; i <= RR.second; ++i) r.insert(i);

    pair<int, int> LLL, RRR;
    int vv = 0;
    for(int i = ind - 1; i >= 0; --i) {
        vv += a[i];
        LLL.first = min(LLL.first, vv);
        LLL.second = max(LLL.second, vv);
    }
    vv = 0;
    for(int i = ind + 1; i < n; ++i) {
        vv += a[i];
        RRR.first = min(RRR.first, vv);
        RRR.second = max(RRR.second, vv);
    }

    for(int i = a[ind] + LLL.first + RRR.first; i <= a[ind] + LLL.second + RRR.second; ++i) {
        r.insert(i);
    }

    cout << r.size() << endl;
    for(auto e : r) cout << e << ' ';
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