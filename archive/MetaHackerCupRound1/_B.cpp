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

vector<bool> isp;
void sieve(int n) {
    isp = vector<bool>(n + 1, 1);
    isp[0] = 0, isp[1] = 0;
    for(int i = 2; i <= n; i++) {
        for(int q = i * 2; q <= n; q += i) {
            isp[q] = 0;
        }
    }
}

void TC() {
    int n; cin >> n;
    int cnt = 0;
    set<int> ansa, ansb;
    if (n >= 5) ansa.insert(2);
    for(int i = 2; i <= n; i++) {
        if (isp[i] && isp[i - 2]) {
            ansa.insert(i);
        }
    }
    cout << ansa.size() << endl;
    
}

int main() {
    HEADER;
    sieve(10000001);
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cout << "Case #" << t + 1 << ": ";
        TC();
    }
    return 0;
}