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

unordered_set<ll> squares;
void TC() {
    // 1 2 3 4 5 6 7 8 9
    // 1 3 5 7 9 11
    // 2 4 6 8 10
    // 28
    // 1 4 9 16 25 36 49 64 81 100
    // 38
    //  3 5 7  9 11 13 15 17 19
    // 2 1 3 5 7 9 11
    // 4 6 8 10
    // 2 1
    // 3 2 1
    // 3 2 1 6 5 4
    // 2 1 3 4
    // 2 1 3 4
    // Add all odds, all evens but 2, 1 at end
    // int n; cin >> n;
    for(int n = 1; n < 100; n++) {
        if (squares.count(ll(n) * ll(n + 1) / 2)) {
            cout << -1 << endl;
            continue;;
        }
        vector<int> seq;
        for(int i = 2; i <= n; i += 1) {
            seq.push_back(i);
        }

        ll t = 0;
        for(auto e : seq) {
            t += e;
            cout << e << ' ';
            if (squares.count(t)) {
                cout << "WRONG ON " << n << endl;
                assert(false);
            }
        } cout << endl;
    }
}

int main() {
    for(ll i = 1; i < 1000000; i++) {
        squares.insert(i * i);
    }
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}