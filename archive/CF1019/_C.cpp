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

struct MedianFinder {
    multiset<int> lset, rset;
    int _size = 0;
    void insert(int num) {
        lset.insert(num);
        int msz = (_size + 2) / 2;
        _size += 1;
        while(lset.size() > msz) {
            auto it = prev(lset.end());
            rset.insert(*it);
            lset.erase(it);
        }
        while(lset.size() && rset.size() && *lset.rbegin() > *rset.begin()) {
            auto it = prev(lset.end());
            int la = *it;
            int pr = *rset.begin();
            lset.erase(it);
            rset.erase(rset.begin());
            lset.insert(pr);
            rset.insert(la);
        }
    }
    int getMedian() {
        assert(lset.size());
        return *lset.rbegin();
    }
    void clear() {
        _size = 0;
        lset.clear();
        rset.clear();
    }
    int size() {
        return _size;
    }
};

void TC() {
    /*
    10 7 12 16 3 | 15 -> (10, 15)
    10 7 12 16 | 3 15 -> (12, 15)
    10 7 12 | 16 3 15 -> (10, 15)
    10 7 | 12 16 3 15 -> (10, 15)
    10 | 7 12 16 3 15 -> (10, 15)

    k = 7
    10 7 12 16 3 15 6 11
    // if there is a lpre and rpre with it is good
    // one is bigger, so should greedily absorb? Shortest one.
    // k = 8
    // 7 11 12 4 9 17 [B]
    
    3 7 9 18 2 2 2 | 15 -> (3, 15)

    6 8
    7 11 12 4 9 17
    IF you absorb sub with lower median, your median will still be less? Assume true
    At least 2 must be smaller


    2 leq K, one greater

    S M L
    M S L

    (7, 15)
    (7, 2)
    (9, 2)
    (7, 2)
    (7, 2)
    */

    // Assume L is smallest? Find the index where it is the smallest, 
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    vector<int> lmedian(n);
    MedianFinder L;
    MedianFinder R;
    for(int i = 0; i < n; i++) {
        L.insert(a[i]);
        lmedian[i] = L.getMedian();
    }
    vector<int> rmedian(n);
    for(int i = 0; i < n; i++) {
        R.insert(a[n - i - 1]);
        rmedian[n - i - 1] = R.getMedian();
    }
    // Check if lr is good
    int lind = -1;
    for(int i = 0; i < n; i++) {
        if (lmedian[i] <= k) {
            lind = i;
            break;
        }
    }
    int rind = -1;
    for(int i = n - 1; i >= 0; i--) {
        if (rmedian[i] <= k) {
            rind = i;
            break;
        }
    }
    // cout << "SEARCHING " << lind << ' ' << rind << endl;
    if (lind != -1 && rind != -1 && lind < rind) {
        cout << "YES" << endl;
        return;
    }
    if (lind == -1 && rind == -1) {
        cout << "NO" << endl;
        return;
    }
    if (lind != -1) {
        // Go from left side. Find just to the edge.
        MedianFinder LL, SL;
        for(int i = 0; i <= lind; i++) {
            LL.insert(a[i]);
            SL.insert(a[i]);
        }
        int nxt = lind + 1;
        while (nxt != n && a[nxt] > k) {
            SL.insert(a[nxt]);
            if (SL.getMedian() <= k) {
                LL.insert(a[nxt]);
                nxt += 1;
            } else break;
        }
        MedianFinder M;
        for(int q = nxt; q < n - 1; q++) {
            M.insert(a[q]);
            if (M.getMedian() <= k) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    if (rind != -1) {
        // Go from right side. Find just to the edge.
        MedianFinder LL, SL;
        for(int i = n - 1; i >= rind; i--) {
            LL.insert(a[i]);
            SL.insert(a[i]);
        }
        int nxt = rind - 1;
        while (nxt != -1 && a[nxt] > k) {
            SL.insert(a[nxt]);
            if (SL.getMedian() <= k) {
                LL.insert(a[nxt]);
                nxt -= 1;
            } else break;
        }
        MedianFinder M;
        for(int q = nxt; q >= 1; q--) {
            M.insert(a[q]);
            if (M.getMedian() <= k) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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