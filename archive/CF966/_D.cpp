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
    vector<ll> a(n);
    vector<ll> pre(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    vector<int> lpos, rpos;
    string s; cin >> s;
    for(int i = 0; i < n; i++) {
        if (s[i] == 'L') lpos.push_back(i);
        else rpos.push_back(i);
    }
    int l = 0, r = rpos.size() - 1;
    ll tot = 0;
    while(l != lpos.size() && r >= 0) {
        // Check if crossing
        if (lpos[l] < rpos[r]) {
            tot += pre[rpos[r] + 1] - pre[lpos[l]];
            l++, r--;
        }
        else break;
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