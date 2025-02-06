#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    vector<string> s = {
        "",
        "1",
        "11",
        "121",
        "1212",
        "12312",
        "112312",
        "1123123",
        "12341234",
    };
    vector<vector<int>> modifier(s.size());
    for(int i = 0; i < s.size(); i++) {
        for(auto c : s[i]) {
            modifier[i].push_back(c - '1');
        }
    }
    int n; cin >> n;
    int q = 1;
    for(int i = 0; i < n; i += 8, q += 4) {
        int left = min(8, n - i);
        for(int j = 0; j < left; j++){
            cout << modifier[left][j] + q << ' ';
        } 
    } cout << endl;

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