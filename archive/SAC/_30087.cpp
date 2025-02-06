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
    map<string, string> lk;
    lk["Algorithm"] = "204";
    lk["DataAnalysis"] = "207";
    lk["ArtificialIntelligence"] = "302";
    lk["CyberSecurity"] = "B101";
    lk["Network"] = "303";
    lk["Startup"] = "501";
    lk["TestStrategy"] = "105";
    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        cout << lk[s] << endl;
    }
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