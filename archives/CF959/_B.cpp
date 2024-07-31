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
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    vector<bool> isd(n, false);
    bool d = false;
    for(int i = 0; i < n; i++) {
        isd[i] = a[i] != b[i];
        if (isd[i]) d = true;
    }
    if (!d) {
        cout << "YES" << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        if (a[i] == '1') {
            break;
        }
        else if (isd[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

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