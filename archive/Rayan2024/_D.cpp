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
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    vector<pair<int, int>> moves;
    set<int> twos, ones, zeros;
    for(int i = 0; i < n; i++) {
        if (a[i] == 2) twos.insert(i);
        if (a[i] == 1) ones.insert(i);
        if (a[i] == 0) zeros.insert(i);
    }
    int tc = twos.size(), oc = ones.size(), zc = zeros.size();
    int inct = n - tc;
    int inco = n - (tc + oc);
    // IF twos are not in place, Move leftmost 2 to rightmost 1. (move 1 if not in pos.) then move ones right.
    if (twos.size()) {
        while (twos.size()) {
            int tp = *twos.begin();
            int op = *ones.rbegin();
            if (tp >= inct) break;
            if (op < inct) {
                op = *ones.begin();
                // swap leftmost one in to rmz first
                int zp = *zeros.rbegin();
                // swap them
                moves.push_back({zp, op});
                zeros.erase(zp);
                ones.erase(op);
                zeros.insert(op);
                ones.insert(zp);
                op = zp;
            }
            // swap them now.
            moves.push_back({tp, op});
            twos.erase(tp);
            ones.erase(op);
            twos.insert(op);
            ones.insert(tp);
        }
    }
    // while ones are less move them
    while(true) {
        int op = *ones.begin();
        if (op >= inco) break;
        // swap one in to rmz first
        int zp = *zeros.rbegin();
        // swap them
        moves.push_back({zp, op});
        zeros.erase(zp);
        ones.erase(op);
        zeros.insert(op);
        ones.insert(zp);
    }
    cout << moves.size() << endl;
    for(auto e : moves) {
        cout << e.first+1 << ' ' << e.second+1 << endl;
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