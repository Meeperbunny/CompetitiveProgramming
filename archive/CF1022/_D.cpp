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
    int n, k;
    cin >> n >> k;
    vector<int> apat(k);
    vector<int> bpat(k);
    for(int i = 0; i < k; i++) {
        cout << "? " << i + 1 << endl;
        cin >> apat[i];
    }
    for(int i = 0; i < k; i++) {
        cout << "? " << n - i << endl;
        cin >> bpat[bpat.size() - i - 1];
    }
    int A = k - 1;
    int B = n - k;
    auto getAExpect = [&](int i) -> int {
        return apat[(i % k)];
    };
    auto getBExpect = [&](int i) -> int {
        int diff = n - i - 1;
        diff %= k;
        return bpat[k - diff - 1];
    };
    // Idea is pick one in the middle that is not ambig to check
    while(true) {
        if (A + 1 == B) {
            cout << "! " << (A + 1) << ' ' << (n - (A + 1)) << endl;
            return;
        }
        int mid = (A + B) / 2;
        // If all in middle are ambig, then is fucked
        bool done = false;
        int qp = -1;
        for(int i = 0; i < k; i++) {
            if (done)break;
            int p = mid - i;
            if (p == A) break;
            if (getAExpect(p) == getBExpect(p)) {
                continue;
            }
            else {
                qp = p;
                done=true;
                break;
            }
        }
        for(int i = 0; i < k; i++) {
            if (done)break;
            int p = mid + i;
            if (p == B) break;
            if (getAExpect(p) == getBExpect(p)) {
                continue;
            }
            else {
                qp = p;
                done=true;
                break;
            }
        }
        if (qp == -1) {cout << "! " << -1 << endl; return;}
        else {
            cout << "? " << qp + 1 << endl;
            int pp;
            cin >> pp;
            if (pp == getAExpect(qp)) {
                A = qp;
            }
            else {
                B = qp;
            }
        }
    }
}

int main() {
    // HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}