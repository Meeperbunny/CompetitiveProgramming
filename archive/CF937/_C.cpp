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
    string s; cin >> s;
    int h = stoi(s.substr(0, 2));
    string m = s.substr(3, 2);
    string en;
    if (h >= 12) en = "PM";
    else en = "AM";
    int b = ((h - 1) % 12) + 1;
    if (!b) b += 12;
    string nm = to_string(b);

    if (nm.size() == 1) nm = "0" + nm;
    cout << nm << ":" << m << ' ' << en << endl;
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