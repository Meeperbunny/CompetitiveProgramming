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
    for(auto &e : a) cin >> e;
    int t = n - 2;
    map<int, int> cnt;
    for(auto e : a) cnt[e]++;
    for(int i = 1; i <= t; i++) {
        if (t % i == 0) {
            int other = t / i;
            int tar = 1;
            if (i == other) {
                if (cnt[i] >= 2){
                    cout << i << ' ' << i << endl;
                    return;
                }
            }
            else {
                if (cnt[i] && cnt[other]) {
                    cout << i << ' ' << other << endl;
                    return;
                }
            }
        }
    }

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