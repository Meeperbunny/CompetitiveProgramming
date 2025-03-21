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
    int n;
    string s; cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = s[i] == '1';
    int zi = -1, zc = 0;
    for(int i = 0; i < n; i++) {
        if (a[i] == 0) {
            zc++, zi = i;
        }
    }
    vector<int> ops;
    if (zc == n || n < 3) assert(false);
    if (zc == 0) {
        zi = 0;
        ops.push_back(0);
        a[0] = 0;
    }
    map<int, int> zsizes, sizes;
    for(int j = 0; j < n; j++) {
        int i = (j + zi) % n;
        if (a[i] == 1) {
            // Get size
            int sz = 0;
            for(int q = 0; q < n; q++) {
                int ii = (i + q) % n;
                if (a[ii] == 1) sz++;
                else break;
            }
            sizes.insert({sz, j});
            j += sz - 1;
        }
        else if (a[i] == 0) {
            // Get size
            int sz = 0;
            for(int q = 0; q < n; q++) {
                int ii = (i + q) % n;
                if (a[ii] == 0) sz++;
                else break;
            }
            zsizes.insert({sz, j});
            j += sz - 1;
        }
    }
    if (sizes.size() == 1 && sizes.begin()->first == 2 && zsizes.size() == 1 && zsizes.begin()->first == 1) {
        cout << -1 << endl;
        return;
    } 
    else {
        bool f = false;
        for(auto e : zsizes) {
            if (!f && e.first != 1) {
                zi = (e.second + zi);
                f = true;
            }
        }
        for(auto e : sizes) {
            if (!f && e.first != 2) {
                zi = (e.second + zi);
                f = true;
            }
        }
    }
    for(int j = 0; j < n; j++) {
        int i = (j + zi) % n;
        if (a[i] == 1) {
            // Get size
            int sz = 0;
            for(int q = 0; q < n; q++) {
                int ii = (i + q) % n;
                if (a[ii] == 1) sz++;
                else break;
            }
            if (sz == 1) {
                ops.push_back(i);
                a[i] = 0;
            }
            else {
                if (sz == 2) {
                    // TUrn one before into a one and make sz = 3
                    ops.push_back((i + (n - 1)) % n);
                    a[(i + (n - 1)) % n] = 0;
                    j -= 1;
                    sz++;
                    i = (j + zi) % n;
                }
                for(int q = 0; q < sz - 3; q++) {
                    int ii = (i + q) % n;
                    ops.push_back((ii + 1) % n);
                    ops.push_back((ii) % n);
                    ops.push_back((ii + 1) % n);
                    a[ii] = 0;
                }
                int f = (i + sz - 3) % n;
                int s = (i + sz - 2) % n;
                int t = (i + sz - 1) % n;
                a[f] = 0;
                a[s] = 0;
                a[t] = 0;

                ops.push_back(s);
                ops.push_back(f);
                ops.push_back(t);
            }
            j += sz - 1;
        }
    }
    cout << ops.size() << endl;
    for(auto e : ops) cout << e << ' ';
    cout << endl;

}

int main() {
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}