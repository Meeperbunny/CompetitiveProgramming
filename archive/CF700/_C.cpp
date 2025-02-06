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

int query(int n) {
    cout << "? " << n << endl;
    cout.flush();
    int j;
    cin >> j;
    return j;
}

int ans(int n) {
    cout << "! " << n << endl;
    cout.flush();
}

void TC() {
    int n; cin >> n;
    int lower = 0, upper = n + 1;
    int lval = INT_MAX, rval = INT_MAX;
    while(lower + 2 < upper) {
        int mid = (lower + upper) / 2;
        int res = query(mid);
        int rmid = mid + 1;
        int rres = query(rmid);
        if (res > rres) {
            lower = mid;
            lval = res;
        }
        else {
            upper = rmid;
            rval = rres;
        }
    }
    ans(lower + 1);
}

int main() {
    // HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}