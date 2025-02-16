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
    int n, k;
    cin >> n >> k;
    if (n == 1 && k == 1) {
        cout << "YES" << endl;
        cout << 1 << '\n';
        return;
    }
    int pcount = 1;
    for(int i = 1; i <= min(10, n); i++) {
        pcount *= i;
    }
    if (pcount < k) {
        cout << "NO" << endl;
        return;
    }
    if (k == 1) {
        cout << "NO" << endl;
        return;
    }
    if (k % 2 == 0) {
        cout << "YES" << endl;
        vector<int> perm(n);
        iota(all(perm), 1);
        while(k) {
            k -= 2;
            for(int i = 0; i < n; i++) cout << perm[i] << ' '; cout << '\n';
            for(int i = 0; i < n; i++) cout << n + 1 - perm[i] << ' '; cout << '\n';
            next_permutation(all(perm));
        }
        return;
    }
    else if ((n + 1) % 2 == 0) {
        // Should be good. k is odd and >= 3.
        // do 3 first
        bool dt = false;


        if (pcount - 3 < k) {
            cout << "NO" << endl;
            return;
        }

        cout << "YES" << endl;
        vector<int> base(n);
        iota(all(base), 1);
        

        vector<int> p(n), pshift(n);
        int m = (n + 1) / 2;
        for(int i = 0; i < m; i++)
            p[i * 2] = m - i;
        for(int i = 0; i < m - 1; i++)
            p[i * 2 + 1] = n - i;
        for(int i = 0; i < n; i++) {
            pshift[i] = p[(i + 1) % n];
        }
        // Print the perm first
        for(int i = 0; i < n; i++) cout << p[i] << ' '; cout << '\n';
        for(int i = 0; i < n; i++) cout << pshift[i] << ' '; cout << '\n';
        for(int i = 0; i < n; i++) cout << base[i] << ' '; cout << '\n';
        k -= 3;
        
        vector<int> perm(n);
        iota(all(perm), 1);
        while(k) {
            // Check for equality here.
            next_permutation(all(perm));
            vector<int> rev(perm);
            for(int i = 0; i < n; i++) {
                rev[i] = n - rev[i] + 1;
            }
            if (perm == base || perm  == p || perm == pshift) {
                continue;
            }
            if (rev == base || rev  == p || rev == pshift) {
                continue;
            }
            k -= 2;
            for(int i = 0; i < n; i++) cout << perm[i] << ' '; cout << endl;
            for(int i = 0; i < n; i++) cout << n - perm[i] + 1 << ' '; cout << endl;
        }
        return;
    }
    else {
        cout << "NO" << endl;
        return;
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