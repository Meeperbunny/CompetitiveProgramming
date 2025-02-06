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
    ll n; cin >> n;
    vector<ll> a(n);
    ll L = 0, R = n - 1;
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> inds(n);
    iota(all(inds), 0);
    sort(all(inds), [&](int i, int j){
        return a[i] < a[j];
    });
    set<ll> seen;
    for(int i = 0; i < n; i++) {
        int q = inds[i];
        ll lb = q - a[q] + 1;
        ll rb = q + a[q] - 1;
        // dbg(q, lb, rb);
        // dbg(L, R);
        // if (seen.size()) dbg(*seen.begin(), *seen.rbegin());
        if (seen.size() && (*seen.begin() < lb || *seen.rbegin() > rb)) {
            cout << 0 << endl;
            return;
        }
        seen.insert(q);
        L = max(L, lb);
        R = min(R, rb);
    }
    // dbg("Done");

    cout << max(R - L + 1, 0ll) << endl;
    
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