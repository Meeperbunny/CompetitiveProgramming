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
    map<char, int> cnts;
    vector<char> inset;
    for(auto c : s) {
        cnts[c]++;
        inset.push_back(c);
    }
    int mv = 0;
    char mac = 0;
    for(auto e : cnts) {
        if (e.second > mv) {
            mv = e.second;
            mac = e.first;
        }
    }
    if (mv * 2 >= n) {
        // Interlace
        string res = "";
        for(auto e : inset) {
            if (e != mac) {
                res += e;
                res += mac;
                mv--;
            }
        }
        while(mv--) {
            res += mac;
        }
        cout << res << endl;
    }
    else {
        // Just place crossing
        sort(all(inset));
        string res = string(n, '0');
        for(int i = 0; i < (n + 1) / 2; i++) {
            res[i * 2] = inset[i];
        }
        for(int i = 0; i < (n) / 2; i++) {
            res[i * 2 + 1] = inset[(n + 1) / 2 + i];
        }
        cout << res << endl;
        
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