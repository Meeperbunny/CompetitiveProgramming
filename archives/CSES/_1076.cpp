#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    multiset<int> mih;
    multiset<int, greater<int>> mah;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k - 1; i++) {
        mih.insert(a[i]);
    }
    for(int i = k - 1, l = 0; i < n; i++, l++) {
        // add a[i]
        if (a[i] <= *mah.begin()) mah.insert(a[i]);
        else mih.insert(a[i]);
        // rebalance: 3 3 : 4 3 : 4 4 : 5 3 -> 4 4 : 2 5 -> 3 4 -> 4 3 : 7 2 -> 6 3 -> 5 4
        while(mih.size() > mah.size()) {
            mah.insert(*mih.begin());
            mih.erase(mih.begin());
        }
        while(mah.size() > 1 + mih.size()) {
            mih.insert(*mah.begin());
            mah.erase(mah.begin());
        }
        // for(auto e : mah) cout << e << ' ';
        // cout << "   ";
        // for(auto e : mih) cout << e << ' ';
        // cout << endl;
        cout << *mah.begin() << ' ';
        // remove a[l]
        if (mah.count(a[l])) mah.erase(mah.find(a[l]));
        else if (mih.count(a[l])) mih.erase(mih.find(a[l]));
    }
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