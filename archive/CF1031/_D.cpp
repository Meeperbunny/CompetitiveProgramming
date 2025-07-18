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
    vector<int> a(n), b(n);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    multiset<int> inset(all(a)), outset;
    int cu = 0;
    int done = 0;
    for(int i = 0; i < n; i++) {
        int beat = b[i];
        // Simulate it.
        while(inset.size() && cu != n - i) {
            if (a[cu] > beat) {
                inset.erase(a[cu]);
                cu++;
            } else break;
        }
        if (inset.size() == 0) {
            cout << cu << endl;
            return;
        }
        // Check if all but one beat it.
        if (inset.size() >= 2) {
            if (*next(inset.begin()) > beat) {
                if (outset.size() && *outset.rbegin() > beat) {
                    cout << cu + inset.size() << endl;
                    return;
                }
            }
        }
        else if (inset.size() == 1) {
            if (outset.size() && *outset.rbegin() > beat) {
                cout << cu + inset.size() << endl;
                return;
            }
        }
        // Can't beat it tr y next
        inset.erase(inset.find(a[n - i - 1]));
        outset.insert(a[n - i - 1]);
    }
    cout << 0 << endl;
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