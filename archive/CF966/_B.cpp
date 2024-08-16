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
    vector<bool> oc(n);
    bool isg = true;
    for(int i = 0; i < n; i++) {
        int j; cin >> j;
        j--;
        if (i == 0) {
            oc[j] = 1;
        }
        else {
            if ((j - 1 >= 0 && oc[j - 1]) || (j + 1 < n && oc[j + 1])) {
                oc[j] = true;
            }
            else {
                isg = false;
            }
        }
    }
    cout << ((isg) ? "YES" : "NO") << endl;
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