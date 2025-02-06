#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);freopen("file.out", "w", stdout);};
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
    double currentMax = DBL_MAX;
    vector<double> lowers;
    for(int i = 1; i <= n; i++) {
        double a, b;
        cin >> a >> b;
        lowers.push_back(a);
        currentMax = min(currentMax,  b / double(i));
    }
    for(int i = 1; i <= n; i++) {
        double l = lowers[i - 1];
        if (currentMax * i < l) {
            cout << -1 << endl;
            return;
        }
    }
    cout << fixed << setprecision(10) << 1.0 / currentMax << endl;
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