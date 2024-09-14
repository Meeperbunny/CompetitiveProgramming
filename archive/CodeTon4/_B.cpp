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
    if (n % 2 == 0) {
        cout << -1 << endl;
    }
    else {
        vector<int> ops;
        bool f = false;
        for(int i = 30; i >= 1; i--) {
            if ((n >> i)  & 1) {
                f = true;
                ops.push_back(2);
            }
            else {
                if (f)
                    ops.push_back(1);
            }
        }
        cout << ops.size() << endl;
        for(auto e : ops) {
            cout << e << ' ';
        } cout <<endl;
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