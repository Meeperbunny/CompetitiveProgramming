#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    map<int, int> cnts;
    for(auto e : a) cnts[e]++;
    int l = k - 1;
    int la = -1;
    for(auto e : cnts) {
        l -= e.second;
        la = e.first;
        if (l <= 0) {
            break;
        }
    }
    vector<int> res;
    int tw = -l;
    for(auto e : a) {
        if (e <= la) res.push_back(e);
    }
    int L = 0, R = res.size() - 1;
    while(L < R) {
        if (res[L] == res[R]) {
            L++, R--;
        }
        else {
            if (res[L] == la) {
                L++;
                tw--;
            }
            else if (res[R] == la) {
                R--;
                tw--;
            }
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    if (tw >= 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
}