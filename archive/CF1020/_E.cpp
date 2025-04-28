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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> inds(n);
    int i = 0;
    for(auto &e : a) {
        cin >> e;
        e--;
        inds[e] = i;
        i++;
    }
    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--, k--;
        // Check bounds
        int ind = inds[k];
        if (ind < l || ind > r) {
            cout << -1 << ' ';
            continue;
        }
        // Get comps requred
        int lmem = 0, umem = 0;
        int lcor = 0, ucor = 0;
        int tlo = 0, tup = 0;
        // Get member set (doesnt matter?)
        int L = l, R = r;
        while(L != R) {
            int mid = (L + R) / 2;
            // cout << "M " << mid << endl;
            if (mid == ind) {
                break;
            }
            else if (mid < ind) {
                if (a[mid] < k) tlo += 1;
                if (a[mid] > k) tup += 1;
                if (a[mid] < k) lcor += 1;
                lmem++;
                L = mid + 1;
            }
            else if (mid > ind) {
                if (a[mid] < k) tlo += 1;
                if (a[mid] > k) tup += 1;
                if (a[mid] > k) ucor += 1;
                umem++;
                R = mid - 1;
            }
        }
        // See if impossible
        int llim = k;
        int ulim = n - k - 1;
        if (lmem > llim || umem > ulim) {
            cout << -1 << ' ';
            continue;
        }
        // Cant do with 1 right
        // Have to select incorrect member set and not select correct member set?
        // Selection doesnt matter. Should find
        int neededLower = (lmem - lcor);
        int neededUpper = (umem - ucor);

        // dbg(q, neededLower, neededUpper);

        int swa = min(neededLower, neededUpper);
        neededLower -= swa;
        neededUpper -= swa;
        int tt = swa * 2;
        tt += 2 * (neededLower + neededUpper);


        cout << tt << ' ';

    }
    cout << endl;
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