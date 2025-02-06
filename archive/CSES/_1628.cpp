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

int aset[1048576], bset[1048576];
int a[20], b[20];
int as = 0, bs = 0;
int az = 0, bz = 0;

void TC() {
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        if (i & 1) cin >> a[az++];
        else cin >> b[bz++];
    }
    aset[as++] = 0;
    bset[bs++] = 0;
    for(int i = 0; i < az; i++) {
        int asz = as;
        for(int q = 0; q < asz; q++) {
            if (a[i] + aset[q] > x) continue;
            aset[as++] = (a[i] + aset[q]);
        }
    }
    for(int i = 0; i < bz; i++) {
        int bsz = bs;
        for(int q = 0; q < bsz; q++) {
            if (b[i] + bset[q] > x) continue;
            bset[bs++] = (b[i] + bset[q]);
        }
    }
    map<int, ll> cntsa, cntsb;
    for(int i = 0; i < as; i++) cntsa[aset[i]]++;
    for(int i = 0; i < bs; i++) cntsb[bset[i]]++;
    ll tot = 0;
    for(auto &e : cntsa) {
        int tar = x - e.first;
        tot += cntsa[e.first] * cntsb[tar];
    }
    cout << tot << endl;
}

int main() {
    // HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}