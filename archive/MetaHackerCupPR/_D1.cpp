#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);freopen("file.out", "w", stdout);};
// #define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
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
    ll n, g;
    cin >> n >> g;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    vector<int> inds(n);
    iota(all(inds), 0);
    sort(all(inds), [&](int &i, int &j){
        return a[i] > a[j];
    });
    ll mdist = LLONG_MAX;
    ll mind = -1;
    for(int i = 0; i < n; i++) {
        ll cpos = a[inds[i]];
        ll dist = abs(cpos - g);
        // dbg(cpos, i);
        if (dist < mdist) {
            mdist = dist;
            mind = i + 1;
        }
        else if (dist == mdist && i + 1 < mind) {
            mind = i + 1;
        }
    }
    cout << mind << ' ' << mdist << endl;
}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cout << "Case #" << t + 1 << ": ";
        TC();
    }
    return 0;
}