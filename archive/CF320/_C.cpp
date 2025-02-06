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

double getMaxPoorness(vector<double> &a, double m) {
    double maxPoorness = 0, mp = INT_MIN, mn =INT_MAX;
    for(int i = a.size() - 1; i >= 0; i--) {
        mp = max((a[i] - m) + mp, (a[i] - m));
        mn = min((a[i] - m) + mn, (a[i] - m));
        maxPoorness = max({maxPoorness, abs(mp), abs(mn)});
    }
    return maxPoorness;
}

void TC() {
    int n; cin >> n;
    vector<double> a(n);
    for(auto &e : a) {
        cin >> e;
    }
    double base = -11000;
    for(double m = 22000; m >= 1e-12; m /= 2) {
        while(true) {
            double onB = getMaxPoorness(a, base + 0);
            double onM = getMaxPoorness(a, base + m);
            double furM = getMaxPoorness(a, base + m + m);
            if (onB > onM && onM > furM) {
                base = base + m;
            }
            else break;
        }
    }
    cout << fixed << setprecision(10) << getMaxPoorness(a, base) << endl;
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