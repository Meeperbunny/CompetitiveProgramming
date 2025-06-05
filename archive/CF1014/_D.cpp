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
    string s; cin >> s;
    vector<int> cnts(1000, 0);
    for(auto &c : s) cnts[c]++;
    auto oc = [](char c) -> pair<char, char> {
        if (c == 'T') return {'L', 'I'};
        if (c == 'L') return {'T', 'I'};
        if (c == 'I') return {'L', 'T'};
    };
    auto oo = [](char a, char b) -> char {
        return char(int('L' + 'I' + 'T' - a - b));
    };
    if (count(all(s), s[0]) == n) {
        cout << -1 << endl;
        return;
    }
    vector<int> ops;
    for(int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            // Create two at current i so we have space.
            char A = s[i];
            char D = s[i + 1];

            // Create two.
            ops.push_back(i);
            ops.push_back(i);

            char C = oo(A, D);
            char B = oo(A, C);

            cnts[C]++;
            cnts[B]++;

            // A B C D
            // Can sub from any now.

            vector<pair<int, char>> cc;
            map<char, int> OO;
            for(auto c : {'L', 'I', 'T'}) {
                OO[c] = 0;
                cc.push_back({cnts[c], c});
            }
            sort(all(cc));

            char ma = cc.back().second;
            char mi = cc.front().second;

            int diff = cc.back().first - cc.front().first;

            OO[cc.back().second] = diff;
            OO[cc[1].second] = (cc[1].first + diff) - cc.back().first;

            for(int q = 0; q < OO[C]; q++) {
                ops.push_back(i + 2);
                ops.push_back(i + 2);
                cnts[B]++;
                cnts[A]++;
            }

            for(int q = 0; q < OO[B]; q++) {
                ops.push_back(i + 1);
                ops.push_back(i + 1);
                cnts[C]++;
                cnts[A]++;
            }

            for(int q = 0; q < OO[A]; q++) {
                ops.push_back(i);
                ops.push_back(i);
                cnts[B]++;
                cnts[C]++;
            }

            cout << ops.size() << '\n';
            for(auto e : ops) {
                cout << e + 1 << '\n';
            }
            return;
        }
    }
    cout << -1 << endl;
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