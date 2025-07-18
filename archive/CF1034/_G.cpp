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

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else return gcd(b, a % b);
}

vector<vector<int>> divs(500001);

void TC() {
    // If k is not a divisor of m, then is good.
    // If k divides m, then we can move some numbers in some band of m.
    // For each, some divisor -> a list. If i > i + 1, then i + 1 must be raised by k. This is an
    // inversion. If there are geq m / k inversions, then this is bad.
    // we compute the inversinos as the swap happens.
    int n, m, q;
    cin >> n >> m >> q;
    auto mdivs = divs[m];
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    int dc = mdivs.size();

    vector<int> icnt(dc);
    vector<vector<int>> b(dc, vector<int>(n));

    // Initial insertion
    for(int d = 0; d < dc; d++) {
        int div = mdivs[d];
        for(int i = 0; i < n; i++) {
            // Set to i % div
            b[d][i] = a[i] % div;
        }
        for(int i = 1; i < n; i++) {
            if (b[d][i - 1] > b[d][i])
                icnt[d]++;
        }
        // cout << div << ' ' << icnt[d] << endl;
    }
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            // Remove inversions and re-insert.
            // cout << "UPD " << i << ' ' << x << endl;
            for(int d = 0; d < dc; d++) {
                // Remove
                int div = mdivs[d];
                // cout << "IC " << div << ' ' << icnt[d] << endl;
                // for(auto e : b[d]) cout << e << ' '; cout << endl;
                if (i != 0) {
                    if (b[d][i - 1] > b[d][i]) {
                        // cout << "UPD1" << endl;
                        icnt[d]--;
                    }
                }
                if (i != n - 1) {
                    if (b[d][i] > b[d][i + 1]) {
                        // cout << "UPD2" << endl;
                        icnt[d]--;
                    }
                }
                b[d][i] = x % div;
                if (i != 0) {
                    if (b[d][i - 1] > b[d][i]) {
                        // cout << "UPD3" << endl;
                        icnt[d]++;
                    }
                }
                if (i != n - 1) {
                    if (b[d][i] > b[d][i + 1]) {
                        // cout << "UPD4" << endl;
                        icnt[d]++;
                    }
                }
                // cout << "div " << div << ' ' << icnt[d] << endl;
                // for(auto e : b[d]) cout << e << ' '; cout << endl;
            }

        }
        else {
            int k; cin >> k;
            // Get status
            int g = gcd(m, k);
            if (g == 1) {
                cout << "YES" << '\n';
            }
            else {
                int ma = m / g;
                int dl = 0;
                for(int d = 0; d < dc; d++) {
                    if (g == mdivs[d]) {
                        dl = d;
                        break;
                    }
                }
                // cout << "QQQ" << g << ' ' << ma  << ' ' << icnt[g] << endl;
                if (icnt[dl] >= ma) {
                    cout << "NO" << '\n';
                }
                else {
                    cout << "YES" << '\n';
                }
            }
            
        }
    }
    /*
    4
    4
    
    4 5 2 2 4 1 0
    - 
    0 1 0 0 0 1 0
        X       X
    4 5 2 2 5 1 0

    0 1 0 1 0 1 0

    */
}

int main() {
    for(int i = 1; i <= 500000; i++) {
        for(int q = i; q <= 500000; q += i) {
            divs[q].push_back(i);
        }
    }
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
}