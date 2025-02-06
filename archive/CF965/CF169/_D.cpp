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

string m[6] = {"BG", "BR", "BY", "GR", "GY", "RY"};

ll sToInd(string s) {
    for(int i = 0; i < 6; i++) {
        if (s == m[i]) return i;
    }
}

void TC() {
    int n, q;
    cin >> n >> q;
    vector<set<int>> inds(6);
    vector<string> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        inds[sToInd(c[i])].insert(i);
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        // If can go directly do it
        string &a = c[l], &b = c[r];
        if (a[0] == b[0] || a[0] == b[1] || a[1] == b[0] || a[1] == b[1]) {
            // dbg(a, b, "DIRECT");
            cout << abs(r - l) << endl;
            continue;
        }
        else {
            int mdist = INT_MAX;
            vector<string> toCheck = {
                string(1, min(a[0], b[0])) + string(1, max(a[0], b[0])),
                string(1, min(a[0], b[1])) + string(1, max(a[0], b[1])),
                string(1, min(a[1], b[0])) + string(1, max(a[1], b[0])),
                string(1, min(a[1], b[1])) + string(1, max(a[1], b[1])),
            };
            for(auto e : toCheck) {
                // cout << q << ' ' << a << ' ' << b << ' ' << "Checking " << e << endl;
                int ind = sToInd(e);
                // Check for lowest at curr, check for highest at curr.
                auto lit = inds[ind].lower_bound(l);
                auto rit = inds[ind].lower_bound(l);
                if (lit != inds[ind].begin()) {
                    lit = prev(lit);
                    int p = *lit;
                    int d1 = p - l;
                    int d2 = p - r;
                    mdist = min(abs(d1) + abs(d2), mdist);
                }
                if (rit != inds[ind].end()) {
                    int p = *rit;
                    int d1 = p - l;
                    int d2 = p - r;
                    mdist = min(abs(d1) + abs(d2), mdist);
                }
            }
            if (mdist < INT_MAX) {
                cout << mdist << endl;
                continue;
            }
        }
        cout << -1 << endl;
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