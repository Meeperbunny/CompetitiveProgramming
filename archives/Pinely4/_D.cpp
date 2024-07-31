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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isp[262145];

void constadj(vector<vector<int>> &adj, int n) {
    for(int i = 0; i < n; i++) {
        for(int q = i; q < n; q++) {
            if (((i + 1) ^ (q + 1)) < 262145 && isp[(i + 1) ^ (q + 1)]) {
                adj[i].push_back(q);
                adj[q].push_back(i);
            }
        }
    }
}


void TC() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> color(n, -1);
    constadj(adj, n);
    for(auto e : adj[0]) cout << e << ' ';
    cout << endl;
}

int main() {
    HEADER;
    int T = 1;

    for(int i = 0; i < 262145; i++) {
        isp[i] = true;
    }
    isp[0] = isp[1] = false;
    for(int q = 2; q < 262145; q++) {
        if (isp[q]) {
            for(int i = q * 2; i < 262145; i += q) {
                isp[i] = false;
            }
        }
    }

    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}