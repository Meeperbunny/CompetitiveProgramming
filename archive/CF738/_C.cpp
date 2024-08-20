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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if (a[0] == 1) {
        cout << n + 1 <<  ' ';
        for(int i = 1; i <= n; i++)  cout << i << ' ';
        cout << endl;
        return;
    }
    if (a[n - 1] == 0) {
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << n + 1 <<  ' ';
        cout << endl;
        return;
    }
    vector<bool> p(n);
    bool f = true;
    for(int i = 0; i < n - 1; i++) {
        if (f && a[i] == 0 && a[i + 1] == 1) {
            f = false;
            cout << i + 1 << ' ' << n + 1 << ' ' << i + 2 << ' ';
            p[i] = 1, p[i + 1] = 1;
        }
        else {
            if (!p[i])
                cout << i + 1 << ' ';
            p[i] = 1;
        }
    }
    if (!p[n - 1]) cout << n << ' ';
    cout << endl;
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