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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first;
    for(int i = 0; i < n; i++) cin >> a[i].second;
    sort(a.begin(), a.end());
    ll mas = 0;
    for(int i = 0; i < n; i++) {
        if (i != 0 && a[i - 1].first + 1 == a[i].first) {
            // Has
            ll p1 = a[i - 1].first, p2 = a[i].first;
            ll c1 = a[i - 1].second, c2 = a[i].second;

            if (p1 * c1 + p2 * c2 <= m) {
                mas = max(mas, p1 * c1 + p2 * c2);
                continue;
            }
            
            {
                ll LC = min(p1 * c1, (m / p1) * p1);
                ll LLeft = m - LC;
                ll HC = min(p2 * c2, (LLeft / p2) * p2);
                ll lUsed = LC / p1;
                ll hUsed = HC / p2;
                ll minc = min(lUsed, c2 - hUsed);
                mas = max(mas, min(m, LC + HC + minc));
            }
            
            {
                ll HC = min(p2 * c2, ((m + p2 - 1) / p2) * p2);
                ll hLeft = max(0ll, m - HC);
                ll hUsed = HC / p2;
                
                ll lUsed = 0;
                ll LC = 0;
                if (hLeft > 0) {
                    LC = min(p1 * c1, (hLeft + p1 - 1) / p1 * p1);
                    lUsed = LC / p1;
                }
                ll minc = min(c1 - lUsed, hUsed);
                if (LC + HC >= m && LC + HC - minc <= m) {
                    mas = max(mas, m);
                }
            }
        } // 3 7 , 20 8 -> 100
        else {
            mas = max(mas, min(a[i].first * a[i].second, (m / a[i].first) * a[i].first));
        }
    }
    cout << mas << endl;
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