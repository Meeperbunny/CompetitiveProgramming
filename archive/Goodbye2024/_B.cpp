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
    vector<pair<int, int>> a(n);
    vector<int> coveredPre(n * 2 + 2, 0);
    vector<int> coveredCnt(n * 2 + 2, 0);
    for(int i = 0; i < n; i++) {
        pair<int, int> &e = a[i];
        cin >> e.first >> e.second;
        e.first++, e.second++;
        if (e.first == e.second) {
            coveredPre[e.first] = 1;
            coveredCnt[e.first] += 1;
        }
    }
    for(int i = 1; i < n * 2 + 2; ++i) {
        coveredPre[i] += coveredPre[i - 1]; 
    }
    string ans(n, '0');
    for(int i = 0; i < n; i++) {
        pair<int,int> &e = a[i];
        if (e.first == e.second) {
            if (coveredCnt.at(e.first) == 1) ans[i] = '1';
            else if (coveredCnt.at(e.first) >= 1) ans[i] = '0';
            else assert(false);
        }
        else if (e.first != e.second) {
            if (coveredPre.at(e.second) - coveredPre.at(e.first - 1) == e.second - e.first + 1) {
                ans[i] = '0';
            }
            else ans[i] = '1';
        }
    }
    cout << ans << endl;
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