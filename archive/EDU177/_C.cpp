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
    int n; cin >> n;
    vector<int> a(n);
    vector<int> d(n);
    for(auto &e : a) {cin >> e;e--;}
    for(auto &e : d) {cin >> e;e--;}
    vector<int> cycsize;
    vector<bool> check(n);
    vector<bool> cycused;
    vector<int> numtoid(n);

    int idd = 0;
    for(int i = 0; i < n; i++) {
        if (!check[i]) {
            int cs = 0;
            int q = i;
            while(!check[q]) {
                check[q] = true;
                cs++;
                numtoid[q] = idd;
                q = a[q];
            }
            cycused.push_back(0);
            cycsize.push_back(cs);
            idd++;

        }
    }
    // get cucles
    int t = 0;
    for(int i = 0; i < n; i++) {
        int D = d[i];
        int id = numtoid[D];
        if (!cycused[id]) {
            cycused[id] = 1;
            t += cycsize[id];
        }
        cout << t << ' ';
    } cout << '\n';
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