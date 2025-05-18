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

// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/#
ll maxSubarraySum(vector<ll> &arr, ll L, ll R) {
    assert(L <= R);
    ll res = arr[L];
    ll maxEnding = arr[L];

    for (int i = L + 1; i <= R; i++) {
      
        // Find the maximum sum ending at index i by either extending 
        // the maximum sum subarray ending at index i - 1 or by
        // starting a new subarray from index i
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
        // Update res if maximum subarray sum ending at index i > res
        res = max(res, maxEnding);
    }
    return res;
}


void TC() {
    ll n, k;
    cin >> n >> k;
    string s; cin >> s;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    int l = 0;
    vector<ll> zinds;
    int col = 0;
    bool binked = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == '0' || (i == n - 1 && s[i] == '1')) {
            int r = i - 1;
            if ((i == n - 1 && s[i] == '1')) {
                r = n - 1;
            }
            else {
                zinds.push_back(i);
            }
            if (l <= r) {
                col++;
                // Get max sub sum of this group
                ll mss = maxSubarraySum(a, min(ll(l), n), min(ll(r), n));
                if (mss > k) {
                    cout << "No" << endl;
                    return;
                }
                if (mss == k) {
                    binked = true;
                }
            }
            l = i + 1;
        }
    }
    for(int i = 1; i < zinds.size(); i++) {
        a[zinds[i]] = -1000000000000ll;
    }
    if (zinds.size() == 0) {
        if (binked) {
            cout << "YES" << endl;
            for(auto e : a) cout << e << ' ';
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
        return;
    }
    int ii = zinds[0];
    ll lsum = 0, LL = 0;
    ll rsum = 0, RR = 0;
    for(int i = ii - 1; i >= 0; i--) {
        lsum += a[i];
        LL = max(lsum, LL);
    }
    for(int i = ii + 1; i < n; i++) {
        rsum += a[i];
        RR = max(rsum, RR);
    }
    a[ii] = k - (LL + RR);
    cout << "YES" << endl;
    for(auto e : a) cout << e << ' ';
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