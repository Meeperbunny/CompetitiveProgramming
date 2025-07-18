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
        int f;
        if (n == 2) {
            cout << "! 1 2 2 1" << endl;
            cin >> f;
            return;
        }
        cout << "+ " << (2 * n + 2) / 2 << endl;
        cin >> f;
        if (f <= -1) {
            return;;
        }
        cout << "+ " << ((2 * n + 2) / 2) + 1 << endl;
        cin >> f;
        if (f <= -1) {
            return;;
        }
        vector<int> idx(2 * n, -1);
        int d;
        cout << "? " << 1 << ' ' << 2 << endl;
        cin >> d;
        if (d <= -1) {
            return;;
        }
        int LP = n;
        idx[n] = 1;
        idx[n + d] = 2;
        int lp = n;
        int rp = n + d;
        for(int i = 3; i <= n; i++) {
            int LD, RD;
            cout << "? " << 1 << ' ' << i << endl;
            cin >> LD;
            if (LD <= -1) {
                return; // 
            }
            cout << "? " << 2 << ' ' << i << endl;
            cin >> RD;
            if (RD <= -1) {
                return;
            }
            if (LD <= d && RD <= d) {
                int np = n + LD;
                idx[np] = i;
            }
            else if(LD >= RD) {
                int np = n + LD;
                idx[np] = i;
            }
            else {
                int np = n + d - RD;
                idx[np] = i;
                LP = min(LP, np);
            }
        }
        // o-o
        cout << "! ";
        for(int i = 0; i < 2; i++) {
            reverse(all(idx));
            vector<int> ans(n);
            int LL = 0;
            int RR = n - 1;
            int q = -1;
            for(int z = 0; z < 2 * n; z++) {
                if (idx[z] != -1) {
                    q = z;
                    break;
                }
            }
            while(LL <= RR) {
                if (LL == RR) {
                    ans[LL] = (idx[q++]);
                    break;
                }
                ans[LL] = (idx[q++]);
                ans[RR] = (idx[q++]);
                LL++, RR--;
            }
            vector<int> A(n);
            for(int q = 0; q < n; q++) {
                A[ans[q] - 1] = q + 1;
            }
            for(auto e : A) cout << e << ' ';
        }
        cout << endl;
        cin >> f;
        if (f <= -1) {
            return;
        }
    }
    // First 1 is 1, second is 2.
    // Take the ascending number, change it to position.

    // 1 4 2 5 3 6

    // 1 6 3 4 5 2
    // unshuffle
    // 1 3 5 2 4 6
    // Reverse 1 and 2.
    // 6 3 5 2 4 1

    // 1 2 3 4 5 6
    // o-o-o-o-o-o

    // od = 5
    // 2 3

    // 1 6 1 1 5 2 3 3 3 4 1 1 4 1
    // 2 3 3 3 4 1 1 4 1

    // 1 5 4 3 6 2
    // 1 6 4 3 2 5

    int main() {
        HEADER;
        int T = 1;
        cin >> T;
        for (int t = 0; t < T; t++) {
            TC();
        }
    }