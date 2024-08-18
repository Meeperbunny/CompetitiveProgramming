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
    string s; cin >> s;
    int cnt = 0;
    stack<int> lopen;
    for(int i = 0; i < n; i++) {
        if (s[i] == '_') {
            if (cnt == 0) {
                cnt++;
                s[i] = '(';
            }
            else {
                s[i] = ')';
                cnt--;
                lopen.push(i);
            }
        }
        else if (s[i] == '(') {
            cnt++;
        }
        else if (s[i] == ')') {
            cnt--;
            while(cnt < 0) {
                int ind = lopen.top();
                lopen.pop();
                s[ind] = '(';
                cnt += 2;
            }
        }
    }
    stack<ll> sta;
    ll d = 0;
    for(ll i = 0; i < n; i++) {
        if (s[i] == '(') sta.push(i);
        else {
            d += i - sta.top();
            sta.pop();
        }
    }
    cout << d << endl;
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