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
    // 1 5 2 3 4 7 8 15 ...
    int n; cin >> n;
    vector<int> used(n + 1);
    vector<int> ans; ans.reserve(n);
    if (n <= 6) {
        if (n == 5) {
            cout << 5 << '\n';
            cout << "2 1 3 4 5\n";
            return;
        }
        if (n == 6) {
            cout << 7 << '\n';
            cout << "1 2 4 6 5 3\n";
            return;
        }
    }
    if (n & 1) {
        // Doesnt end with an and.
        ll p = 1;
        bool o = true;
        while(p <= n) {
            ans.push_back(p);
            used[p] = 1;
            o = !o; // f
            p = p * 2 - 1;
            if (p <= n) {
                if (p == 1) {
                    ans.push_back(5);
                    used[5] = 1;
                }
                else {
                    ans.push_back(p);
                    used[p] = 1;
                }
                o = !o; // t
            }
            p += 1;
        }
        if (!o && !used[n]) {
            ans.push_back(n);
            used[n] = 1;
        }
        // p
    }
    else {
        // Doesnt end with an and.
        ll p = 1;
        bool o = true;
        while(p <= n) {
            ans.push_back(p);
            used[p] = 1;
            o = !o; // f
            p = p * 2 - 1;
            if (p <= n) {
                if (p == 1) {
                    ans.push_back(5);
                    used[5] = 1;
                }
                else {
                    ans.push_back(p);
                    used[p] = 1;
                }
                o = !o; // t
            }
            p += 1;
        }
        if (o) {
            used[ans.back()] = 0;
            ans.pop_back();
        }
        // p
    }
    int k = 0;
    bool p = 0;
    vector<int> fin;
    fin.reserve(n);
    for(int i = 1; i <= n; i++) {
        if (!used[i]) {
            fin.push_back(i);
        }
    }
    for(auto i : ans) {
        fin.push_back(i);
    }
    for(int i = 0; i < fin.size(); i++) {
        if (i & 1) {
            k |= fin[i];
        }
        else {
            k &= fin[i];
        }
    }
    cout << k << endl;
    for(auto e : fin) cout << e << ' ';
    cout << '\n';
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