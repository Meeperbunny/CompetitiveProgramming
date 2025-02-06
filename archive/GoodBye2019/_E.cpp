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

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

void TC() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> inset;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first += 1000000;
        a[i].second += 1000000;
        if ((a[i].first + a[i].second) & 1) {
            inset.push_back(i);
        }
    }
    if (inset.size() != n && !inset.empty()) {
        cout << inset.size() << endl;
        for(auto e : inset) cout << e + 1 << ' ';
        cout << endl;
        return;
    }
    else {
        inset.clear();
        int gcdX = 0, gcdY = 0;
        for(int i = 0; i < n; i++) {
            for(int q = 0; q < n; q++) {
                gcdX = gcd(gcdX, (a[i].first - a[q].first));
                gcdY = gcd(gcdY, (a[i].second - a[q].second));
            }
        }
        int minc = gcd(gcdX, gcdY);
        for(int i = 0; i < n; i++) {
            int xd = abs(a[0].first - a[i].first) / minc;
            int yd = abs(a[0].second - a[i].second) / minc;
            dbg(xd, yd);
            if ((xd + yd) & 1) {
                inset.push_back(i);
            }
        }
        if (!inset.size() || inset.size() == n) {
            inset.clear();
            for(int i = 0; i < n; i++) {
                int xd = abs(a[0].first - a[i].first) / minc;
                int yd = abs(a[0].second - a[i].second) / minc;
                dbg(xd, yd);
                if ((xd & 1 || yd & 1)) {
                    inset.push_back(i);
                }
            }
        }
        cout << inset.size() << endl;
        for(auto e : inset) cout << e + 1 << ' ';
        cout << endl;
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