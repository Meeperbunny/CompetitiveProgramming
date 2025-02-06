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

vector<char> nar = {'n', 'a', 'r', 'e', 'k'};

pair<int, int>cont(int i, string &s) {
    int r = 0;
    for(auto & c : s) {
        if (c == nar[i]) {
            if (i == 4) {
                r += 10;
            }
            i = (i + 1) % 5;
        }
        for(int q = 0; q < 5; q++) {
            if (c == nar[q]) {
                r--;
            }
        }
    }
    // cout << s << ' ' << r << ' ' << i << endl;
    return {r, i};
}

void TC() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(auto &e : a) cin >> e;
    // For each string, given starting on C, cont to narek's and chatgpt's score.
    vector<int> best(5, -1e7);
    best[0] = 0;
    for(int i = 1; i <= n; i++) {
        string &s = a[i - 1];
        vector<int> nxt(5, -1e7);
        for(int q = 0; q < 5; q++) {
            auto res = cont(q, s);
            int end = res.second;
            nxt[end] = max(nxt[end], best[q] + res.first);
            // cout << "From " << i - 1 << " to " << i << ": " << res.first << endl;
        }
        for(int q = 0; q < 5; q++) {
            best[q] = max(best[q], nxt[q]);
        }
    }
    int bans = 0;
    for(auto e : best) {
        bans = max(bans, e);
    }
    cout << bans << endl;
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