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
    ll maxnum = 4294967295;
    ll n; cin >> n;
    vector<ll> tom;
    ll currmult = 1;
    bool isoverflowing = false;
    int overflowind = -1;
    ll x = 0;
    for(int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (a == "add") {
            x += currmult;
            if (isoverflowing || x > maxnum) {
                cout << "OVERFLOW!!!" << endl;
                return;
            }
        }
        else if (a == "for") {
            ll times; cin >> times;
            if (!isoverflowing) {
                currmult *= times;
            }
            if (currmult > maxnum) {
                isoverflowing = true;
                overflowind = tom.size();
                currmult /= times;
            }
            tom.push_back(times);
        }
        else if (a == "end") {
            if (!isoverflowing) {
                currmult /= tom.back();
            }
            tom.pop_back();
            if (isoverflowing && overflowind == tom.size()) {
                isoverflowing = false;
            }
        }
        dbg(a, i, isoverflowing, currmult);
    }
    cout << x << endl;
}

int main() {
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}