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
    string s; cin >> s;
    bool f= false;
    int off = 0;
    for(int i = 0; i < n; i++) {
        if (f) {
            if (s[i] == '?') {
                if (s[i - 1] == 'R') s[i] = 'B';
                else s[i]  = 'R';
            }
        }
        if (s[i] != '?') f = true;
    }
    f = false;
    for(int i = n - 1; i >= 0; i--) {
        if (f) {
            if (s[i] == '?') {
                if (s[i + 1] == 'R') s[i] = 'B';
                else s[i]  = 'R';
            }
        }
        if (s[i] != '?') f = true;
    }
    for(int i = n - 1; i >= 0; i--) {
        if (s[i] == '?') {
            if (i & 1) s[i] = 'B';
            else s[i]  = 'R';
        }
    }
    cout << s << endl;
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