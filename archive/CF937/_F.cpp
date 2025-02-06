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
    int a, b, c;
    cin >> a >> b >> c;
    bool isv = true;
    if (a == 0 && b == 0) {
        if (c != 1) cout << -1 << endl;
        else cout << 0 << endl;
        return;
    }
    if (!a) {
        if (c != 1) cout << -1 << endl;
        else cout << b << endl;
    }
    else {
        int reqz = a + 1;
        if (c != reqz) {
            cout << -1 << endl;
        }
        else {
            map<int, int> hcnt;
            int natm = -1;
            hcnt[0] = 1;
            for(int i = 0; i < a; i++) {
                int mic = hcnt.begin()->first;
                hcnt[mic]--;
                natm = max(mic, natm);
                if (hcnt[mic] == 0) hcnt.erase(mic);
                hcnt[mic + 1] += 2;
            }
            // for(auto e : hcnt) cout << e.first << ' ' << e.second << "   ";
            // cout << endl;
            for(int i = 0; i < b; i++) {
                int mic = hcnt.begin()->first;
                natm = max(mic, natm);
                hcnt[mic]--;
                if (hcnt[mic] == 0) hcnt.erase(mic);
                hcnt[mic + 1] += 1;
            }
            // for(auto e : hcnt) cout << e.first << ' ' << e.second << "   ";
            // cout << endl;
            for(int i = 0; i < c; i++) {
                int mic = hcnt.begin()->first;
                natm = max(mic, natm);
                hcnt[mic]--;
                if (hcnt[mic] == 0) hcnt.erase(mic);
                hcnt[mic + 1] += 1;
            }
            // for(auto e : hcnt) cout << e.first << ' ' << e.second << "   ";
            // cout << endl;
            cout << natm << endl;
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