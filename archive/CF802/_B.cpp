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
    if (s[0] == '9') {
        // 1 before
        int carry = 0;
        string ret = string(n, '0');
        for(int i = n - 1; i >= 0; i--) {
            int cn = s[i] - '0' + carry;
            carry = 0;
            if (cn == 1) {
                ret[i] = '0';
            }
            else if (cn == 0) {
                ret[i] = '1';
            }
            else {
                ret[i] = '0' + (11 - cn);
                carry = 1;
            }
        }
        cout << ret << endl;
    }
    else {
        string ret = string(n, '0');
        for(int i = 0; i < n; i++) {
            ret[i] = ('9' - s[i]) + '0';
        }
        cout << ret << endl;
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