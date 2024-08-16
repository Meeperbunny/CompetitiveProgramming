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
    int m; cin >> m;
    while(m--) {
        string s;
        cin >> s;
        map<int, int> mapping;
        set<int> used;
        if (s.size() != n) {
            cout << "NO" << endl;
            continue;
        }
        bool w = true;
        for(int i = 0; i < n; i++) {
            // If havent seen current char, assign it a[i]. If a[i] is being used then bad. Set a[i] as used.
            // If have seen, ensure current is same as mapping
            int c = s[i];
            if (mapping.count(c)) {
                if (mapping[c] != a[i]) {
                    w = false;
                    break;
                }
            }
            else {
                mapping[c] = a[i];
                if (used.count(a[i])) {
                    w = false;
                    break;
                }
                else {
                    used.insert(a[i]);
                }
            }
        }
        if (w) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
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