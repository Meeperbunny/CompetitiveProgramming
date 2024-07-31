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
    vector<string> a(2);
    cin >> a[0] >> a[1];
    int cnt = 0;
    for(int i = 1; i < n - 1; i++) {
        string bs = a[0].substr(i - 1, 3), ts = a[1].substr(i - 1, 3);
        if ((bs == "x.x" && ts == "...") || (bs == "..." && ts == "x.x")) {
            cnt++;
        } 
    }   
    cout << cnt << endl;
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