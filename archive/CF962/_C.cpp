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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> pre(n + 1, vector<int>(26, 0));
    string a, b;
    cin >> a >> b;
    for(int i = 1; i <= n; i++) {
        for(int z = 0; z < 26; z++) {
            pre[i][z] = pre[i - 1][z];
        }
        pre[i][a[i - 1] - 'a']++;
        pre[i][b[i - 1] - 'a']--;
    }
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int td = 0;
        for(int z = 0; z < 26; z++) {
            td += abs(pre[r][z] - pre[l - 1][z]);
        }
        cout << int((td + 1) / 2) << endl; 
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