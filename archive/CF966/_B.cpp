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
    vector<int> a(n), b(n);
    map<int, int> apos, bpos;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        apos[a[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        bpos[b[i]] = i;
    }
    for(int i = 0; i < n - 1; i++) {
        int aa = a[i], bb = a[i + 1];
        if (abs(bpos[aa] - bpos[bb]) > 1) {
            cout << "Alice" << endl;
            return;
        }
    }
    cout << "Bob" << endl;

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