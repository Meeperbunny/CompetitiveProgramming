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

void populate(pair<int, int> &r, vector<int> &rsub, int k) {
    if (r.first > r.second) swap(r.first, r.second);
    rsub[0] = 0;
    int f = r.first, s = r.second;
    for(int i = 1; i <= min(f + s, k); i++) {
        if (r.first == 1 && r.second == 1) {
            rsub[i] = rsub[i - 1] + 1;
            if (i + 1 <= k)
                rsub[i + 1] = rsub[i];
            break;
        }
        else if (r.first <= r.second) {
            rsub[i] = rsub[i - 1] + r.first;
            r.second--;
        }
        else {
            rsub[i] = rsub[i - 1] + r.second;
            r.first--;
        }
    }
}

void TC() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> r(n);
    for(int i = 0; i < n; i++) {
        cin >> r[i].first >> r[i].second;   
    }
    vector<int> mops(k + 1, INT_MAX);
    mops[0] = 0;
    for(int i = 0; i < n; i++) {
        vector<int> rsub(k + 1, INT_MAX);
        populate(r[i], rsub, k);

        // dbg(i, r[i].first, r[i].second);
        // for(int q = 0; q <= k; q++) cout << rsub[q] << ' ';
        // cout << endl;

        for(int q = k; q >= 0; q--) {
            for(int j = 0; j <= k; j++) {
                if (mops[q] != INT_MAX && rsub[j] != INT_MAX && q + j <= k) {
                    mops[q + j] = min(mops[q + j], mops[q] + rsub[j]);
                }
            }
        }
        
        // cout << "## MOPS ##" << endl;
        // for(int q = 0; q <= k; q++) cout << mops[q] << ' ';
        // cout << endl;
    }
    if (mops[k] == INT_MAX) mops[k] = -1;
    cout << mops[k] << endl;
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